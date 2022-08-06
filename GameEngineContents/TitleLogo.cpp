#include "PreCompile.h"
#include "TitleLogo.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>


TitleLogo::TitleLogo() 
{
}

TitleLogo::~TitleLogo() 
{
}

void TitleLogo::BootEnd(const FrameAnimation_DESC& _Info)
{
	Renderer->ChangeFrameAnimation("Windose");
	BgmPlayer3 = GameEngineSound::SoundPlayControl("Boot.wav", 0);
	CountStart = true;
}

void TitleLogo::Start() 
{
	// 960 540


	{	
	 Renderer = CreateComponent<GameEngineTextureRenderer>();
	 Renderer->GetTransform().SetLocalScale({ 960, 540, 0 });
		Renderer->SetTexture("Blank.png");


		Renderer->CreateFrameAnimationCutTexture("Boot", FrameAnimation_DESC("Boot.png", 0, 68, 0.1f,false));
		Renderer->CreateFrameAnimationCutTexture("Windose", FrameAnimation_DESC("Windose.png", 0, 20, 0.12f, false));
		Renderer->ChangeFrameAnimation("Boot");
		BgmPlayer1 =	GameEngineSound::SoundPlayControl("BIOS_piko.wav", 0);
		BgmPlayer2 =    GameEngineSound::SoundPlayControl("BIOS_HDD.wav", 0);
	}
	
}

void TitleLogo::Update(float _DeltaTime) 
{
	if (CountStart)
	{
		Time = Time + _DeltaTime;
	}

	Renderer->AnimationBindEnd("Boot", std::bind(&TitleLogo::BootEnd, this, std::placeholders::_1));
	if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
		|| Time > 7.8f)
	{
		BgmPlayer1.Stop();
		BgmPlayer2.Stop();
		BgmPlayer3.Stop();
		GEngine::ChangeLevel("Title");
	}
}

void TitleLogo::End() 
{
	int a = 0;
}