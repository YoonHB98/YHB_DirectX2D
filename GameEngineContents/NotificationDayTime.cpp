#include "PreCompile.h"
#include "NotificationDayTime.h"

NotificationDayTime::NotificationDayTime()
{
}

NotificationDayTime::~NotificationDayTime()
{
}

void NotificationDayTime::Start()
{
	// 25 ¿Ã¸®¸é µÊ
	GlobalContentsValue::LineNum = GlobalContentsValue::LineNum + 1;
	Tuuti = CreateComponent<GameEngineTextureRenderer>();
	Tuuti->SetTexture("tuuti.png");
	Tuuti->GetTransform().SetLocalScale(float4(140, 20));
	Tuuti->GetTransform().SetLocalPosition(float4(280, -230, 0));
	Tuuti->CreateFrameAnimationCutTexture("Tuuti", FrameAnimation_DESC("tuutidaytime.png", 0, 5, 0.08f, true));
	Tuuti->ChangeFrameAnimation("Tuuti");

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalScale(float4(140, 20));
	Collision->GetTransform().SetLocalPosition(float4(280, -230, 0));
	Collision->ChangeOrder(OBJECTORDER::UI);

	Line = CreateComponent<GameEngineTextureRenderer>();
	switch (GlobalContentsValue::DayTime)
	{
	case 1:
		Line->SetTexture("icon_watch_noon.png");
		break;
	case 2:
		Line->SetTexture("icon_watch_evening.png");
		break;
	case 3:
		Line->SetTexture("icon_watch_night.png");
		break;
	default:
		break;
	}

	Line->GetTransform().SetLocalPosition(float4(220, -230, 0));
	Line->GetTransform().SetLocalScale(float4(14, 14, 1));

	ChangeZPos(-10);
}

void NotificationDayTime::Update(float _DeltaTime)
{

	if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
		&& MouseCheck(Collision))
	{
		GlobalContentsValue::Line = false;
		GlobalContentsValue::Twitter = false;
		Death();
	}
}

void NotificationDayTime::End()
{
}


