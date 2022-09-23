#include "PreCompile.h"
#include "Sojae.h"

Sojae::Sojae() 
{
}

Sojae::~Sojae() 
{
}

void Sojae::Start()
{
	if (GlobalContentsValue::TextContents == "Communication")
	{
		SetTexture("SoJae.png");
		SetLocalPosition(float4(0, 0, -200));
		SetLocalScale(float4(297, 195));
	}else
		if (GlobalContentsValue::TextContents == "Game")
		{
			SetTexture("SoJaeGame.png");
			SetLocalPosition(float4(0, 0, -200));
			SetLocalScale(float4(297, 195));

		}


	GameEngineSound::SoundPlayOneShot("day_start.wav");

	MainCol= CreateComponent<GameEngineCollision>();
	MainCol->GetTransform().SetLocalPosition(float4(-5, -70));
	MainCol->GetTransform().SetLocalScale(float4(100, 20, 500));
	MainCol->ChangeOrder(OBJECTORDER::Window);
	
	GameEngineTextureRenderer* Actor = CreateComponent<GameEngineTextureRenderer>();
	Actor->SetTexture("Color3.png");
	Actor->GetTransform().SetLocalScale(float4(718,1000));
	Actor->GetTransform().SetLocalPosition(float4(0, 0, -120));
	Actor->GetPixelData().MulColor = 0.4f;

	GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture("BackGroundColor.png");
	Renderer->GetTransform().SetLocalScale(float4(297, 2));
	Renderer->GetTransform().SetLocalPosition(float4(1, -97,-200));
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("BackGroundColor.png");
		Renderer->GetTransform().SetLocalScale(float4(2, 190));
		Renderer->GetTransform().SetLocalPosition(float4(147.8f, -2,-200));
	}
}

void Sojae::Update(float _DeltaTime)
{
	if (MouseCheck(MainCol)
	&&true == GameEngineInput::GetInst()->IsDown("MouseClick"))
	{
		Death();
	}
}

void Sojae::End()
{
}