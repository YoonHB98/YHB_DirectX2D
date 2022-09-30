#include "PreCompile.h"
#include "LineText.h"
#include <GameEngineBase/GameEngineRandom.h>
#include "ToolTipText.h"

void LineText::EmoticonON()
{
	GlobalContentsValue::EomticonStatus = 2;
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("sorena.png");
		Renderer->GetTransform().SetLocalPosition(float4(290, -200, -3));
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
		Renderer->GetTransform().SetLocalPosition(float4(230, -200, -3));
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
		Renderer->GetTransform().SetLocalPosition(float4(170, -200, -3));
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
		Renderer->GetTransform().SetLocalPosition(float4(110, -200, -3));
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
		Renderer->GetTransform().SetLocalPosition(float4(290, -144, -3));
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
		Renderer->GetTransform().SetLocalPosition(float4(230, -144, -3));
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
		Renderer->GetTransform().SetLocalPosition(float4(170, -144, -3));
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
		Renderer->GetTransform().SetLocalPosition(float4(110, -144, -3));
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
		Renderer->GetTransform().SetLocalPosition(float4(200.5, -172, -3));
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
		EmoticonTimeStart = true;
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
		ReactionName = GlobalContentsValue::CurEmoticonName;
		GlobalContentsValue::CurEmoticonName = "";	
	}
	int Re = Reaction();
	if (Re != -1)
	{
		if (ToolTipText::Count == 6)
		{
			ToolTipText::Count = ToolTipText::Count + 1;
		}
		CreateText("Reaction" + std::to_string(Re) + ".png");
	}
	if (EmoticonTimeStart)
	{
		EmoticonTime = EmoticonTime + GameEngineTime::GetDeltaTime();
	}
}

int LineText::Reaction()
{
	if (ChoiceNum < 3)
	{
		return -1;
	}
	int Num = -1;
	if (EmoticonTime > 1.0f)
	{
		if (ReactionName == "sorena.png")
		{
			Num = GameEngineRandom::MainRandom.RandomInt(62, 70);
		}else
		if (ReactionName == "love.png")
		{
			Num = GameEngineRandom::MainRandom.RandomInt(52, 61);
		}else
		if (ReactionName == "bujisyuuryou.png")
		{
			Num = GameEngineRandom::MainRandom.RandomInt(43, 51);
		}else
		if (ReactionName == "gomen.png")
		{
			Num = GameEngineRandom::MainRandom.RandomInt(35, 42);
		}else
		if (ReactionName == "waritodoudemoii.png")
		{
			Num = GameEngineRandom::MainRandom.RandomInt(27, 34);
		}
		else
		if (ReactionName == "pien.png")
		{
			Num = GameEngineRandom::MainRandom.RandomInt(19, 26);
		}
		else
		if (ReactionName == "saikouka.png")
		{
			Num = GameEngineRandom::MainRandom.RandomInt(10, 18);
		}
		else
		if (ReactionName == "ok.png")
		{
			Num = GameEngineRandom::MainRandom.RandomInt(1, 9);
		}
		ReactionName = "";
		EmoticonTimeStart = false;
		EmoticonTime = 0.0f;
		GameEngineSound().SoundPlayOneShot("jine_recieve.wav");
		return Num;
	}
	else
	{
		return -1;
	}
	

}


