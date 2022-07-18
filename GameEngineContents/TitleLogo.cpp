#include "PreCompile.h"
#include "TitleLogo.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

TitleLogo::TitleLogo() 
{
}

TitleLogo::~TitleLogo() 
{
}


void BootEnd(const FrameAnimation_DESC& _Info)
{
	GlobalContentsValue::boot = true;
}

void TitleLogo::Start() 
{
	// 1280 720


	{	
	 Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("boot.png", 0);
		Renderer->GetTransform().SetLocalScale({ 960, 540, 0 });

		Renderer->CreateFrameAnimation("Boot", FrameAnimation_DESC("boot.png", 0, 68, 0.1f,false));
		Renderer->CreateFrameAnimation("Windose", FrameAnimation_DESC("Windose.png", 0, 20, 0.1f, false));
		Renderer->ChangeFrameAnimation("Boot");
		GameEngineSound::SoundPlayOneShot("BIOS_piko.wav", 0);
		GameEngineSound::SoundPlayOneShot("BIOS_HDD.wav", 0);
	}

}

void TitleLogo::Update(float _DeltaTime) 
{

	Renderer->AnimationBindEnd("Boot", BootEnd);
	if (GlobalContentsValue::boot == true)
	{
		GlobalContentsValue::boot = false;
		Renderer->ChangeFrameAnimation("Windose");
		GameEngineSound::SoundPlayOneShot("Boot.wav", 0);
	}
}

void TitleLogo::End() 
{
	int a = 0;
}