#include "PreCompile.h"
#include "Change.h"

Change::Change() 
{
}

Change::~Change() 
{
}

void Change::Start()
{
	SetTexture("Change.png");
	SetLocalPosition(float4(0, 0, 0));
	Renderer->ScaleToTexture();

	Bank = CreateComponent<GameEngineTextureRenderer>();
	Bank->GetTransform().SetLocalPosition(float4(-1, -4,0));
	Bank->GetTransform().SetLocalScale(float4(362, 238));
	Bank->CreateFrameAnimationCutTexture("Bank", FrameAnimation_DESC("Bank.png", 0, 184, 0.08f, false));
	Bank->CreateFrameAnimationCutTexture("BankE", FrameAnimation_DESC("Bank.png", 0, 0, 0.08f, false));
	ChangeZPos(500);

}

void Change::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Change == false)
	{
		Bank->ChangeFrameAnimation("BankE");
		first = true;
		return;
	}
	if (GlobalContentsValue::Change)
	{
		ChangeZPos(-100);
		Bank->ChangeFrameAnimation("Bank");
		Bank->AnimationBindEnd("Bank", std::bind(&Change::BootEnd, this, std::placeholders::_1));
		if (first)
		{
			Sound = GameEngineSound::SoundPlayControl("Bank.wav");
			GlobalContentsValue::BgmStop = true;
			first = false;
		}
		if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
		{
			Sound.Stop();
			GlobalContentsValue::BgmStop = false;
			GlobalContentsValue::Change = false;
			GlobalContentsValue::Stream = true;
			ChangeZPos(500);
		}
	}

}

void Change::End()
{
}

void Change::BootEnd(const FrameAnimation_DESC& _Info)
{
	Sound.Stop();
	GlobalContentsValue::BgmStop = false;
	GlobalContentsValue::Change = false;
	GlobalContentsValue::Stream = true;
	ChangeZPos(500);
}