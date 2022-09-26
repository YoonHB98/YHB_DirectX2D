#include "PreCompile.h"
#include "Neru_Night.h"

Neru_Night::Neru_Night() 
{
}

Neru_Night::~Neru_Night() 
{
}

void Neru_Night::Start()
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
	Font->TextDraw("밤까지 잔다", "galmuri11", float4(545, 112), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 17);
	Font->SetRenderingOrder(501);
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("icon_status_stress.png");
		Renderer->GetTransform().SetLocalScale(float4(24,20));
		Renderer->GetTransform().SetLocalPosition(float4(80, 80, -3));
	}
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("icon_status_yami.png");
		Renderer->GetTransform().SetLocalScale(float4(24, 20));
		Renderer->GetTransform().SetLocalPosition(float4(80, 55, -3));
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
		for (float X = 195.5f;X < 226.0f ; X = X +7.5f)
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
		for (float X = 195.5f; X < 196.5f; X = X + 7.5f)
		{
			CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
			Renderer->SetTexture("DownArrow.png");
			Renderer->GetTransform().SetLocalScale(float4(7, 8));
			Renderer->GetTransform().SetLocalPosition(float4(X, 61.5f, -5));
			Renderer->Color.PosX = 215.0f / 255.0f;
			Renderer->Color.PosY = 90.0f / 255.0f;
			Renderer->Color.SizeX = 90.0f / 255.0f;
		}
	}


	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("방송 전까지만 잘게", "galmuri11", float4(548, 150), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 10);
		Script->SetRenderingOrder(501);
	}

	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("스트레스", "galmuri11", float4(572,180), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(501);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw(std::to_string(GlobalContentsValue::Stress), "DinkieBitmap 7px", float4(675, 185), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(501);
	}
	{
		int Temp = GlobalContentsValue::Stress;
		Temp = Temp - 9;
		if (Temp < 0)
		{
			Temp = 0;
		}
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw(std::to_string(Temp), "DinkieBitmap 7px", float4(720, 175), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 30);
		Script->SetRenderingOrder(501);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("멘탈", "galmuri11", float4(572, 205), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(501);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw(std::to_string(GlobalContentsValue::Mental), "DinkieBitmap 7px", float4(675, 210), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(501);
	}
	{
		int Temp = GlobalContentsValue::Mental;
		Temp = Temp - 2;
		if (Temp < 0)
		{
			Temp = 0;
		}
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw(std::to_string(Temp), "DinkieBitmap 7px", float4(720, 202), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 30);
		Script->SetRenderingOrder(501);
	}
	{
		std::string DayTime = CheckDayTime(GlobalContentsValue::DayTime);
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::CENTER);
		Script->TextDraw(DayTime, "galmuri11", float4(558, 435), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(501);
	}
	{
		std::string DayTime = CheckDayTime(GlobalContentsValue::DayTime + 2);
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::CENTER);
		Script->TextDraw(DayTime, "galmuri11", float4(790, 435), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(501);
	}
	{
		std::string DayTime = CheckDayTime(GlobalContentsValue::DayTime + 2);
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::CENTER);
		Script->TextDraw(DayTime +"이  될  거야", "galmuri11", float4(674, 455), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 8);
		Script->SetRenderingOrder(501);
	}

	ChangeZPos(-400);
}

void Neru_Night::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Asobu_Window != "Night")
	{
		Death();
	}
}

void Neru_Night::End()
{
}

std::string Neru_Night::CheckDayTime(int DayTime)
{
	std::string CurDayTime = "";
	switch (DayTime)
	{
	case 0:
		CurDayTime = "낮";
		return CurDayTime;
		break;
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
	case 4:
		CurDayTime = "다음날";
		return CurDayTime;
		break;
	default:
		CurDayTime = "다음날";
		return CurDayTime;
		break;
	}
	return "이상함";
}
