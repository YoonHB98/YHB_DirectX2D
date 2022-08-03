#include "PreCompile.h"
#include "StreamAnimation.h"

StreamAnimation::StreamAnimation() 
{
}

StreamAnimation::~StreamAnimation() 
{
}

void StreamAnimation::Start()
{
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->GetTransform().SetLocalPosition(float4(-120, 40, 0));
	Renderer->GetTransform().SetLocalScale(float4(348, 227));
	Renderer->CreateFrameAnimation("cho_kashikoma", FrameAnimation_DESC("cho_kashikoma.png", 0, 7, 0.15f, false));
	Renderer->CreateFrameAnimation("cho_idle", FrameAnimation_DESC("cho_idle.png", 0, 1, 0.5f, true));
	Renderer->CreateFrameAnimation("cho_idleEnd", FrameAnimation_DESC("cho_idle.png", 0, 0, 0.5f, false));
	Renderer->CreateFrameAnimation("cho_kawaiku", FrameAnimation_DESC("cho_kawaiku.png", 0, 2, 0.5f, true));
	Renderer->CreateFrameAnimation("cho_kawaikuEnd", FrameAnimation_DESC("cho_kawaiku.png", 2, 2, 0.5f, false));
	Renderer->CreateFrameAnimation("cho_pointing", FrameAnimation_DESC("cho_pointing.png", 0, 4, 0.5f, true));
	Renderer->CreateFrameAnimation("cho_pointingEnd", FrameAnimation_DESC("cho_pointing.png", 4, 4, 0.5f, false));

	ContentsMap["Tutorial"] = StreamContents::Tutorial;
}

void StreamAnimation::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Stream == false)
	{
		ChangeZPos(500);
		first = true;
		return;
	}
	else
	{
		if (first == true)
		{
			first = false;
			ChangeZPos(-510);
		}
		Contents = ContentsMap[GlobalContentsValue::Contents];
		ContentsUpdate(Contents);
	}

}

void StreamAnimation::End()
{
}

void StreamAnimation::ContentsUpdate(StreamContents Contents)
{
	switch (Contents)
	{
	case StreamContents::Tutorial:
		Tutorial();
		break;
	default:
		break;
	}
}
