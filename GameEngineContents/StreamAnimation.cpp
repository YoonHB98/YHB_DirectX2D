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

	ContentsMap["Tutorial"] = StreamContents::Tutorial;
}

void StreamAnimation::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Stream == false)
	{
		ChangeZPos(500);
		return;
	}
	else
	{
		Contents = ContentsMap[GlobalContentsValue::Contents];
		ChangeZPos(-510);
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
