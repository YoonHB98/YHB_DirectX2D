#include "PreCompile.h"
#include "StreamAnimation.h"

StreamAnimation::StreamAnimation() 
{
}

StreamAnimation::~StreamAnimation() 
{
}

void StreamAnimation::Start()
{
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->GetTransform().SetLocalPosition(float4(-120, 40, 0));
	Renderer->GetTransform().SetLocalScale(float4(348, 227));
	Renderer->CreateFrameAnimationCutTexture("cho_kashikoma", FrameAnimation_DESC("cho_kashikoma.png", 0, 7, 0.15f, false));
	std::vector<unsigned int> End { 0, 2 };
	Renderer->CreateFrameAnimationCutTexture("cho_idle", FrameAnimation_DESC("cho_idle.png", 0, 2, 0.5f, false));
	Renderer->CreateFrameAnimationCutTexture("cho_idleEnd", FrameAnimation_DESC("cho_idle.png", End, 0.5f, false));
	Renderer->CreateFrameAnimationCutTexture("cho_kawaiku", FrameAnimation_DESC("cho_kawaiku.png", 0, 2, 0.5f, false));
	Renderer->CreateFrameAnimationCutTexture("cho_pointing", FrameAnimation_DESC("cho_pointing.png", 0, 4, 0.5f, false));

	
	ContentsMap["Tutorial"] = StreamContents::Tutorial;
	Font = CreateComponent<Myfont>();
}

void StreamAnimation::Update(float _DeltaTime)
{
	TextDrawTime("æ»≥Á«œººø‰", "Galmuri11", float4(100, 100), float4(1, 0, 0, 1), 80.0f, 3.0f);
	GlobalContentsValue::Stream = true;
	if (GlobalContentsValue::Stream == false)
	{
		ChangeZPos(500);
		first = true;
		return;
	}
	else
	{
		if (first == true)
		{
			first = false;
			ChangeZPos(-510);
		}
		Contents = ContentsMap[GlobalContentsValue::Contents];
		ContentsUpdate(Contents);
	}
	//TempTime = TempTime + GameEngineTime::GetDeltaTime();
	//if (TempTime > 0.5f)
	//{
	//	TempTime = TempTime - 0.5f;
	//	std::string AABB = "æ»≥Á«œººø‰";
	//	std::string BBBB = "";

	//	
	//	if (TempCount == 0)
	//	{
	//		Myfont* Font = CreateComponent<Myfont>();
	//		Font->TextDrawTime("æ»≥Á«œººø‰", "Galmuri11", float4(100, 100), float4(1, 0, 0, 1), 80.0f,3.0f);
	//		Font->TextDraw(BBBB + AABB[0] + AABB[1], "Galmuri11", float4(100, 100), float4(1, 0, 0, 1), 80.0f);
	//		TempCount++;
	//	}else
	//	if (TempCount == 1)
	//	{
	//		Myfont* Font = CreateComponent<Myfont>();
	//		Font->TextDraw("æ»≥Á", "Galmuri11", float4(100, 100), float4(1, 0, 0, 1), 80.0f);
	//		TempCount++;
	//	}else
	//	if (TempCount == 2)
	//	{
	//		Myfont* Font = CreateComponent<Myfont>();
	//		Font->TextDraw("æ»≥Á«œ", "Galmuri11", float4(100, 100), float4(1, 0, 0, 1), 80.0f);
	//		TempCount++;
	//	}else
	//	if (TempCount == 3)
	//	{
	//		Myfont* Font = CreateComponent<Myfont>();
	//		Font->TextDraw("æ»≥Á«œºº", "Galmuri11", float4(100, 100), float4(1, 0, 0, 1), 80.0f);
	//		TempCount++;
	//	}else
	//	if (TempCount == 4)
	//	{
	//		Myfont* Font = CreateComponent<Myfont>();
	//		Font->TextDraw("æ»≥Á«œººø‰", "Galmuri11", float4(100, 100), float4(1, 0, 0, 1), 80.0f);
	//		TempCount++;
	//	}
	//	
	//}

}

void StreamAnimation::End()
{
}

void StreamAnimation::ContentsUpdate(StreamContents Contents)
{
	switch (Contents)
	{
	case StreamContents::Tutorial:
		Tutorial();
		break;
	default:
		break;
	}
}
