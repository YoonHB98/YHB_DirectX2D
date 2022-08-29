#include "PreCompile.h"
#include "Notification.h"

Notification::Notification()
{
}

Notification::~Notification()
{
}

void Notification::Start()
{
	// 25 ¿Ã¸®¸é µÊ
	GlobalContentsValue::LineNum = GlobalContentsValue::LineNum + 1;
	Tuuti = CreateComponent<GameEngineTextureRenderer>();
	Tuuti->SetTexture("tuuti.png");
	Tuuti->GetTransform().SetLocalScale(float4(140, 20));
	Tuuti->GetTransform().SetLocalPosition(float4(280, -255, 0));

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalScale(float4(140, 20));
	Collision->GetTransform().SetLocalPosition(float4(280, -255, 0));
	Collision->ChangeOrder(OBJECTORDER::UI);

	Line = CreateComponent<GameEngineTextureRenderer>();
	Line->SetTexture("Line.png");
	Line->GetTransform().SetLocalPosition(float4(220, -255, 0));
	Line->ScaleToTexture();

	GameEngineSound().SoundPlayOneShot("jine_recieve.wav");
}

void Notification::Update(float _DeltaTime)
{
	
	if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
		&& MouseCheck(Collision))
	{
		GlobalContentsValue::Line = true;
		GlobalContentsValue::EomticonStatus = 2;
		//GlobalContentsValue::WebCamWindow = true;
	}
	if (GlobalContentsValue::LineNum != 1)
	{
		GetTransform().SetWorldMove(float4(0, 25));
	}
	if (GlobalContentsValue::Line)
	{
		Off();
	}
}

void Notification::End()
{
}


