#include "PreCompile.h"
#include "LineText.h"
#include <GameEngineBase/GameEngineRandom.h>

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

		EmoticonCollision1 = CreateComponent<GameEngineCollision>();
		EmoticonCollision1->GetTransform().SetLocalScale(float4(56, 56));
		EmoticonCollision1->GetTransform().SetLocalPosition(float4(290, -200, 0));
		EmoticonCollision1->ChangeOrder(OBJECTORDER::Emoticon);
		EmoticonCollision1->SetName("sorena.png");
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("love.png");
		Renderer->GetTransform().SetLocalPosition(float4(230, -200));
		Renderer->ScaleToTexture();
		Renderer->GetPixelData().MulColor.a = 0.6f;
		EmoticonRenderer.push_back(Renderer);

		EmoticonCollision2 = CreateComponent<GameEngineCollision>();
		EmoticonCollision2->GetTransform().SetLocalScale(float4(56, 56));
		EmoticonCollision2->GetTransform().SetLocalPosition(float4(230, -200));
		EmoticonCollision2->ChangeOrder(OBJECTORDER::Emoticon);
		EmoticonCollision2->SetName("love.png");
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("bujisyuuryou.png");
		Renderer->GetTransform().SetLocalPosition(float4(170, -200));
		Renderer->ScaleToTexture();
		Renderer->GetPixelData().MulColor.a = 0.6f;
		EmoticonRenderer.push_back(Renderer);

		EmoticonCollision3 = CreateComponent<GameEngineCollision>();
		EmoticonCollision3->GetTransform().SetLocalScale(float4(56, 56));
		EmoticonCollision3->GetTransform().SetLocalPosition(float4(170, -200));
		EmoticonCollision3->ChangeOrder(OBJECTORDER::Emoticon);
		EmoticonCollision3->SetName("bujisyuuryou.png");
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("gomen.png");
		Renderer->GetTransform().SetLocalPosition(float4(110, -200));
		Renderer->ScaleToTexture();
		Renderer->GetPixelData().MulColor.a = 0.6f;
		EmoticonRenderer.push_back(Renderer);

		EmoticonCollision4 = CreateComponent<GameEngineCollision>();
		EmoticonCollision4->GetTransform().SetLocalScale(float4(56, 56));
		EmoticonCollision4->GetTransform().SetLocalPosition(float4(110, -200));
		EmoticonCollision4->ChangeOrder(OBJECTORDER::Emoticon);
		EmoticonCollision4->SetName("gomen.png");
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("waritodoudemoii.png");
		Renderer->GetTransform().SetLocalPosition(float4(290, -144));
		Renderer->ScaleToTexture();
		Renderer->GetPixelData().MulColor.a = 0.6f;
		EmoticonRenderer.push_back(Renderer);

		EmoticonCollision5 = CreateComponent<GameEngineCollision>();
		EmoticonCollision5->GetTransform().SetLocalScale(float4(56, 56));
		EmoticonCollision5->GetTransform().SetLocalPosition(float4(290, -144));
		EmoticonCollision5->ChangeOrder(OBJECTORDER::Emoticon);
		EmoticonCollision5->SetName("waritodoudemoii.png");
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("pien.png");
		Renderer->GetTransform().SetLocalPosition(float4(230, -144));
		Renderer->ScaleToTexture();
		Renderer->GetPixelData().MulColor.a = 0.6f;
		EmoticonRenderer.push_back(Renderer);

		EmoticonCollision6 = CreateComponent<GameEngineCollision>();
		EmoticonCollision6->GetTransform().SetLocalScale(float4(56, 56));
		EmoticonCollision6->GetTransform().SetLocalPosition(float4(230, -144));
		EmoticonCollision6->ChangeOrder(OBJECTORDER::Emoticon);
		EmoticonCollision6->SetName("pien.png");
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("saikouka.png");
		Renderer->GetTransform().SetLocalPosition(float4(170, -144));
		Renderer->ScaleToTexture();
		Renderer->GetPixelData().MulColor.a = 0.6f;
		EmoticonRenderer.push_back(Renderer);

		EmoticonCollision7 = CreateComponent<GameEngineCollision>();
		EmoticonCollision7->GetTransform().SetLocalScale(float4(56, 56));
		EmoticonCollision7->GetTransform().SetLocalPosition(float4(170, -144));
		EmoticonCollision7->ChangeOrder(OBJECTORDER::Emoticon);
		EmoticonCollision7->SetName("saikouka.png");
	}
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("ok.png");
		Renderer->GetTransform().SetLocalPosition(float4(110, -144));
		Renderer->ScaleToTexture();
		Renderer->GetPixelData().MulColor.a = 0.6f;
		EmoticonRenderer.push_back(Renderer);

		EmoticonCollision8 = CreateComponent<GameEngineCollision>();
		EmoticonCollision8->GetTransform().SetLocalScale(float4(56, 56));
		EmoticonCollision8->GetTransform().SetLocalPosition(float4(110, -144));
		EmoticonCollision8->ChangeOrder(OBJECTORDER::Emoticon);
		EmoticonCollision8->SetName("ok.png");
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

void LineText::EmoticonCheck()
{
	if (GlobalContentsValue::CurEmoticonName != "")
	{
		MyTextureRenderer* TextRend = CreateComponent<MyTextureRenderer>();
		float SizeX = 0;
		float SizeY = 0;
		TextRend->SetTexture(GlobalContentsValue::CurEmoticonName);
		TextRend->ScaleToTexture();
		SizeX = TextRend->GetTransform().GetLocalScale().x;
		SizeY = TextRend->GetTransform().GetLocalScale().y;
		TextRend->GetTransform().SetLocalPosition(float4(337.5f - SizeX / 2, 75 - TextNum - SizeY / 2));
		Text.push_back(TextRend);
		MoveStart++;
		TextMove(SizeY + 3, 0);

		GlobalContentsValue::CurEmoticonName = "";
		int a = GameEngineRandom::MainRandom.RandomInt(0, 3);
	}
}
