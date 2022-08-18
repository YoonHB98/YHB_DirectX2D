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
	TextureRenderer->GetTransform().SetLocalPosition(float4(0, 10, 0));
	TextureRenderer->SetTexture("Twitter.png");
	TextureRenderer->ScaleToTexture();

	Loading = CreateComponent<GameEngineTextureRenderer>();
	Loading->GetTransform().SetLocalPosition(float4(0,210, 0));
	Loading->GetTransform().SetLocalScale(float4(18, 18));
	Loading->CreateFrameAnimationCutTexture("loading", FrameAnimation_DESC("icon_loading_poketter.png", 0, 7, 0.09f, true));
	Loading->ChangeFrameAnimation("loading");

}

void Twitter::Update(float _DeltaTime)
{
	GlobalContentsValue::Stream = true;
	if (GlobalContentsValue::Twitter)
	{
		if (GlobalContentsValue::Contents == "Tutorial")
		{
			TweetComment::RemainTwit = 2;
			GlobalContentsValue::Contents == "";
		}
		ChangeZPos(0);
	}
	else
	{
		ChangeZPos(500);
		return;
	}
}

void Twitter::End()
{
}