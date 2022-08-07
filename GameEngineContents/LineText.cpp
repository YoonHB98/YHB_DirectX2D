#include "PreCompile.h"
#include "LineText.h"

LineText::LineText() 
{
}

LineText::~LineText() 
{
}

void LineText::Start()
{

	ChangeZPos(-50);
}

void LineText::Update(float _DeltaTime)
{
	if (Count >= 5)
	{
		time = time + _DeltaTime;
		if (time > 1.5f)
		{
			GlobalContentsValue::Change = true;
			GlobalContentsValue::Line = false;
			GlobalContentsValue::WebCamWindow = false;
			Count = 0;
		}

	}
	if (GlobalContentsValue::LineNum != 1
		&& GlobalContentsValue::WebCamWindow == true)
	{
		Count = Count + 1;
		if (Count == 1)
		{
			Renderer1 = CreateComponent<GameEngineTextureRenderer>();
			Renderer1->SetTexture("Sample1.png");
			Renderer1->ScaleToTexture();
			Renderer1->GetTransform().SetLocalPosition(float4(200, 30));
		}else
		if (Count == 2)
			{
				Renderer2 = CreateComponent<GameEngineTextureRenderer>();
				Renderer2->SetTexture("Sample2.png");
				Renderer2->ScaleToTexture();
				Renderer2->GetTransform().SetLocalPosition(float4(200, -25));
		}else
		if (Count == 3)
			{
			Renderer3 = CreateComponent<GameEngineTextureRenderer>();
			Renderer3->SetTexture("Sample3.png");
			Renderer3->ScaleToTexture();
			Renderer3->GetTransform().SetLocalPosition(float4(200, -55));
			}
			else
			if (Count == 4)
			{
				Renderer4 = CreateComponent<GameEngineTextureRenderer>();
				Renderer4->SetTexture("Sample4.png");
				Renderer4->ScaleToTexture();
				Renderer4->GetTransform().SetLocalPosition(float4(200, -85));
			}
				else
				if (Count == 5)
				{
					Renderer5 = CreateComponent<GameEngineTextureRenderer>();
					Renderer5->SetTexture("Sample5.png");
					Renderer5->ScaleToTexture();
					Renderer5->GetTransform().SetLocalPosition(float4(200, -115));
				}
	}
	if (GlobalContentsValue::Line == false)
	{
		ChangeZPos(500);
	}
	else
	{
		ChangeZPos(40);
	}

}

void LineText::End()
{
}

void LineText::CreateText(std::string)
{
	GameEngineTextureRenderer* TextRend = CreateComponent<GameEngineTextureRenderer>();
	TextRend->SetTexture("Sample1.png");
	TextRend->ScaleToTexture();
	TextRend->GetTransform().SetLocalPosition(float4(200, 30));
	Text.push_back(TextRend);
}
