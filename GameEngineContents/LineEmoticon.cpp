#include "PreCompile.h"
#include "LineText.h"

void LineText::EmoticonON()
{
	GlobalContentsValue::EomticonStatus = 2;
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("sorena.png");
		Renderer->GetTransform().SetLocalPosition(float4(290, -200));
		Renderer->ScaleToTexture();
		Renderer->GetPixelData().MulColor.a = 0.6f;
		EmoticonRenderer.push_back(Renderer);
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("love.png");
		Renderer->GetTransform().SetLocalPosition(float4(230, -200));
		Renderer->ScaleToTexture();
		Renderer->GetPixelData().MulColor.a = 0.6f;
		EmoticonRenderer.push_back(Renderer);
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("bujisyuuryou.png");
		Renderer->GetTransform().SetLocalPosition(float4(170, -200));
		Renderer->ScaleToTexture();
		Renderer->GetPixelData().MulColor.a = 0.6f;
		EmoticonRenderer.push_back(Renderer);
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("gomen.png");
		Renderer->GetTransform().SetLocalPosition(float4(110, -200));
		Renderer->ScaleToTexture();
		Renderer->GetPixelData().MulColor.a = 0.6f;
		EmoticonRenderer.push_back(Renderer);
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("waritodoudemoii.png");
		Renderer->GetTransform().SetLocalPosition(float4(290, -144));
		Renderer->ScaleToTexture();
		Renderer->GetPixelData().MulColor.a = 0.6f;
		EmoticonRenderer.push_back(Renderer);
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("pien.png");
		Renderer->GetTransform().SetLocalPosition(float4(230, -144));
		Renderer->ScaleToTexture();
		Renderer->GetPixelData().MulColor.a = 0.6f;
		EmoticonRenderer.push_back(Renderer);
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("saikouka.png");
		Renderer->GetTransform().SetLocalPosition(float4(170, -144));
		Renderer->ScaleToTexture();
		Renderer->GetPixelData().MulColor.a = 0.6f;
		EmoticonRenderer.push_back(Renderer);
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("ok.png");
		Renderer->GetTransform().SetLocalPosition(float4(110, -144));
		Renderer->ScaleToTexture();
		Renderer->GetPixelData().MulColor.a = 0.6f;
		EmoticonRenderer.push_back(Renderer);
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("LineRect.png");
		Renderer->GetTransform().SetLocalPosition(float4(200.5, -172));
		Renderer->GetTransform().SetLocalScale(float4(301,120));
		Renderer->GetPixelData().MulColor.a = 0.15f;
		EmoticonRenderer.push_back(Renderer);
	}

}

void LineText::EmoticonOnOff()
{
	std::vector<GameEngineTextureRenderer*>::iterator Startiter = EmoticonRenderer.begin();
	std::vector<GameEngineTextureRenderer*>::iterator Enditer = EmoticonRenderer.end();
	switch (GlobalContentsValue::EomticonStatus)
	{
	case 0:
		for (; Startiter != Enditer; ++Startiter)
		{
			(*Startiter)->GetPixelData().MulColor.a = 0.0f;
		}
		break;
	case 1:
		for (; Startiter != Enditer - 1; ++Startiter)
		{
			(*Startiter)->GetPixelData().MulColor.a = 0.0f;
		}
		break;
	case 2:
		for (; Startiter != Enditer - 1; ++Startiter)
		{
			(*Startiter)->GetPixelData().MulColor.a = 0.6f;
		}
		(*Startiter)->GetPixelData().MulColor.a = 0.15f;
		break;

	default:
		break;
	}
}