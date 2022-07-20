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

		switch (_State)
		{
		case night:
			StartNight();
			break;
		case noon:
			StartNoon();
			break;
		case evening:
			StartEvening();
		case Max:
			break;
		default:
			break;
		}
	}

	CurState_ = _State;
}

void SideBG::StartNight()
{
	RightBG->SetTexture("bg_side_bar_night.png");
	RightBG->GetTransform().PixLocalNegativeX();
	LeftBG->SetTexture("bg_side_bar_night.png");
}

void SideBG::StartNoon()
{
	RightBG->SetTexture("bg_side_bar_noon.png");
	RightBG->GetTransform().PixLocalNegativeX();
	LeftBG->SetTexture("bg_side_bar_noon.png");
}

void SideBG::StartEvening()
{
	RightBG->SetTexture("bg_side_bar_evening.png");
	RightBG->GetTransform().PixLocalNegativeX();
	LeftBG->SetTexture("bg_side_bar_evening.png");
}

void SideBG::Start()
{
	{
		RightBG = CreateComponent<GameEngineTextureRenderer>();
		RightBG->SetTexture("bg_side_bar_night.png");
		RightBG->GetTransform().SetLocalPosition(float4(419.5, 0));
		RightBG->ScaleToTexture();
		RightBG->GetTransform().PixLocalNegativeX();
	}
	{
		LeftBG = CreateComponent<GameEngineTextureRenderer>();
		LeftBG->SetTexture("bg_side_bar_night.png");
		LeftBG->GetTransform().SetLocalPosition(float4(-419.5, 0));
		LeftBG->ScaleToTexture();
	}
}

void SideBG::Update(float _DeltaTime)
{
	ChangeState(noon);
}

void SideBG::End()
{
}
