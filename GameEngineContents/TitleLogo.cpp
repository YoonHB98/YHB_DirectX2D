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
}

void TitleLogo::Start() 
{
	// 960 540


	{	
	 Renderer = CreateComponent<GameEngineTextureRenderer>();
	 Renderer->GetTransform().SetLocalScale({ 960, 540, 0 });
		Renderer->SetTexture("Blank.png");


		Renderer->CreateFrameAnimation("Boot", FrameAnimation_DESC("Boot.png", 0, 68, 0.1f,false));
		Renderer->CreateFrameAnimation("Windose", FrameAnimation_DESC("Windose.png", 0, 20, 0.12f, false));
		Renderer->ChangeFrameAnimation("Boot");
		BgmPlayer1 =	GameEngineSound::SoundPlayControl("BIOS_piko.wav", 0);
		BgmPlayer2 =    GameEngineSound::SoundPlayControl("BIOS_HDD.wav", 0);
	}

}

void TitleLogo::Update(float _DeltaTime) 
{
	Renderer->AnimationBindEnd("Boot", &TitleLogo::BootEnd,this	);
	if (true == GameEngineInput::GetInst()->IsDown("LevelChange"))
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