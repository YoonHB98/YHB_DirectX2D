#include "PreCompile.h"
#include "StreamAnimation.h"
#include "Stream.h"

StreamAnimation::StreamAnimation() 
{
}

StreamAnimation::~StreamAnimation() 
{
}

void StreamAnimation::Start()
{
	Blank = CreateComponent<GameEngineTextureRenderer>();
	Blank->SetTexture("Color.png");

	BG = CreateComponent<GameEngineTextureRenderer>();
	BG->SetTexture("bg_stream.png");
	BG->GetTransform().SetLocalPosition(float4(-140, 55, 0));
	BG->GetTransform().SetLocalScale(float4(335, 223));
	//348 227 -> 335 223 13 4
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->GetTransform().SetLocalPosition(float4(-140, 55, 0));
	Renderer->GetTransform().SetLocalScale(float4(335, 223));
	Renderer->CreateFrameAnimationCutTexture("cho_kashikoma", FrameAnimation_DESC("cho_kashikoma.png", 0, 7, 0.15f, false));
	std::vector<unsigned int> End { 0, 2 };
	Renderer->CreateFrameAnimationCutTexture("cho_idle", FrameAnimation_DESC("cho_idle.png", 0, 2, 0.5f, false));
	Renderer->CreateFrameAnimationCutTexture("cho_idleEnd", FrameAnimation_DESC("cho_idle.png", End, 0.5f, false));
	Renderer->CreateFrameAnimationCutTexture("cho_kawaiku", FrameAnimation_DESC("cho_kawaiku.png", 0, 2, 0.25f, false));
	Renderer->CreateFrameAnimationCutTexture("cho_kawaiku2", FrameAnimation_DESC("cho_kawaiku.png", 1, 2, 0.5f, true));
	Renderer->CreateFrameAnimationCutTexture("cho_angel", FrameAnimation_DESC("cho_angel.png", 0, 1, 0.2f, false));
	Renderer->CreateFrameAnimationCutTexture("cho_angelEnd", FrameAnimation_DESC("cho_angel.png", 0, 0, 0.5f, false));
	Renderer->CreateFrameAnimationCutTexture("cho_teach", FrameAnimation_DESC("cho_teach.png", 0, 1, 0.5f, true));
	Renderer->CreateFrameAnimationCutTexture("cho_teachEnd", FrameAnimation_DESC("cho_teach.png", 0, 0, 0.5f, false));
	Renderer->CreateFrameAnimationCutTexture("pointing", FrameAnimation_DESC("cho_pointing.png", 0, 4, 0.5f,false));
	Renderer->CreateFrameAnimationCutTexture("ChoEnd", FrameAnimation_DESC("stream_cho_end.png", 0, 0, 0.5f, false));
	Renderer->CreateFrameAnimationCutTexture("ChoNyo", FrameAnimation_DESC("cho_nyo.png", 0, 0, 0.5f, false)); 
	Renderer->CreateFrameAnimationCutTexture("ChoSuperChat", FrameAnimation_DESC("cho_dokuzetsu_superchat.png", 0, 5, 0.15f, false));


	
	ContentsMap["Tutorial"] = StreamContents::Tutorial;
	Font = CreateComponent<Myfont>();
	Font->SetRenderingOrder(500);
}

void StreamAnimation::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Stream == false)
	{
		first = true;
		return;
	}
	else
	{
		if (first == true)
		{
			first = false;
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
