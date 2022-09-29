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
	// 25 올리면 됨
	GlobalContentsValue::LineNum = GlobalContentsValue::LineNum + 1;
	Tuuti = CreateComponent<GameEngineTextureRenderer>();
	Tuuti->SetTexture("tuuti.png");
	Tuuti->GetTransform().SetLocalScale(float4(140, 20));
	Tuuti->GetTransform().SetLocalPosition(float4(280, -230, -150));
	Tuuti->CreateFrameAnimationCutTexture("Tuuti", FrameAnimation_DESC("tuutidaytime.png", 0, 5, 0.08f, true));
	Tuuti->ChangeFrameAnimation("Tuuti");

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalScale(float4(140, 20));
	Collision->GetTransform().SetLocalPosition(float4(280, -230, 0));
	Collision->ChangeOrder(OBJECTORDER::UI);

	Line = CreateComponent<GameEngineTextureRenderer>();

	Font = CreateComponent<Myfont>();
	Font->SetRenderingOrder(500);
	Font->SetScreenPostion(float4(710.0f, 492.0f -25.0f));
	switch (GlobalContentsValue::DayTime)
	{
	case 1:
		Line->SetTexture("icon_watch_noon.png");
		Font->TextDraw("다음날로", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
		break;
	case 2:
		Line->SetTexture("icon_watch_evening.png");
		Font->TextDraw("저녁 시간대로", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
		break;
	case 3:
		Line->SetTexture("icon_watch_night.png");
		Font->TextDraw("밤 시간대로", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
		break;
	case 4:
		Line->SetTexture("icon_watch_night.png");
		Font->TextDraw("다음날로", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
		break;
	default:
		break;
	}

	Line->GetTransform().SetLocalPosition(float4(220, -230, -150));
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
		GlobalContentsValue::TextContents = "LineD";
		GlobalContentsValue::RemainLinenum = 1;
		if (GlobalContentsValue::DayTime == 4)
		{
			GlobalContentsValue::Day = GlobalContentsValue::Day + 1;
			GlobalContentsValue::DayTime = 1;	
		}
		Death();
	}
}

void NotificationDayTime::End()
{
}


