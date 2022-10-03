#include "PreCompile.h"
#include "BadEndEndWindow.h"

BadEndEndWindow::BadEndEndWindow() 
{
}

BadEndEndWindow::~BadEndEndWindow() 
{
}

void BadEndEndWindow::Start()
{

	SetTexture("BadEndEnd.png");
	SetLocalPosition(float4(0, 0, -200));
	SetLocalScale(float4(297, 195));

	MainCol = CreateComponent<GameEngineCollision>();
	MainCol->GetTransform().SetLocalPosition(float4(-5, -70));
	MainCol->GetTransform().SetLocalScale(float4(100, 20, 500));
	MainCol->ChangeOrder(OBJECTORDER::Window);

	GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture("BackGroundColor.png");
	Renderer->GetTransform().SetLocalScale(float4(297, 2));
	Renderer->GetTransform().SetLocalPosition(float4(1, -97, -200));
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("BackGroundColor.png");
		Renderer->GetTransform().SetLocalScale(float4(2, 190));
		Renderer->GetTransform().SetLocalPosition(float4(147.8f, -2, -200));
	}
}

void BadEndEndWindow::Update(float _DeltaTime)
{
	if (MouseCheck(MainCol)
		&& true == GameEngineInput::GetInst()->IsDown("MouseClick"))
	{
		GlobalContentsValue::BgmOn = true;
		GlobalContentsValue::Stream = false;
		GlobalContentsValue::ChangeTime = 0.0f;
		GlobalContentsValue::BgmName = "mainloop_kenjo.wav";
		GlobalContentsValue::TextContents = "LineD";
		GlobalContentsValue::Twitter = false;
		GlobalContentsValue::Tooltip = false;
		GlobalContentsValue::BadEnd = false;
		Death();
	}
}

void BadEndEndWindow::End()
{
}