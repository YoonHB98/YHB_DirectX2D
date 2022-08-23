#include "PreCompile.h"
#include "LineText.h"
#include "ToolTipText.h"
#include "LineMain.h"

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
			EmoticonON();
			time = 0;
		}
	}

	if (GlobalContentsValue::LineNum != 1)
	{
		Count = Count + 1;
		for (int i = 0; i < 30; i++)
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
		return;
	}
	else
	{
		ChangeZPos(std::stoi(LineMain::Inst_->LineMainCol->GetNameConstRef()) - 5 );
	}

	if (ChoiceTimeStart == true)
	{
		ChoiceTime = ChoiceTime + GameEngineTime::GetDeltaTime();
	}
	if (ChoiceTime > 1.5f)
	{
		ChoiceTime = 0;
		ChoiceTimeStart = false;
		ChoiceNum++;
		CreateChoice();
	}
	if (CheckStart)
	{
		Check();
	}
	if (ChangeStart == true)
	{
		ChangeTime = ChangeTime + GameEngineTime::GetDeltaTime();
		if (ChangeTime > 2.5f)
		{
			GlobalContentsValue::WebCamWindow = false;
			GlobalContentsValue::Line = false;
			GlobalContentsValue::Change = true;
			ChangeStart = false;
		}
	}
}

void LineText::End()
{
}

void LineText::CreateText(std::string _Text)
{
	if (_Text == "Tutorial9.png")
	{
		GlobalContentsValue::Tooltip = true;
		ToolTipText::Count = ToolTipText::Count + 1;
		ChoiceTimeStart = true;
	}
	if (_Text == "Tutorial17.png")
	{
		ChangeStart = true;
	}
	MyTextureRenderer* TextRend = CreateComponent<MyTextureRenderer>();
	TextRend->SetTexture( _Text);
	TextRend->ScaleToTexture();

	float SizeY = 0;
	SizeY = TextRend->GetTransform().GetLocalScale().y;

	TextRend->GetTransform().SetLocalPosition(float4(185,(75 - TextNum) - SizeY/2 ));
	Text.push_back(TextRend);
	MoveStart++;
	if (MoveStart >= 5)
	{
		if (TextNum > 180.0f)
		{
			TextMove(TextNum - 180,0);
			TextNum = 180.0f;
		}
		TextMove(SizeY + 3, 0);
	}
	else
	{
		TextNum = TextNum + SizeY + 3;
	}
}

void LineText::TextMove(float Y_, float last)
{

		std::vector<MyTextureRenderer*>::iterator StartIter = Text.begin();
		std::vector<MyTextureRenderer*>::iterator EndIter = Text.end();

		for (; StartIter != EndIter ; ++StartIter)
		{
			(*StartIter)->GetTransform().SetLocalMove(float4(0, Y_));
		}

}

void LineText::CreateChoice()
{
	ChoiceText = CreateComponent<MyTextureRenderer>();
	std::string Choice = "Choice" + std::to_string(ChoiceNum) + ".png";
	ChoiceText->SetTexture(Choice);
	ChoiceText->ScaleToTexture();
	ChoiceText->GetTransform().SetLocalPosition(float4(300, -170));

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalScale(float4(40, 10));
	Collision->GetTransform().SetLocalPosition(float4(320, -160, 0));
	Collision->ChangeOrder(OBJECTORDER::UI);

	Collision2 = CreateComponent<GameEngineCollision>();
	Collision2->GetTransform().SetLocalScale(float4(80, 10));
	Collision2->GetTransform().SetLocalPosition(float4(300, -185, 0));
	Collision2->ChangeOrder(OBJECTORDER::UI);
	CheckStart = true;
}

void LineText::Check()
{
	if (MouseCheck(Collision)
		&& true == GameEngineInput::GetInst()->IsDown("MouseClick"))
	{
		MyTextureRenderer* TextRend = CreateComponent<MyTextureRenderer>();
		float SizeY = 0;
		TextRend->SetTexture("Choice1_1.png");
		TextRend->ScaleToTexture();
		SizeY = TextRend->GetTransform().GetLocalScale().y;
		TextRend->GetTransform().SetLocalPosition(float4(320, 75 - TextNum - SizeY / 2));
		ChoiceText->GetTransform().SetLocalMove(float4(0, 0, 600));
		Text.push_back(TextRend);
		MoveStart++;
		TextMove(SizeY + 3, 0);
		GlobalContentsValue::RemainLinenum = 8;
		Collision->Off();
		Collision2->Off();
		GlobalContentsValue::Tooltip = false;
	}else
		if (MouseCheck(Collision2)
			&& true == GameEngineInput::GetInst()->IsDown("MouseClick"))
		{
			MyTextureRenderer* TextRend = CreateComponent<MyTextureRenderer>();
			float SizeY = 0;
			TextRend->SetTexture("Choice1_2.png");
			TextRend->ScaleToTexture();
			SizeY = TextRend->GetTransform().GetLocalScale().y;
			TextRend->GetTransform().SetLocalPosition(float4(320, 75 - TextNum - SizeY / 2));
			ChoiceText->GetTransform().SetLocalMove(float4(0, 0, 600));
			Text.push_back(TextRend);
			MoveStart++;
			TextMove(SizeY + 3, 0);
			GlobalContentsValue::RemainLinenum = 8;
			Collision->Off();
			Collision2->Off();
			GlobalContentsValue::Tooltip = false;
		}
}
