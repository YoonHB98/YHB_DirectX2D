#include "PreCompile.h"
#include "SideBG.h"

SideBG::SideBG()
{
}

SideBG::~SideBG()
{
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
}

void SideBG::End()
{
}
