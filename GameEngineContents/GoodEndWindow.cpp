#include "PreCompile.h"
#include "GoodEndWindow.h"
#include "NotificationDayTime.h"

GoodEndWindow::GoodEndWindow()
{
}

GoodEndWindow::~GoodEndWindow()
{
}

void GoodEndWindow::Start()
{

	SetTexture("GoodEndOk.png");
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

void GoodEndWindow::Update(float _DeltaTime)
{
	if (MouseCheck(MainCol)
		&& true == GameEngineInput::GetInst()->IsDown("MouseClick")
		&& GlobalContentsValue::GameEnd == false)
	{
		SetTexture("Ending.png");
		SetLocalPosition(float4(0, 0, -400));
		SetLocalScale(float4(960, 540));
		GlobalContentsValue::BgmOn = true;
		GlobalContentsValue::BgmName = "InternetOverdose.wav";
		GlobalContentsValue::GameEnd = true;
	}
}

void GoodEndWindow::End()
{
}