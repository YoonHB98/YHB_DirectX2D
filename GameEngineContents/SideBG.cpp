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
		RightBG = CreateComponent<CommentTextureRenderer>();
		RightBG->SetTexture("bg_side_bar_night.png");
		RightBG->GetTransform().SetLocalPosition(float4(419.5, 0,400));
		RightBG->ScaleToTexture();
		RightBG->GetTransform().PixLocalNegativeX();
	}
	{
		LeftBG = CreateComponent<CommentTextureRenderer>();
		LeftBG->SetTexture("bg_side_bar_night.png");
		LeftBG->GetTransform().SetLocalPosition(float4(-419.5, 0,400));
		LeftBG->ScaleToTexture();
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
	float A = LeftBG->Color.SizeY;
	if (LeftBG->Color.SizeY < 1.4f
		&& AAAA == false)
	{
		LeftBG->Color.SizeY  = LeftBG->Color.SizeY +1.0f * _DeltaTime;
	}
	else
	{
		AAAA = true;
	}

	if (AAAA && LeftBG->Color.SizeY > 0.0f)
	{
		LeftBG->Color.SizeY = LeftBG->Color.SizeY - 0.06f * _DeltaTime;
	}
	else
		if (AAAA && LeftBG->Color.SizeY < 0.0f)
		{
			LeftBG->Color.SizeY = 0.0f;
		}
	{

	}

			//RightBG->Color.SizeY - 1.0f * _DeltaTime;


}

void SideBG::End()
{
}
