#include "PreCompile.h"
#include "Stream_Game.h"

Stream_Game::Stream_Game()
{
}

Stream_Game::~Stream_Game()
{
}

void Stream_Game::Start()
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
		Renderer->GetTransform().SetLocalPosition(float4(202, -175, -3));
	}

	Font = CreateComponent<Myfont>();
	Font->SetLeftAndRightSort(LeftAndRightSort::LEFT);
	Font->TextDraw("���� ��Ȳ 1", "galmuri11", float4(545, 112), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 17);
	Font->SetRenderingOrder(500);

	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("���� ��� �Ұž�, ��⸸ �ص� Ī���޴� ���̶�� ���� ��\n���!", "galmuri11", float4(548, 150), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 10);
		Script->SetRenderingOrder(500);
	}
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("icon_status_follower.png");
		Renderer->GetTransform().SetLocalScale(float4(24, 20));
		Renderer->GetTransform().SetLocalPosition(float4(80, 75, -3));
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("�ȷο�", "galmuri11", float4(572, 185), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(500);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("���� ��� ���ʽ�", "galmuri11", float4(548, 210), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 8);
		Script->SetRenderingOrder(500);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("x", "DinkieBitmap 7px", float4(680, 207), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 12);
		Script->SetRenderingOrder(500);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("2", "DinkieBitmap 7px", float4(690, 203), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(500);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("���Ӻ��ʽ�", "galmuri11", float4(548, 230), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 8);
		Script->SetRenderingOrder(500);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("x", "DinkieBitmap 7px", float4(680, 227), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 12);
		Script->SetRenderingOrder(500);
	}
	{
		Myfont* Script = CreateComponent<Myfont>();
		Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
		Script->TextDraw("1 . 5", "DinkieBitmap 7px", float4(690, 223), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
		Script->SetRenderingOrder(500);
	}
		{
			Myfont* Script = CreateComponent<Myfont>();
			Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
			Script->TextDraw("��ȭ �ɷº��ʽ�", "galmuri11", float4(548, 250), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 8);
			Script->SetRenderingOrder(500);
		}
		{
			Myfont* Script = CreateComponent<Myfont>();
			Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
			Script->TextDraw("x", "DinkieBitmap 7px", float4(680, 247), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 12);
			Script->SetRenderingOrder(500);
		}
		{
			Myfont* Script = CreateComponent<Myfont>();
			Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
			Script->TextDraw("1", "DinkieBitmap 7px", float4(690, 243), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
			Script->SetRenderingOrder(500);
		}
		{
			CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
			Renderer->SetTexture("icon_status_stress.png");
			Renderer->GetTransform().SetLocalScale(float4(24, 20));
			Renderer->GetTransform().SetLocalPosition(float4(80, -10, -3));
		}
		{
			Myfont* Script = CreateComponent<Myfont>();
			Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
			Script->TextDraw("��Ʈ����", "galmuri11", float4(572,270), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
			Script->SetRenderingOrder(500);
		}
		{
			Myfont* Script = CreateComponent<Myfont>();
			Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
			Script->TextDraw(std::to_string(GlobalContentsValue::Stress), "DinkieBitmap 7px", float4(675, 275), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
			Script->SetRenderingOrder(500);
		}
		{
			CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
			Renderer->SetTexture("Arrow.png");
			Renderer->GetTransform().SetLocalScale(float4(15, 12));
			Renderer->GetTransform().SetLocalPosition(float4(226.5f, -15.0f, -5));
		}
		{
			for (float X = 195.5f; X < 239.0f; X = X + 7.5f)
			{
				CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
				Renderer->SetTexture("UpArrow.png");
				Renderer->GetTransform().SetLocalScale(float4(7, 8));
				Renderer->GetTransform().SetLocalPosition(float4(X, -3.0f, -5));
			}
		}
		{
			int Temp = GlobalContentsValue::Stress;
			Temp = Temp + 18;
			if (Temp > 100)
			{
				Temp = 100;
			}
			Myfont* Script = CreateComponent<Myfont>();
			Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
			Script->TextDraw(std::to_string(Temp), "DinkieBitmap 7px", float4(720, 267), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 30);
			Script->SetRenderingOrder(500);
		}
		{
			Myfont* Script = CreateComponent<Myfont>();
			Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
			Script->TextDraw("���  ���ʽ�", "galmuri11", float4(548, 310), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 8);
			Script->SetRenderingOrder(500);
		}
		{
			Myfont* Script = CreateComponent<Myfont>();
			Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
			Script->TextDraw("����", "galmuri11", float4(548, 325), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
			Script->SetRenderingOrder(500);
		}
		{
			Myfont* Script = CreateComponent<Myfont>();
			Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
			Script->TextDraw("1", "DinkieBitmap 7px", float4(645, 332), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
			Script->SetRenderingOrder(500);
		}
		{
			CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
			Renderer->SetTexture("Arrow.png");
			Renderer->GetTransform().SetLocalScale(float4(15, 12));
			Renderer->GetTransform().SetLocalPosition(float4(205.5f, -72.0f, -5));
		}
		{
			CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
			Renderer->SetTexture("UpArrow.png");
			Renderer->GetTransform().SetLocalScale(float4(7, 8));
			Renderer->GetTransform().SetLocalPosition(float4(168, -59.0f, -5));
			Renderer->Color.PosX = 215.0f / 255.0f;
			Renderer->Color.PosY = 90.0f / 255.0f;
			Renderer->Color.SizeX = 90.0f / 255.0f;
		}
		{
			Myfont* Script = CreateComponent<Myfont>();
			Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
			Script->TextDraw("2", "DinkieBitmap 7px", float4(700,325), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 30);
			Script->SetRenderingOrder(500);
		}
		{
			Myfont* Script = CreateComponent<Myfont>();
			Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
			Script->TextDraw("��ȭ �ɷ�", "galmuri11", float4(548, 355), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
			Script->SetRenderingOrder(500);
		}
		{
			Myfont* Script = CreateComponent<Myfont>();
			Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
			Script->TextDraw("0", "DinkieBitmap 7px", float4(645, 362), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
			Script->SetRenderingOrder(500);
		}
		{
			CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
			Renderer->SetTexture("Arrow.png");
			Renderer->GetTransform().SetLocalScale(float4(15, 12));
			Renderer->GetTransform().SetLocalPosition(float4(205.5f, -102.0f, -5));
		}
		{
			CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
			Renderer->SetTexture("UpArrow.png");
			Renderer->GetTransform().SetLocalScale(float4(7, 8));
			Renderer->GetTransform().SetLocalPosition(float4(168, -89.0f, -5));
			Renderer->Color.PosX = 215.0f / 255.0f;
			Renderer->Color.PosY = 90.0f / 255.0f;
			Renderer->Color.SizeX = 90.0f / 255.0f;
		}
		{
			Myfont* Script = CreateComponent<Myfont>();
			Script->SetLeftAndRightSort(LeftAndRightSort::LEFT);
			Script->TextDraw("1", "DinkieBitmap 7px", float4(700, 355), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 30);
			Script->SetRenderingOrder(500);
		}

		{
			std::string DayTime = CheckDayTime(GlobalContentsValue::DayTime);
			Myfont* Script = CreateComponent<Myfont>();
			Script->SetLeftAndRightSort(LeftAndRightSort::CENTER);
			Script->TextDraw(DayTime, "galmuri11", float4(558, 435), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
			Script->SetRenderingOrder(500);
		}
		{
			std::string DayTime = CheckDayTime(GlobalContentsValue::DayTime + 1);
			Myfont* Script = CreateComponent<Myfont>();
			Script->SetLeftAndRightSort(LeftAndRightSort::CENTER);
			Script->TextDraw(DayTime, "galmuri11", float4(790, 435), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 18);
			Script->SetRenderingOrder(500);
		}
		{
			std::string DayTime = CheckDayTime(GlobalContentsValue::DayTime + 1);
			Myfont* Script = CreateComponent<Myfont>();
			Script->SetLeftAndRightSort(LeftAndRightSort::CENTER);
			Script->TextDraw(DayTime + "��  ��  �ž�", "galmuri11", float4(674, 455), float4(75.0f / 255.0f, 35.0f / 255.0f, 198.0f / 255.0f, 1), 8);
			Script->SetRenderingOrder(500);
		}

		ChangeZPos(-400);
}

void Stream_Game::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Stream_Window != "Game")
	{
		Death();
	}
}

void Stream_Game::End()
{
}

std::string Stream_Game::CheckDayTime(int DayTime)
{
	std::string CurDayTime = "";
	switch (DayTime)
	{
	case 1:
		CurDayTime = "��";
		return CurDayTime;
		break;
	case 2:
		CurDayTime = "����";
		return CurDayTime;
		break;
	case 3:
		CurDayTime = "��";
		return CurDayTime;
		break;
	case 4:
		CurDayTime = "������";
		return CurDayTime;
		break;
	default:
		CurDayTime = "������";
		return CurDayTime;
		break;
	}
	return "�̻���";
}
