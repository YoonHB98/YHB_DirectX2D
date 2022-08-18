#include "PreCompile.h"
#include "TweetComment.h"

int TweetComment::RemainTwit = 0;

TweetComment::TweetComment() 
{
}

TweetComment::~TweetComment() 
{
}

void TweetComment::Start()
{
	SetTexture("Color.png");
	SetLocalPosition(float4(0, -50, 0));
}

void TweetComment::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Twitter)
	{
		Time = Time + _DeltaTime;
		if (Time > 1.0f
			&& GlobalContentsValue::RemainTwitnum != 0)
		{
			Time = Time - 1.0f;
			CreateText(GlobalContentsValue::Contents +"Twit" +  std::to_string(i) + ".png");
			i = i + 1;
			GlobalContentsValue::RemainTwitnum = GlobalContentsValue::RemainTwitnum - 1;
		}
		else if (GlobalContentsValue::RemainTwitnum == 0
			&& Time > 1.0f
			&& LoadingFirst)
		{
			LoadingFirst = false;
			Time = Time  - 1.0f;
			LoadingEnd();
		}
		if (i >2)
		{
			MoveY(YSize);
		}

		ChangeZPos(0);
	}
	else
	{
		LoadingFirst = true;
		ChangeZPos(500);
		return;
	}

}

void TweetComment::End()
{
}

void TweetComment::CreateText(const std::string& _Text)
{
	GameEngineTextureRenderer* TextRend = CreateComponent<GameEngineTextureRenderer>();
	TextRend->SetTexture(_Text);
	TextRend->ScaleToTexture();
	YSize = TextRend->GetTransform().GetLocalScale().y;
	TextRend->GetTransform().SetLocalPosition(float4(-3, 198 - YSize /2, -500));
	TextVector.push_back(TextRend);
	Bot = Bot - YSize;
}

void TweetComment::MoveY(float Y)
{
	if (YSize  > 0.0f)
	{
		YSize = YSize - 500 * GameEngineTime::GetDeltaTime();
	}
	else
	{
		return;
	}
	std::vector<GameEngineTextureRenderer*>::iterator StartIter = TextVector.begin();
	std::vector<GameEngineTextureRenderer*>::iterator EndIter = TextVector.end();

	for (; StartIter != EndIter - 1 ; ++StartIter )
	{
		(*StartIter)->GetTransform().SetLocalMove(float4(0, -500 * GameEngineTime::GetDeltaTime() ));
	}
}

void TweetComment::LoadingEnd()
{
	std::vector<GameEngineTextureRenderer*>::iterator StartIter = TextVector.begin();
	std::vector<GameEngineTextureRenderer*>::iterator EndIter = TextVector.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		(*StartIter)->GetTransform().SetLocalMove(float4(0, 25));
	}
}
