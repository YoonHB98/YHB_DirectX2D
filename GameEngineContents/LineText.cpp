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
	if (Tutorial == false
		&&Count == 2
		&&GlobalContentsValue::Line)
	{
		time = time + GameEngineTime::GetDeltaTime();
		if (time >= 1.0f)
		{
			GlobalContentsValue::Tooltip = true;
			Tutorial = true;
			time = 0;
		}
	}
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
	if (GlobalContentsValue::LineNum != 1)
	{
		Count = Count + 1;
		for (int i = 0; i < 10; i++)
		{
			if (Count == i)
			{
				CreateText(GlobalContentsValue::TextContents + std::to_string(i) + ".png");
			}
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

void LineText::CreateText(std::string _Text)
{

	GameEngineTextureRenderer* TextRend = CreateComponent<GameEngineTextureRenderer>();
	TextRend->SetTexture( _Text);
	TextRend->ScaleToTexture();
	if (TextRend->GetTransform().GetLocalScale().y > 30)
	{
		TextNum = TextNum + 50;
	}
	TextNum = TextNum + 35;
	TextRend->GetTransform().SetLocalPosition(float4(185, 85 - TextNum));
	Text.push_back(TextRend);
}
