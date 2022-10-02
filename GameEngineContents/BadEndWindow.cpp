#include "PreCompile.h"
#include "BadEndWindow.h"
#include "NotificationDayTime.h"

BadEndWindow::BadEndWindow()
{
}

BadEndWindow::~BadEndWindow()
{
}

void BadEndWindow::Start()
{

		SetTexture("BadEndOk.png");
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

void BadEndWindow::Update(float _DeltaTime)
{
	if (MouseCheck(MainCol)
		&& true == GameEngineInput::GetInst()->IsDown("MouseClick"))
	{
		GlobalContentsValue::BadEndChange = true;
		Death();
	}
}

void BadEndWindow::End()
{
}