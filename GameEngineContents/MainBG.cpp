#include "PreCompile.h"
#include "MainBG.h"

MainBG::MainBG()
{
}

MainBG::~MainBG()
{
}

void MainBG::Start()
{
	MiddleBG = CreateComponent<GameEngineTextureRenderer>();
	MiddleBG->SetTexture("bg_main.png");
	MiddleBG->GetTransform().SetLocalScale(float4(718,540,-1));

	Day = CreateComponent<CommentTextureRenderer>();
	Day->SetTexture("Day1.png");
	Day->GetTransform().SetLocalScale(float4(33, 20, 1));
	Day->GetTransform().SetLocalPosition(float4(330,-259.5, -1));

	Day->Color.PosX = 103.0f / 255.0f;
	Day->Color.PosY = 85.0f / 255.0f;
	Day->Color.SizeX = 187.0f / 255.0f;

	DayTime = CreateComponent<CommentTextureRenderer>();
	DayTime->SetTexture("icon_watch_noon.png");
	DayTime->GetTransform().SetLocalScale(float4(13, 13, 1));
	DayTime->GetTransform().SetLocalPosition(float4(300, -259.5, -1));
}

void MainBG::Update(float _DeltaTime)
{
	Day->SetTexture("Day" + std::to_string(GlobalContentsValue::Day) + ".png");
	switch (GlobalContentsValue::DayTime)
	{
	case 1:
		DayTime->SetTexture("icon_watch_noon.png");
		break;
	case 2:
		DayTime->SetTexture("icon_watch_evening.png");
		break;
	case 3:
		DayTime->SetTexture("icon_watch_night.png");
		break;
	default:
		break;
	}
}

void MainBG::End()
{
}
