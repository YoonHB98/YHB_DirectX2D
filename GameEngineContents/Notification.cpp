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
	Tuuti->GetTransform().SetLocalPosition(float4(280, -255));

	Line = CreateComponent<GameEngineTextureRenderer>();
	Line->SetTexture("Line.png");
	Line->GetTransform().SetLocalPosition(float4(220, -255));
	Line->ScaleToTexture();

	GameEngineSound().SoundPlayOneShot("jine_recieve.wav");
}

void Notification::Update(float _DeltaTime)
{

	if (GlobalContentsValue::LineNum != 1)
	{
		Tuuti->GetTransform().SetLocalMove(float4(0,25));
		Line->GetTransform().SetLocalMove(float4(0, 25));

	}
	if (GlobalContentsValue::LineNum == 0)
	{
		Death();
	}

}

void Notification::End()
{
}
