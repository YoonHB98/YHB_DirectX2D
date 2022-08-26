#include "PreCompile.h"
#include "Twitter.h"
#include "TweetComment.h"

Twitter::Twitter() 
{
}

Twitter::~Twitter() 
{
}

void Twitter::Start()
{
	TextureRenderer = CreateComponent<CommentTextureRenderer>();
	TextureRenderer->GetTransform().SetLocalPosition(float4(-75, 10, 0));
	TextureRenderer->SetTexture("Twitter.png");
	TextureRenderer->ScaleToTexture();

	Loading = CreateComponent<GameEngineTextureRenderer>();
	Loading->GetTransform().SetLocalPosition(float4(-75,210, 0));
	Loading->GetTransform().SetLocalScale(float4(18, 18));
	Loading->CreateFrameAnimationCutTexture("loading", FrameAnimation_DESC("icon_loading_poketter.png", 0, 7, 0.09f, true));
	Loading->ChangeFrameAnimation("loading");

}

void Twitter::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Twitter)
	{
		if (GlobalContentsValue::Contents == "Tutorial"
			&&First)
		{
			TweetComment::RemainTwit = 2;
			First = false;
		}
		ChangeZPos(-300);
		if (TweetComment::RemainTwit == 0)
		{
			Time = Time + _DeltaTime;
			if (Time > 5.0f
				|| GameEngineInput::GetInst()->IsDown("MouseClick") ==true)
			{
				GlobalContentsValue::Twitter = false;
				GlobalContentsValue::RemainLinenum = 6;
				First = true;
				Time = 0;
			}
		}
	}
	else
	{
		ChangeZPos(500);
		Time = 0;
		return;
	}
}

void Twitter::End()
{
}