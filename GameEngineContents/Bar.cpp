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
	Mental->GetTransform().SetLocalPosition(float4(343.5f, 168.5f+ 27 * (GlobalContentsValue::Mental) * 0.01f *0.5f,49));
	Mental->GetTransform().SetLocalScale(float4(3.0f, 27.0f * (GlobalContentsValue::Mental) * 0.01f));
	
	Stress = CreateComponent<GameEngineTextureRenderer>();
	Stress->SetTexture("Color.png");
	Stress->GetTransform().SetLocalPosition(float4(343.5f, 132.5f+ 27 * (GlobalContentsValue::Stress) * 0.01f * 0.5f, 49.0f));
	Stress->GetTransform().SetLocalScale(float4(3, 27 * (GlobalContentsValue::Stress) * 0.01f));

	Affection = CreateComponent<GameEngineTextureRenderer>();
	Affection->SetTexture("Color.png");
	Affection->GetTransform().SetLocalPosition(float4(343.5f, 97.5f + 27 * (GlobalContentsValue::Affection) * 0.01f * 0.5f, 49));
	Affection->GetTransform().SetLocalScale(float4(3, 27 * (GlobalContentsValue::Affection) * 0.01f));
}

void Bar::Update(float _DeltaTime)
{
	time = time + GameEngineTime::GetDeltaTime();
	if (count == 20)
	{ 
		time2 = time2 + GameEngineTime::GetDeltaTime();
		if (time2 > 1.0f)
		{
			Off();
		}
	
	}
	if (time > 1.0f
		&& count != 20)
	{
		Mental->GetTransform().SetLocalMove(float4(-3, 0, 0));
		Stress->GetTransform().SetLocalMove(float4(-3, 0, 0));
		Affection->GetTransform().SetLocalMove(float4(-3, 0, 0));
		time = time - 1.0f;
		count++;
	}

}

void Bar::End()
{
}
