#include "PreCompile.h"
#include "WebCamWindow.h"

WebCamWindow::WebCamWindow()
{
}

WebCamWindow::~WebCamWindow()
{
}

void WebCamWindow::Start()
{
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture("WebCam.png");
	Renderer->GetTransform().SetLocalPosition(float4(-90, 120));
	Renderer->GetTransform().SetLocalScale(float4(358,254));

	BG = CreateComponent<GameEngineTextureRenderer>();
	BG->SetTexture("bg_stream.png");
	BG->GetTransform().SetLocalPosition(float4(-91, 115));
	BG->GetTransform().SetLocalScale(float4(348, 222));

	BGNC = CreateComponent<GameEngineTextureRenderer>();
	BGNC->SetTexture("bg_stream_no_chair.png");
	BGNC->GetTransform().SetLocalPosition(float4(-91, 115));
	BGNC->GetTransform().SetLocalScale(float4(348, 222));

	Ame = CreateComponent<GameEngineTextureRenderer>();
	Ame->GetTransform().SetLocalPosition(float4(-90, 115));
	Ame->GetTransform().SetLocalScale(float4(348, 222));
	Ame->CreateFrameAnimation("ame_talk1", FrameAnimation_DESC("ame_talk1.png", 0, 4, 0.4f,true));
	Ame->CreateFrameAnimation("ame_out0", FrameAnimation_DESC("ame_out0.png", 0, 13, 0.15f, false));

	StateManager.CreateStateMember("Idle", this, &WebCamWindow::IdleUpdate, &WebCamWindow::IdleStart);
	StateManager.CreateStateMember("Active", this, &WebCamWindow::ActiveUpdate, &WebCamWindow::ActiveStart);
	StateManager.ChangeState("Idle");

	ChangeZPos(-50);
}

void WebCamWindow::Update(float _DeltaTime)
{
	if (GlobalContentsValue::WebCamWindow == false)
	{
		ChangeZPos(500);
	}
	else
	{
		ChangeZPos(-50);
	}

	if (GlobalContentsValue::Stream ==true)
	{
		if (Stop == false)
		{
			ChangeZPos(500);
		}

		Stop = true;

		return;
	}
	Stop = false;
	StateManager.Update(_DeltaTime);

}

void WebCamWindow::End()
{
}

void WebCamWindow::IdleStart(const StateInfo& _Info)
{
	Ame->ChangeFrameAnimation("ame_talk1");
	Ame->GetTransform().SetLocalPosition(float4(-90, 115));
	Ame->GetTransform().SetLocalScale(float4(348, 222));
}

void WebCamWindow::IdleUpdate(float _DeltaTime, const StateInfo& _Info)
{
	if (GlobalContentsValue::Out == true)
	{
		Ame->ChangeFrameAnimation("ame_out0");
		StateManager.ChangeState("Active");
	}
}

void WebCamWindow::ActiveStart(const StateInfo& _Info)
{

}

void WebCamWindow::ActiveUpdate(float _DeltaTime, const StateInfo& _Info)
{
}
