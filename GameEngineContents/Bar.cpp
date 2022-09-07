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

}

void Bar::Update(float _DeltaTime)
{
	BarMake();
	time = time + _DeltaTime;
	if (time > 1.0f
		&& StartCheck)
	{
		BarMove();
		time = time - 1.0f;

	}

}

void Bar::End()
{
}

void Bar::BarMake()
{
	BarTime = BarTime + GameEngineTime::GetDeltaTime();
if (time < -0.01f)
{
	time = 0.0f;
}
if (BarTime > 1.0f)
{
	BarTime = BarTime - 1.0f;
	if (GlobalContentsValue::Tutorial == false
		&& count != 23)
	{
		{		
			count++;
			CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
			Renderer->SetTexture("Color2.png");
			Renderer->GetTransform().SetLocalPosition(float4(343.5f, 97.5f + 27 * (GlobalContentsValue::Mental) * 0.01f * 0.5f,0));
			Renderer->GetTransform().SetLocalScale(float4(3.0f, 27.0f * (GlobalContentsValue::Mental) * 0.01f));
			Renderer->Clip.SizeX = 760.0f;
			MentalStack.push_back(Renderer);
		}

		{
			CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
			Renderer->SetTexture("Color2.png");
			Renderer->GetTransform().SetLocalPosition(float4(343.5f, 168.5f + 27.0f * static_cast<float>(GlobalContentsValue::Stress) * 0.01f * 0.5f,0.0f));
			Renderer->GetTransform().SetLocalScale(float4(3.0f, 27.0f * static_cast<float>(GlobalContentsValue::Stress) * 0.01f));
			Renderer->Clip.SizeX = 760.0f;
			StressStack.push_back(Renderer);
		}
		{
			CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
			Renderer->SetTexture("Color2.png");
			Renderer->GetTransform().SetLocalPosition(float4(343.5f, 132.5f + 27.0f * static_cast<float>(GlobalContentsValue::Affection) * 0.01f * 0.5f,0.0f));
			Renderer->GetTransform().SetLocalScale(float4(3.0f, 27.0f * static_cast<float>(GlobalContentsValue::Affection) * 0.01f));
			Renderer->Clip.SizeX = 760.0f;
			AffectionStack.push_back(Renderer);
		}
		StartCheck = true;
	}
}
}

void Bar::BarMove()
{
	std::vector<CommentTextureRenderer*>::iterator StartIter = MentalStack.begin();
	std::vector<CommentTextureRenderer*>::iterator EndIter = MentalStack.end();
	for (; StartIter != EndIter; ++StartIter)
	{
		(*StartIter)->GetTransform().SetLocalMove(float4(-3, 0, 0));
	}
	StartIter = MentalStack.begin() + BarCount;
	(*StartIter)->GetTransform().SetLocalPosition(float4(343.5f, 97.5f + 27.0f * static_cast<float>(GlobalContentsValue::Mental) * 0.01f * 0.5f, 0.0f));
	(*StartIter)->GetTransform().SetLocalScale(float4(3.0f, 27.0f * static_cast<float>(GlobalContentsValue::Mental) * 0.01f));

	StartIter = StressStack.begin();
	EndIter = StressStack.end();
	for (; StartIter != EndIter; ++StartIter)
	{
		(*StartIter)->GetTransform().SetLocalMove(float4(-3, 0, 0));
	}
	StartIter = StressStack.begin() + BarCount;
	(*StartIter)->GetTransform().SetLocalPosition(float4(343.5f, 168.5f + 27.0f * static_cast<float>(GlobalContentsValue::Stress) * 0.01f * 0.5f, 0.0f));
	(*StartIter)->GetTransform().SetLocalScale(float4(3.0f, 27.0f * static_cast<float>(GlobalContentsValue::Stress) * 0.01f));

	StartIter = AffectionStack.begin();
	EndIter = AffectionStack.end();
	for (; StartIter != EndIter; ++StartIter)
	{
		(*StartIter)->GetTransform().SetLocalMove(float4(-3, 0, 0));
	}
	StartIter = AffectionStack.begin() + BarCount;
	(*StartIter)->GetTransform().SetLocalPosition(float4(343.5f, 132.5f + 27.0f * static_cast<float>(GlobalContentsValue::Affection) * 0.01f * 0.5f, 0.0f));
	(*StartIter)->GetTransform().SetLocalScale(float4(3.0f, 27.0f * static_cast<float>(GlobalContentsValue::Affection) * 0.01f));



	//97.5 132.5 168.5

	BarCount = BarCount + 1;
	if (BarCount == 23)
	{
		BarCount = 0;
	}
}
