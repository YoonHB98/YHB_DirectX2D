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

	Exit = CreateComponent<GameEngineCollision>();
	Exit->GetTransform().SetLocalPosition(float4(117, 255.5, 5));
	Exit->GetTransform().SetLocalScale(float4(10, 10, 500));
	Exit->ChangeOrder(OBJECTORDER::Exit);

	Loading = CreateComponent<GameEngineTextureRenderer>();
	Loading->GetTransform().SetLocalPosition(float4(-75,210, 0));
	Loading->GetTransform().SetLocalScale(float4(18, 18));
	Loading->CreateFrameAnimationCutTexture("loading", FrameAnimation_DESC("icon_loading_poketter.png", 0, 7, 0.09f, true));
	Loading->ChangeFrameAnimation("loading");

	SetName("Twitter");
}

void Twitter::Update(float _DeltaTime)
{
	StatusChange();
	if (GlobalContentsValue::Twitter)
	{
		if (GlobalContentsValue::Contents == "Tutorial"
			&&First)
		{
			First = false;
		}
		ChangeZPos(-300);
		/*if (GlobalContentsValue::RemainTwitnum == 0)
		{
			Time = Time + _DeltaTime;
			if (Time > 5.0f)
			{
				Check = true;
				GlobalContentsValue::Twitter = false;
				GlobalContentsValue::RemainLinenum = 6;
				First = true;
				Time = 0;
			}
		}*/
	}
	else
	{
		if (First == false)
		{
			Check = true;
			GlobalContentsValue::Twitter = false;
			GlobalContentsValue::RemainLinenum = 6;
			First = true;
			Time = 0;
		}
		ChangeZPos(500);
		Time = 0;
		return;
	}
}

void Twitter::End()
{
}

void Twitter::StatusChange()
{
	if (Check)
	{
		Check = false;
		if (GlobalContentsValue::Contents == "Tutorial")
		{
			GlobalContentsValue::Followers = GlobalContentsValue::Followers + 1000;
			GlobalContentsValue::Stress = GlobalContentsValue::Stress + 10;
		}
	}
}
