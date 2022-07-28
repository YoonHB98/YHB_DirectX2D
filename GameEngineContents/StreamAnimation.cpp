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
}

void StreamAnimation::Update(float _DeltaTime)
{

	if (GlobalContentsValue::Stream
		&& first)
	{
		Renderer->ChangeFrameAnimation("cho_kashikoma");
		first = false;
		ChangeZPos(-500);
	}
}

void StreamAnimation::End()
{
}