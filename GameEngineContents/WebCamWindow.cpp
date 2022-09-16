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

	ClickCol = CreateComponent<GameEngineCollision>();
	ClickCol->GetTransform().SetLocalPosition(float4(-90, 165, 5000));
	ClickCol->GetTransform().SetLocalScale(float4(120, 60));
	ClickCol->ChangeOrder(OBJECTORDER::Click);
	ClickCol->SetName("Click");

	BGNC = CreateComponent<GameEngineTextureRenderer>();
	BGNC->SetTexture("bg_stream_no_chair.png");
	BGNC->GetTransform().SetLocalPosition(float4(-91, 115));
	BGNC->GetTransform().SetLocalScale(float4(348, 222));

	Ame = CreateComponent<GameEngineTextureRenderer>();
	Ame->GetTransform().SetLocalPosition(float4(-90, 115));
	Ame->GetTransform().SetLocalScale(float4(348, 222));
	Ame->CreateFrameAnimationCutTexture("ame_talk1", FrameAnimation_DESC("ame_talk1.png", 0, 4, 0.4f,true));
	Ame->CreateFrameAnimationCutTexture("ame_out0", FrameAnimation_DESC("ame_out0.png", 0, 13, 0.15f, false));
	Ame->CreateFrameAnimationCutTexture("ame_idle_happy3", FrameAnimation_DESC("ame_idle_happy3.png", 0, 8, 0.2f, true));
	Ame->CreateFrameAnimationCutTexture("ame_idle_happy6", FrameAnimation_DESC("ame_idle_happy6.png", 0, 5, 0.2f, true));

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
	if (GlobalContentsValue::WebCamWindow == true
		&&BgmOn)
	{
		BgmOn = false;
		GlobalContentsValue::BgmOn = true;
		GlobalContentsValue::BgmName = "mainloop_kenjo.wav";
	}
	if (GlobalContentsValue::WebCamWindow == false)
	{
		ChangeZPos(500);
	}
	else
	{
			int A = std::stoi(Inst_->WebCamMainCol->GetNameConstRef());
			ChangeZPos(static_cast<float>(std::stoi(Inst_->WebCamMainCol->GetNameConstRef())));
	}

	if (GlobalContentsValue::Change ==true)
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
	std::string numbers[5]{ "GameStart", "CommunicationStart", "ThatStart" };
	if (GlobalContentsValue::Out == true)
	{
		Ame->ChangeFrameAnimation("ame_out0");
		StateManager.ChangeState("Active");
	}
	for (int i = 0; i <3 ; i++)
	{
		if (GlobalContentsValue::Asobu_Window == numbers[i]
			&& GlobalContentsValue::Asobu == false)
		{
			Ame->ChangeFrameAnimation("ame_idle_happy3");
			StateManager.ChangeState("Active");
		}
	}

}

void WebCamWindow::ActiveStart(const StateInfo& _Info)
{

}

void WebCamWindow::ActiveUpdate(float _DeltaTime, const StateInfo& _Info)
{
	if (GlobalContentsValue::Asobu_Window == "CommunicationStart")
	{
		ClickCol->GetTransform().SetLocalPosition(float4(-91, 165, -100));
		if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
		{
			if (ClickCol->IsCollision(CollisionType::CT_OBB, OBJECTORDER::Mouse, CollisionType::CT_OBB))
			{
				Ame->ChangeFrameAnimation("ame_idle_happy6");
			}
		}
	
	}
}

