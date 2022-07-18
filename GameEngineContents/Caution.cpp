#include "PreCompile.h"
#include "Caution.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

Caution::Caution()
{
}

Caution::~Caution()
{
}



void Caution::Start()
{
	// 1280 720


	{

	}

}

void Caution::Update(float _DeltaTime)
{
			Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 960, 540, 0 });
		Renderer->SetTexture("SetUp.png");
		if (GlobalContentsValue::Title == false)
		{

			GameEngineSound::SoundPlayOneShot("OP_PV.wav", 0);
			GlobalContentsValue::Title = true;
		}

}

void Caution::End()
{
	int a = 0;
}