#include "PreCompile.h"
#include "CommentBadEnding.h"
#include "Stream.h"
#include "SuperChat.h"

CommentBadEnding::CommentBadEnding()
{
}

CommentBadEnding::~CommentBadEnding()
{
}

void CommentBadEnding::Start()
{
	GameEngineTextureRenderer* TextRend = CreateComponent<GameEngineTextureRenderer>();
	TextRend->SetTexture("Rect.png");
	TextRend->ScaleToTexture();
	TextRend->GetTransform().SetLocalPosition(float4(88, -185));

	GameEngineTextureRenderer* TextRend2 = CreateComponent<GameEngineTextureRenderer>();
	TextRend2->SetTexture("Rect.png");
	TextRend2->ScaleToTexture();
	TextRend2->GetTransform().SetLocalPosition(float4(-102, -185));

	GameEngineTextureRenderer* TextRend3 = CreateComponent<GameEngineTextureRenderer>();
	TextRend3->SetTexture("Speed.png");
	TextRend3->GetTransform().SetLocalScale(float4(183, 14));
	TextRend3->GetTransform().SetLocalPosition(float4(138, 158));

	Font = CreateComponent<Myfont>();
	Font->SetLeftAndRightSort(LeftAndRightSort::CENTER);
	Font->TextDraw("방송 속도(보통)", "galmuri11", float4(618, 103), float4(94 / 255, 60 / 255, 127 / 255, 1), 12);
	Font->SetRenderingOrder(500);

	GlobalContentsValue::FirstComment = "";
	GlobalContentsValue::SecondComment = "";

}

void CommentBadEnding::Update(float _DeltaTime)
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
		ChangeZPos(static_cast<float>(std::stoi(Stream::Inst_->StreamMainCol->GetNameConstRef())));
	}
	if (GlobalContentsValue::Stream)
	{
		if (i < ((GlobalContentsValue::ChangeTime) / 1.0)
			&& i < 15)
		{
			DeathTime = true;
			CreateText("BedEnd" + std::to_string(i) + ".png");
			i = i + 1;
		}
		GlobalContentsValue::BgmSpeed = 1.0f;
		Font->TextDraw("방송 속도 : 말 빠른 오타쿠", "galmuri11", float4(618, 103), float4(94 / 255, 60 / 255, 127 / 255, 1), 12);
		GlobalContentsValue::Check = false;
	}

}

void CommentBadEnding::End()
{
}



void CommentBadEnding::CreateText(const std::string& _Text)
{
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

void CommentBadEnding::TextMove(float Y_, float last)
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
