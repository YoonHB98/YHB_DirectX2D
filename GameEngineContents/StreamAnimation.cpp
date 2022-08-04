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
	Renderer->CreateFrameAnimationCutTexture("cho_kashikoma", FrameAnimation_DESC("cho_kashikoma.png", 0, 7, 0.15f, false));
	std::vector<unsigned int> End { 0, 2 };
	Renderer->CreateFrameAnimationCutTexture("cho_idle", FrameAnimation_DESC("cho_idle.png", 0, 2, 0.5f, false));
	Renderer->CreateFrameAnimationCutTexture("cho_idleEnd", FrameAnimation_DESC("cho_idle.png", End, 0.5f, false));
	Renderer->CreateFrameAnimationCutTexture("cho_kawaiku", FrameAnimation_DESC("cho_kawaiku.png", 0, 2, 0.5f, false));
	Renderer->CreateFrameAnimationCutTexture("cho_pointing", FrameAnimation_DESC("cho_pointing.png", 0, 4, 0.5f, false));

	ContentsMap["Tutorial"] = StreamContents::Tutorial;
}

void StreamAnimation::Update(float _DeltaTime)
{
	GlobalContentsValue::Stream = true;
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
	Myfont* Font = CreateComponent<Myfont>();
	Font->TextDrawTime("안녕하세요요요요요", "Galmuri11",float4(100,100),float4(1,1,1,1), 80.0f, 2.0f);

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
