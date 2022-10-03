#include "PreCompile.h"
#include "CommentGoodEnding.h"
#include "Stream.h"
#include "SuperChat.h"

CommentGoodEnding::CommentGoodEnding()
{
}

CommentGoodEnding::~CommentGoodEnding()
{
}

void CommentGoodEnding::Start()
{
	GameEngineTextureRenderer* TextRend = CreateComponent<GameEngineTextureRenderer>();
	TextRend->SetTexture("Rect.png");
	TextRend->ScaleToTexture();
	TextRend->GetTransform().SetLocalPosition(float4(88, -185, -1));

	GameEngineTextureRenderer* TextRend2 = CreateComponent<GameEngineTextureRenderer>();
	TextRend2->SetTexture("Rect.png");
	TextRend2->ScaleToTexture();
	TextRend2->GetTransform().SetLocalPosition(float4(-102, -185, -1));

	GameEngineTextureRenderer* TextRend3 = CreateComponent<GameEngineTextureRenderer>();
	TextRend3->SetTexture("Speed.png");
	TextRend3->GetTransform().SetLocalScale(float4(183, 14));
	TextRend3->GetTransform().SetLocalPosition(float4(138, 158, -1));

	Font = CreateComponent<Myfont>();
	Font->SetLeftAndRightSort(LeftAndRightSort::CENTER);
	Font->TextDraw("방송 속도(보통)", "galmuri11", float4(618, 103), float4(94 / 255, 60 / 255, 127 / 255, 1), 12);
	Font->SetRenderingOrder(500);

	GlobalContentsValue::FirstComment = "";
	GlobalContentsValue::SecondComment = "";

}

void CommentGoodEnding::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Stream == false)
	{
		ChangeZPos(500);
		Font->TextDraw(" ", "galmuri11", float4(618, 103), float4(94 / 255, 60 / 255, 127 / 255, 1), 12);
		if (DeathTime)
		{
			Death();
		}
		return;
	}
	else
	{
		ChangeZPos(-160);
	}
	if (GlobalContentsValue::Stream)
	{
		if ((i < ((GlobalContentsValue::ChangeTime ) / 0.5))
			&& i < 5)
		{
			DeathTime = true;
			CreateText("HappyEnd" + std::to_string(i) + ".png");
			i = i + 1;
		}else
			if (i < 12 && i >= 5 )
			{
				CreateText("HappyEnd" + std::to_string(i) + ".png");
				i = i + 1;
			}else
				if (i < 21
					&&(i - 11) < (GlobalContentsValue::ChangeTime - 5.0f) / 0.5)
				{
					CreateText("HappyEnd" + std::to_string(i) + ".png");
					i = i + 1;
				}
				else if (i < 28 && i >=21)
				{
					CreateText("HappyEnd" + std::to_string(i) + ".png");
					i = i + 1;
				}
				else if (i < 31 && i > 27
					&& (i - 27) < (GlobalContentsValue::ChangeTime - 7.0f) / 0.5)
				{
					CreateText("HappyEnd" + std::to_string(i) + ".png");
					i = i + 1;
				}
				else if (i < 38 && i >= 31)
				{
					CreateText("HappyEnd" + std::to_string(i) + ".png");
					i = i + 1;
				}
				else if (i < 41 && i > 37
					&& (i - 37) < (GlobalContentsValue::ChangeTime - 10.0f) / 0.5)
				{
					CreateText("HappyEnd" + std::to_string(i) + ".png");
					i = i + 1;
				}
				else if (i < 48 && i >= 41)
				{
					CreateText("HappyEnd" + std::to_string(i) + ".png");
					i = i + 1;
				}
				else if (i < 52 && i > 47
					&& (i - 48) < (GlobalContentsValue::ChangeTime - 13.5f) / 0.5)
				{
					CreateText("HappyEnd" + std::to_string(i) + ".png");
					i = i + 1;
				}
				else if (i < 59 && i >= 52)
				{
					CreateText("HappyEnd" + std::to_string(i) + ".png");
					i = i + 1;
				}
				else if (i < 68 && i > 58
					&& (i - 59) < (GlobalContentsValue::ChangeTime - 16.5f) / 0.5)
				{
					CreateText("HappyEnd" + std::to_string(i) + ".png");
					i = i + 1;
				}
				else if (i < 75 && i >= 68)
				{
					CreateText("HappyEnd" + std::to_string(i) + ".png");
					i = i + 1;
				}
				else if (i < 79 && i > 74
					&& (i - 74) < (GlobalContentsValue::ChangeTime - 23.0f) / 0.5)
				{
					CreateText("HappyEnd" + std::to_string(i) + ".png");
					i = i + 1;
				}
				else if (i < 86 && i >= 79)
				{
					CreateText("HappyEnd" + std::to_string(i) + ".png");
					i = i + 1;
				}
				else if (i < 118 && i > 85
					&& (i - 86) < (GlobalContentsValue::ChangeTime - 27.5f) / 0.5)
				{
					CreateText("HappyEnd" + std::to_string(i) + ".png");
					i = i + 1;
				}
		GlobalContentsValue::BgmSpeed = 1.0f;
		Font->TextDraw("방송 속도 : 말 빠른 오타쿠", "galmuri11", float4(618, 103), float4(94 / 255, 60 / 255, 127 / 255, 1), 12);
		GlobalContentsValue::Check = false;
	}

}

void CommentGoodEnding::End()
{
}



void CommentGoodEnding::CreateText(const std::string& _Text)
{
	GetLevel()->CreateActor<SuperChat>();
	CommentTextureRenderer* TextRend = CreateComponent<CommentTextureRenderer>();
	TextRend->SetTexture(_Text);
	TextRend->ScaleToTexture();
	TextRend->GetTransform().SetLocalPosition(float4(138.0f, 137.0f - static_cast<float>(TextNum), -2.0f));
	TextRend->Clip.PosY = 126.0f;

	float4 Scale = TextRend->GetTransform().GetLocalScale();

	TextNum = TextNum + 25;
	Text.push_back(TextRend);

	MoveStart++;
	if (MoveStart >= 10)
	{
		Move = Move + 25;
		TextMove(25.0f, static_cast<float>(Move));
	}

}

void CommentGoodEnding::TextMove(float Y_, float last)
{
	std::vector<CommentTextureRenderer*>::iterator StartIter = Text.begin();
	std::vector<CommentTextureRenderer*>::iterator EndIter = Text.end();
	std::string A = (*StartIter)->GetNameCopy();



	for (; StartIter != EndIter - 1; ++StartIter)
	{
		(*StartIter)->GetTransform().SetLocalMove(float4(0, Y_, 0));
	}


	(StartIter) = EndIter - 1;
	(*StartIter)->GetTransform().SetLocalMove(float4(0, last, 0));


}
