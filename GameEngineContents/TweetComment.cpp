#include "PreCompile.h"
#include "TweetComment.h"
#include "NotificationDayTime.h"

TweetComment::TweetComment() 
{
}

TweetComment::~TweetComment() 
{
}

void TweetComment::Start()
{
}

void TweetComment::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Contents != "Tutorial"
		&& CurStatus != GlobalContentsValue::Twitter)
	{
		CurStatus = GlobalContentsValue::Twitter;
		std::vector<CommentTextureRenderer*>::iterator StartIter = TextVector.begin();
		std::vector<CommentTextureRenderer*>::iterator EndIter = TextVector.end();

		for (; StartIter != EndIter; ++StartIter)
		{
			(*StartIter)->GetTransform().SetLocalMove(float4(0, -12.5f, 0));
		}
	}
	if (CurContents != GlobalContentsValue::Contents)
	{
		CurContents = GlobalContentsValue::Contents;
		i = 1;
	}
	if (GlobalContentsValue::Twitter)
	{
		Time = Time + _DeltaTime;
		if (Time >3.0f
			&& GlobalContentsValue::RemainTwitnum != 0)
		{
			Time = Time - 3.0f;
			CreateText(GlobalContentsValue::Contents +"Twit" +  std::to_string(i) + ".png");
			i = i + 1;
			GlobalContentsValue::RemainTwitnum = GlobalContentsValue::RemainTwitnum - 1;
		}
		else if (GlobalContentsValue::RemainTwitnum == 0
			&& Time > 2.0f
			&& LoadingFirst)
		{
			LoadingFirst = false;
			Time = Time  - 1.0f;
			LoadingEnd();
		}
		if (i >2
			|| CurContents != "Tutorial")
		{
			MoveY(YSize);
		}


	}
	else
	{
		if (GlobalContentsValue::RemainTwitnum != 0)
		{
			CreateText(GlobalContentsValue::Contents + "Twit" + std::to_string(i) + ".png");
			i = i + 1;
			GlobalContentsValue::RemainTwitnum = GlobalContentsValue::RemainTwitnum - 1;
			if (GlobalContentsValue::RemainTwitnum == 0)
			{
				Time = 0.0f;
				LoadingFirst = false;
				LoadingEnd();
			}
		}
		if (i > 2
			|| CurContents != "Tutorial")
		{
			MoveY(YSize);
		}
		LoadingFirst = true;
		return;
	}

}

void TweetComment::End()
{
}

void TweetComment::CreateText(const std::string& _Text)
{
	CommentTextureRenderer* TextRend = CreateComponent<CommentTextureRenderer>();
	TextRend->SetTexture(_Text);
	TextRend->ScaleToTexture();
	TextRend->PixelDataInst.Slice.y = 507.0f;
	YSize = TextRend->GetTransform().GetLocalScale().y;
	TextRend->GetTransform().SetLocalPosition(float4(-78, 198 - YSize /2, -500,-3));
	TextVector.push_back(TextRend);
	Bot = Bot - YSize;
	if (GlobalContentsValue::Contents + "Twit" + std::to_string(i) == "CommunicationStreamTwit1")
	{
		GetLevel()->CreateActor<NotificationDayTime>();
	}
}

void TweetComment::MoveY(float Y)
{
	if (YSize  > 0.0f && GlobalContentsValue::Contents + "Twit" + std::to_string(i) + ".png" == "CommunicationStreamTwit1")
	{
		YSize = 0.0f;
		std::vector<CommentTextureRenderer*>::iterator StartIter = TextVector.begin();
		std::vector<CommentTextureRenderer*>::iterator EndIter = TextVector.end();

		for (; StartIter != EndIter - 1; ++StartIter)
		{
			(*StartIter)->GetTransform().SetLocalMove(float4(0, -YSize, 0));
		}
	}
	else
	{
		YSize = YSize - 500 * GameEngineTime::GetDeltaTime();
		std::vector<CommentTextureRenderer*>::iterator StartIter = TextVector.begin();
		std::vector<CommentTextureRenderer*>::iterator EndIter = TextVector.end();

		for (; StartIter != EndIter - 1; ++StartIter)
		{
			(*StartIter)->GetTransform().SetLocalMove(float4(0, -500 * GameEngineTime::GetDeltaTime(), 0));
		}
	}
	if (YSize < 0.0f)
	{
		std::vector<CommentTextureRenderer*>::iterator StartIter = TextVector.begin();
		std::vector<CommentTextureRenderer*>::iterator EndIter = TextVector.end();

		for (; StartIter != EndIter - 1; ++StartIter)
		{
			(*StartIter)->GetTransform().SetLocalMove(float4(0, -YSize, 0));
		}
		YSize = 0.0f;
	}

}

void TweetComment::LoadingEnd()
{
	std::vector<CommentTextureRenderer*>::iterator StartIter = TextVector.begin();
	std::vector<CommentTextureRenderer*>::iterator EndIter = TextVector.end();

	for (; StartIter != EndIter; ++StartIter)
	{
		(*StartIter)->GetTransform().SetLocalMove(float4(0, 25,0));
	}
}
