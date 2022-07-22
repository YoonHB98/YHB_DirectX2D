#include "PreCompile.h"
#include "Bar.h"

Bar::Bar()
{
}

Bar::~Bar()
{
}

void Bar::Start()
{
	Mental = CreateComponent<GameEngineTextureRenderer>();
	Mental->SetTexture("Color.png");
	Mental->GetTransform().SetLocalPosition(float4(343.5, 168.5 + 27 * (GlobalContentsValue::Mental) * 0.01 *0.5));
	Mental->GetTransform().SetLocalScale(float4(3, 27 * (GlobalContentsValue::Mental) * 0.01));
	
	Stress = CreateComponent<GameEngineTextureRenderer>();
	Stress->SetTexture("Color.png");
	Stress->GetTransform().SetLocalPosition(float4(343.5, 132.5 + 27 * (GlobalContentsValue::Stress) * 0.01 * 0.5));
	Stress->GetTransform().SetLocalScale(float4(3, 27 * (GlobalContentsValue::Stress) * 0.01));

	Affection = CreateComponent<GameEngineTextureRenderer>();
	Affection->SetTexture("Color.png");
	Affection->GetTransform().SetLocalPosition(float4(343.5, 97.5 + 27 * (GlobalContentsValue::Affection) * 0.01 * 0.5));
	Affection->GetTransform().SetLocalScale(float4(3, 27 * (GlobalContentsValue::Affection) * 0.01));
	Death(21.0f);
}

void Bar::Update(float _DeltaTime)
{
	time = time + GameEngineTime::GetDeltaTime();
	if (time > 1.0f)
	{
		Mental->GetTransform().SetLocalMove(float4(-3, 0));
		Stress->GetTransform().SetLocalMove(float4(-3, 0));
		Affection->GetTransform().SetLocalMove(float4(-3, 0));
		time = time - 1.0f;
	}

}

void Bar::End()
{
}
