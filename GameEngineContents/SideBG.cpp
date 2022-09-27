#include "PreCompile.h"
#include "SideBG.h"

SideBG::SideBG()
{
}

SideBG::~SideBG()
{
}

void SideBG::ChangeState(DayState _State)
{
	if (CurState_ != _State)
	{
		CurState_ = _State;
		switch (_State)
		{
		case DayState::night :
			StartNight();
			break;
		case DayState::noon:
			StartNoon();
			break;
		case DayState::evening:
			StartEvening();
		case DayState::Max:
			break;
		default:
			break;
		}
	}
}

void SideBG::StartNight()
{
	RightBG->ChangeFrameAnimation("Night");
	RightBG->GetTransform().PixLocalNegativeX();
	LeftBG->ChangeFrameAnimation("Night");
}

void SideBG::StartNoon()
{
	RightBG->ChangeFrameAnimation("Noon");
	RightBG->GetTransform().PixLocalNegativeX();
	LeftBG->ChangeFrameAnimation("Noon");
}

void SideBG::StartEvening()
{
	RightBG->ChangeFrameAnimation("Evening");
	RightBG->GetTransform().PixLocalNegativeX();
	LeftBG->ChangeFrameAnimation("Evening");
}

void SideBG::Start()
{
	{
		RightBG = CreateComponent<GameEngineTextureRenderer>();
		RightBG->GetTransform().SetLocalPosition(float4(419.5, 0,400));
		RightBG->CreateFrameAnimationCutTexture("Night", FrameAnimation_DESC("bg_side_bar_night.png", 0, 77, 0.05f, false));
		RightBG->CreateFrameAnimationCutTexture("Evening", FrameAnimation_DESC("bg_side_bar_evening.png", 0, 74, 0.05f, false));
		RightBG->CreateFrameAnimationCutTexture("Noon", FrameAnimation_DESC("bg_side_bar_noon.png", 0, 0, 0.05f, false));
		RightBG->GetTransform().SetLocalScale(float4(121,540));
		RightBG->GetTransform().PixLocalNegativeX();
		RightBG->ChangeFrameAnimation("Night");
	}
	{
		LeftBG = CreateComponent<GameEngineTextureRenderer>();
		LeftBG->SetTexture("bg_side_bar_night.png");
		LeftBG->CreateFrameAnimationCutTexture("Night", FrameAnimation_DESC("bg_side_bar_night.png", 0, 77, 0.05f, false));
		LeftBG->CreateFrameAnimationCutTexture("Evening", FrameAnimation_DESC("bg_side_bar_evening.png", 0, 74, 0.05f, false));
		LeftBG->CreateFrameAnimationCutTexture("Noon", FrameAnimation_DESC("bg_side_bar_noon.png", 0, 0, 0.05f, false));
		LeftBG->GetTransform().SetLocalPosition(float4(-419.5, 0,400));
		LeftBG->GetTransform().SetLocalScale(float4(121, 540));
		LeftBG->ChangeFrameAnimation("Night");
	}
}

void SideBG::Update(float _DeltaTime)
{
	DayState GlobalValue = (DayState)GlobalContentsValue::DayTime;
	if (GlobalContentsValue::DayTimeChange || GlobalContentsValue::Contents == "Tutorial")
	{
		GlobalContentsValue::DayTimeChange = false;
	}
	ChangeState(GlobalValue);
}

void SideBG::End()
{
}
