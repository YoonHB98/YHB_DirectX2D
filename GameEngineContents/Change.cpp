#include "PreCompile.h"
#include "Change.h"
#include "StreamInfo.h"
#include "CommentTalk.h"

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

	//{
	//	GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
	//	Renderer->SetTexture("Change2.png");
	//	Renderer->GetTransform().SetLocalPosition(float4(0, 0, 1));
	//	Renderer->ScaleToTexture();
	//}

	Bank = CreateComponent<GameEngineTextureRenderer>();
	Bank->GetTransform().SetLocalPosition(float4(-1, -4,0));
	Bank->GetTransform().SetLocalScale(float4(362, 238));
	Bank->CreateFrameAnimationCutTexture("Bank", FrameAnimation_DESC("Bank.png", 0, 184, 0.08f, false));
	Bank->CreateFrameAnimationCutTexture("BankE", FrameAnimation_DESC("Bank.png", 0, 0, 0.08f, false));
	ChangeZPos(500);
	Bank->ChangeFrameAnimation("BankE");
	first = true;
	if (GlobalContentsValue::Contents != "Tutorial")
	{
		GlobalContentsValue::CommentContents = GlobalContentsValue::Contents;
	}

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
		if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
			&&first == false
			&&GlobalContentsValue::BadEnd != true)
		{
			Sound.Stop();
			GlobalContentsValue::ChangeTime = 0.0f;
			GlobalContentsValue::BgmStop = false;
			GlobalContentsValue::Change = false;
			GlobalContentsValue::Stream = true;
			GetLevel()->CreateActor<StreamInfo>();
			ChangeZPos(500);
			Death();
		}
		ChangeZPos(-150);
		Bank->ChangeFrameAnimation("Bank");
		Bank->AnimationBindEnd("Bank", std::bind(&Change::BootEnd, this, std::placeholders::_1));
		if (first)
		{
			Sound = GameEngineSound::SoundPlayControl("Bank.wav");
			GlobalContentsValue::BgmStop = true;
			first = false;
		}
	}

}

void Change::End()
{
}

void Change::BootEnd(const FrameAnimation_DESC& _Info)
{
	GlobalContentsValue::ChangeTime = 0.0f;
	Sound.Stop();
	GlobalContentsValue::BgmStop = false;
	GlobalContentsValue::Change = false;
	GlobalContentsValue::Stream = true;
	GetLevel()->CreateActor<StreamInfo>();
	if (GlobalContentsValue::BadEnd)
	{
		GlobalContentsValue::BadEndLoadEnd = true;
	}
	ChangeZPos(500);
	Death();
}