#include "PreCompile.h"
#include "Stream.h"
#include "StreamAnimation.h"
#include "PlayLevel.h"

Stream::Stream() 
{
}

Stream::~Stream() 
{
}

void Stream::Start()
{
	SetTexture("Stream.png");
	SetLocalPosition(float4(0, 0));
	Renderer->ScaleToTexture();

	Haisin = CreateComponent<GameEngineTextureRenderer>();
	Haisin->SetTexture("Haisin.png");
	Haisin->GetTransform().SetLocalPosition(float4(0,-5));
	Haisin->GetTransform().SetLocalScale(float4(662, 440));
	
}

void Stream::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Stream
		&&first)
	{
		ChangeZPos(40);
		first = false;
		BgmPlayer = GameEngineSound::SoundPlayControl("mainloop_kenjo.wav", 999);
	}
	if (GlobalContentsValue::ChangeTime > 200.0f)
	{
		BgmPlayer.Stop();
	}
	if (GlobalContentsValue::Stream == false)
	{
		ChangeZPos(500);

	}
}

void Stream::End()
{
}