#include "PreCompile.h"
#include "WebCamWindow.h"

WebCamWindow* WebCamWindow::Inst_ = new WebCamWindow();

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
	Ame->CreateFrameAnimationCutTexture("ame_talk1", FrameAnimation_DESC("ame_talk1.png", 0, 4, 0.4f,true));
	Ame->CreateFrameAnimationCutTexture("ame_out0", FrameAnimation_DESC("ame_out0.png", 0, 13, 0.15f, false));

	StateManager.CreateStateMember("Idle", std::bind(&WebCamWindow::IdleUpdate, this, std::placeholders::_1, std::placeholders::_2), std::bind(&WebCamWindow::IdleStart, this, std::placeholders::_1));
	StateManager.CreateStateMember("Active", std::bind(&WebCamWindow::ActiveUpdate, this, std::placeholders::_1, std::placeholders::_2), std::bind(&WebCamWindow::ActiveStart, this, std::placeholders::_1));
	StateManager.ChangeState("Idle");

	Inst_->WebCamMainCol = CreateComponent<GameEngineCollision>();
	Inst_->WebCamMainCol->GetTransform().SetLocalPosition(float4(-90, 120));
	Inst_->WebCamMainCol->GetTransform().SetLocalScale(float4(358, 254,5));
	Inst_->WebCamMainCol->ChangeOrder(OBJECTORDER::Window);
	Mouse::Inst_->ChangeNameAll();
	Inst_->WebCamMainCol->SetName("-90");

	SetName("WebCamWindow");
	ChangeZPos(0);
}

void WebCamWindow::Update(float _DeltaTime)
{
	if (GlobalContentsValue::BgmOn
		&& GlobalContentsValue::WebCamWindow == true)
	{
		BgmPlayer = GameEngineSound::SoundPlayControl("mainloop_normal.wav");
		GlobalContentsValue::BgmOn = false;
	}
	if (GlobalContentsValue::WebCamWindow == false)
	{
		ChangeZPos(500);
	}
	else
	{
		BgmPlayer.UnPaused();
			int A = std::stoi(Inst_->WebCamMainCol->GetNameConstRef());
			ChangeZPos(std::stoi(Inst_->WebCamMainCol->GetNameConstRef()));
	}

	if (GlobalContentsValue::Change ==true)
	{
		if (Stop == false)
		{
			ChangeZPos(500);
			BgmPlayer.Paused();
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
