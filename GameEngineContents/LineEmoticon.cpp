#include "PreCompile.h"
#include "LineText.h"

void LineText::EmoticonON()
{
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("sorena.png");
		Renderer->GetTransform().SetLocalPosition(float4(290, -200));
		Renderer->ScaleToTexture();
		Renderer->GetColorData().MulColor.a = 0.6f;
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("love.png");
		Renderer->GetTransform().SetLocalPosition(float4(230, -200));
		Renderer->ScaleToTexture();
		Renderer->GetColorData().MulColor.a = 0.6f;
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("bujisyuuryou.png");
		Renderer->GetTransform().SetLocalPosition(float4(170, -200));
		Renderer->ScaleToTexture();
		Renderer->GetColorData().MulColor.a = 0.6f;
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("gomen.png");
		Renderer->GetTransform().SetLocalPosition(float4(110, -200));
		Renderer->ScaleToTexture();
		Renderer->GetColorData().MulColor.a = 0.6f;
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("waritodoudemoii.png");
		Renderer->GetTransform().SetLocalPosition(float4(290, -144));
		Renderer->ScaleToTexture();
		Renderer->GetColorData().MulColor.a = 0.6f;
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("pien.png");
		Renderer->GetTransform().SetLocalPosition(float4(230, -144));
		Renderer->ScaleToTexture();
		Renderer->GetColorData().MulColor.a = 0.6f;
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("saikouka.png");
		Renderer->GetTransform().SetLocalPosition(float4(170, -144));
		Renderer->ScaleToTexture();
		Renderer->GetColorData().MulColor.a = 0.6f;
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("ok.png");
		Renderer->GetTransform().SetLocalPosition(float4(110, -144));
		Renderer->ScaleToTexture();
		Renderer->GetColorData().MulColor.a = 0.6f;
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("ok.png");
		Renderer->GetTransform().SetLocalPosition(float4(110, -144));
		Renderer->ScaleToTexture();
		Renderer->GetColorData().MulColor.a = 0.6f;
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("LineRect.png");
		Renderer->GetTransform().SetLocalPosition(float4(200.5, -172));
		Renderer->GetTransform().SetLocalScale(float4(301,120));
		Renderer->GetColorData().MulColor.a = 0.15f;
	}

}