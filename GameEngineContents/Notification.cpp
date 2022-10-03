#include "PreCompile.h"
#include "Notification.h"
#include "LineMain.h"

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
	Tuuti->GetTransform().SetLocalPosition(float4(280, -255, -30));

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalScale(float4(140, 20));
	Collision->GetTransform().SetLocalPosition(float4(280, -255, -30));
	Collision->ChangeOrder(OBJECTORDER::UI);

	Line = CreateComponent<GameEngineTextureRenderer>();
	Line->SetTexture("Line.png");
	Line->GetTransform().SetLocalPosition(float4(220, -255, -30));
	Line->ScaleToTexture();

	GameEngineSound().SoundPlayOneShot("jine_recieve.wav");
	ChangeZPos(-10);
}

void Notification::Update(float _DeltaTime)
{
	
	if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
		&& MouseCheck(Collision))
	{
		GlobalContentsValue::Line = true;
		Mouse::Inst_->ChangeNameAll();
		LineMain::Inst_->LineMainCol->SetName("-100");
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


