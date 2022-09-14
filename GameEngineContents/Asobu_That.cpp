#include "PreCompile.h"
#include "Asobu_That.h"

Asobu_That::Asobu_That()
{
}

Asobu_That::~Asobu_That()
{
}

void Asobu_That::Start()
{
	BG = CreateComponent<GameEngineTextureRenderer>();
	BG->SetTexture("Color.png");
	BG->GetTransform().SetLocalScale(float4(298, 414));
	BG->GetTransform().SetLocalPosition(float4(195, -15, -3));
	BG->GetPixelData().MulColor.a = 0.6f;

	GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture("BackGroundColor.png");
	Renderer->GetTransform().SetLocalScale(float4(298, 2));
	Renderer->GetTransform().SetLocalPosition(float4(197, -223, -3));
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("BackGroundColor.png");
		Renderer->GetTransform().SetLocalScale(float4(2, 400));
		Renderer->GetTransform().SetLocalPosition(float4(345, -22, -3));
	}
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("Triangle2.png");
		Renderer->GetTransform().SetLocalScale(float4(15, 17));
		Renderer->GetTransform().SetLocalPosition(float4(188, -175, -3));
	}
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("Triangle2.png");
		Renderer->GetTransform().SetLocalScale(float4(15, 17));
		Renderer->GetTransform().SetLocalPosition(float4(209.5, -175, -3));
	}

	Font = CreateComponent<Myfont>();
	Font->SetLeftAndRightSort(LeftAndRightSort::LEFT);
	Font->TextDraw("어른의 놀이", "galmuri11", float4(545-380, 112), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 17);
	Font->SetRenderingOrder(500);
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("icon_status_stress.png");
		Renderer->GetTransform().SetLocalScale(float4(24, 20));
		Renderer->GetTransform().SetLocalPosition(float4(80, 80, -3));
	}
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("icon_status_love.png");
		Renderer->GetTransform().SetLocalScale(float4(24, 20));
		Renderer->GetTransform().SetLocalPosition(float4(80, 55, -3));
	}
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("icon_status_yami.png");
		Renderer->GetTransform().SetLocalScale(float4(24, 20));
		Renderer->GetTransform().SetLocalPosition(float4(80, 30, -3));
	}
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("Arrow.png");
		Renderer->GetTransform().SetLocalScale(float4(15, 12));
		Renderer->GetTransform().SetLocalPosition(float4(226.5f, 76.5f, -5));
	}
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("Arrow.png");
		Renderer->GetTransform().SetLocalScale(float4(15, 12));
		Renderer->GetTransform().SetLocalPosition(float4(226.5f, 51.5f, -5));
	}
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("Arrow.png");
		Renderer->GetTransform().SetLocalScale(float4(15, 12));
		Renderer->GetTransform().SetLocalPosition(float4(226.5f, 26.5f, -5));
	}
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("Arrow.png");
		Renderer->GetTransform().SetLocalScale(float4(15, 12));
		Renderer->GetTransform().SetLocalPosition(float4(205.5f, -27.0f, -5));
	}
	{
		for (float X = 195.5f; X < 239.5f; X = X + 7.5f)
		{
			CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
			Renderer->SetTexture("DownArrow.png");
			Renderer->GetTransform().SetLocalScale(float4(7, 8));
			Renderer->GetTransform().SetLocalPosition(float4(X, 86.0f, -5));
			Renderer->Color.PosX = 215.0f / 255.0f;
			Renderer->Color.PosY = 90.0f / 255.0f;
			Renderer->Color.SizeX = 90.0f / 255.0f;
		}
	}
	{
		for (float X = 195.5f; X < 224.5f; X = X + 7.5f)
		{
			CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
			Renderer->SetTexture("DownArrow.png");
			Renderer->GetTransform().SetLocalScale(float4(7, 8));
			Renderer->GetTransform().SetLocalPosition(float4(X, 36.0f, -5));
			Renderer->Color.PosX = 215.0f / 255.0f;
			Renderer->Color.PosY = 90.0f / 255.0f;
			Renderer->Color.SizeX = 90.0f / 255.0f;
		}
	}
	{
		for (float X = 195.5f; X < 239.0f; X = X + 7.5f)
		{
			CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
			Renderer->SetTexture("UpArrow.png");
			Renderer->GetTransform().SetLocalScale(float4(7, 8));
			Renderer->GetTransform().SetLocalPosition(float4(X, 61.5f, -5));
		}
	}
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("UpArrow.png");
		Renderer->GetTransform().SetLocalScale(float4(7, 8));
		Renderer->GetTransform().SetLocalPosition(float4(168, -15.2f, -5));
		Renderer->Color.PosX = 215.0f / 255.0f;
		Renderer->Color.PosY = 90.0f / 255.0f;
		Renderer->Color.SizeX = 90.0f / 255.0f;
	}

	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("그거 하자...", "galmuri11", float4(548-380, 150), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 10);
		Script->SetRenderingOrder(500);
	}

	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("스트레스", "galmuri11", float4(572-380, 180), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(500);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw(std::to_string(GlobalContentsValue::Stress), "DinkieBitmap 7px", float4(675-380, 185), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(500);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw(std::to_string(GlobalContentsValue::Mental), "DinkieBitmap 7px", float4(675 - 380, 235), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(500);
	}
	{
		int Temp = GlobalContentsValue::Stress;
		Temp = Temp - 12;
		if (Temp < 0)
		{
			Temp = 0;
		}
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw(std::to_string(Temp), "DinkieBitmap 7px", float4(720-380, 175), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 30);
		Script->SetRenderingOrder(500);
	}
	{
		int Temp = GlobalContentsValue::Mental;
		Temp = Temp - 4;
		if (Temp < 0)
		{
			Temp = 0;
		}
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw(std::to_string(Temp), "DinkieBitmap 7px", float4(720 - 380, 225), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 30);
		Script->SetRenderingOrder(500);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("호감도", "galmuri11", float4(572-380, 205), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(500);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("멘탈", "galmuri11", float4(572 - 380, 230), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(500);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw(std::to_string(GlobalContentsValue::Affection), "DinkieBitmap 7px", float4(675-380, 210), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(500);
	}
	{
		int Temp = GlobalContentsValue::Affection;
		Temp = Temp + 15;
		if (Temp > 100)
		{
			Temp = 100;
		}
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw(std::to_string(Temp), "DinkieBitmap 7px", float4(720-380, 202), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 30);
		Script->SetRenderingOrder(500);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("방송  보너스", "galmuri11", float4(548-380, 265), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 8);
		Script->SetRenderingOrder(500);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("경험", "galmuri11", float4(548-380, 280), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(500);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("0", "DinkieBitmap 7px", float4(645-380, 287), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(500);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("1", "DinkieBitmap 7px", float4(700 - 380, 280), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 30);
		Script->SetRenderingOrder(500);
	}
	{GlobalContentsValue::DayTime = 1;
	std::string DayTime = CheckDayTime(GlobalContentsValue::DayTime);
	Myfont* Script = CreateComponent<Myfont>();
	Script->SetLeftAndRightSort(LeftAndRightSort::CENTER);
	Script->TextDraw(DayTime, "galmuri11", float4(558 - 380, 435), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
	Script->SetRenderingOrder(500);
	}
	{
		std::string DayTime = CheckDayTime(GlobalContentsValue::DayTime + 2);
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::CENTER);
		Script->TextDraw(DayTime, "galmuri11", float4(790 - 380, 435), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(500);
	}
	{
		std::string DayTime = CheckDayTime(GlobalContentsValue::DayTime + 2);
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::CENTER);
		Script->TextDraw(DayTime + "이  될  거야", "galmuri11", float4(674 - 380, 455), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 8);
		Script->SetRenderingOrder(500);
	}
	GetTransform().SetLocalMove(float4(-380,0,0));

	ChangeZPos(-400);
}

void Asobu_That::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Asobu_Window != "That")
	{
		Death();
	}
}

void Asobu_That::End()
{
}

std::string Asobu_That::CheckDayTime(int DayTime)
{
	std::string CurDayTime = "";
	switch (DayTime)
	{
	case 1:
		CurDayTime = "낮";
		return CurDayTime;
		break;
	case 2:
		CurDayTime = "저녁";
		return CurDayTime;
		break;
	case 3:
		CurDayTime = "밤";
		return CurDayTime;
		break;
	default:
		break;
	}
	return "이상함";
}
