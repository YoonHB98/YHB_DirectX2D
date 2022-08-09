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

	if (GlobalContentsValue::LineNum != 1)
	{
		Count = Count + 1;
		for (int i = 0; i < 20; i++)
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
}

void LineText::End()
{
}

void LineText::CreateText(std::string _Text)
{
	if (_Text == "Tutorial9.png")
	{
		ChoiceTimeStart = true;
	}
	MyTextureRenderer* TextRend = CreateComponent<MyTextureRenderer>();
	TextRend->SetTexture( _Text);
	TextRend->ScaleToTexture();

	if (TextRend->GetTransform().GetLocalScale().y > 75)
	{
		TextNum = TextNum + 41;
	}
	else
		if (TextRend->GetTransform().GetLocalScale().y > 30)
		{
			TextNum = TextNum + 25;
		}
		else
		{
			TextNum = TextNum + 17;
		}

	TextRend->GetTransform().SetLocalPosition(float4(185,75 - TextNum));
	if (TextRend->GetTransform().GetLocalScale().y > 75)
	{
		TextNum = TextNum + 41;
	}
	else
		if (TextRend->GetTransform().GetLocalScale().y > 30)
		{
			TextNum = TextNum + 25;
		}
		else
		{
			TextNum = TextNum + 17;
		}
	Text.push_back(TextRend);
	MoveStart++;
	if (MoveStart >= 5)
	{
		if (TextRend->GetTransform().GetLocalScale().y > 75)
		{
			Move = Move + 82;
			TextMove(82,Move);
		}
		else
			if (TextRend->GetTransform().GetLocalScale().y > 30)
			{
				Move = Move + 50;
				TextMove(50,Move);
			}
			else
			{
				Move = Move + 34;
				TextMove(34,Move);
			}
	}
}

void LineText::TextMove(float Y_, float last)
{

		std::vector<MyTextureRenderer*>::iterator StartIter = Text.begin();
		std::vector<MyTextureRenderer*>::iterator EndIter = Text.end();

		for (; StartIter != EndIter - 1; ++StartIter)
		{
			(*StartIter)->GetTransform().SetLocalMove(float4(0, Y_));
		}
		(StartIter) = EndIter - 1; 
		(*StartIter)->GetTransform().SetLocalMove(float4(0, last));
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
		TextNum = TextNum + 17;
		MyTextureRenderer* TextRend = CreateComponent<MyTextureRenderer>();
		TextRend->SetTexture("Choice1_1.png");
		TextRend->ScaleToTexture();
		TextRend->GetTransform().SetLocalPosition(float4(320, 75 - TextNum));
		ChoiceText->GetTransform().SetLocalMove(float4(0, 0, 600));
		Text.push_back(TextRend);
		MoveStart++;
		Move = Move + 34;
		TextMove(34, Move);
		GlobalContentsValue::RemainLinenum = 8;
		Collision->Off();
		Collision2->Off();
	}else
		if (MouseCheck(Collision2)
			&& true == GameEngineInput::GetInst()->IsDown("MouseClick"))
		{
			TextNum = TextNum + 17;
			MyTextureRenderer* TextRend = CreateComponent<MyTextureRenderer>();
			TextRend->SetTexture("Choice1_2.png");
			TextRend->ScaleToTexture();
			TextRend->GetTransform().SetLocalPosition(float4(320, 75 - TextNum));
			ChoiceText->GetTransform().SetLocalMove(float4(0, 0, 600));
			Text.push_back(TextRend);
			MoveStart++;
			Move = Move + 34;
			TextMove(34, Move);
			GlobalContentsValue::RemainLinenum = 8;
			Collision->Off();
			Collision2->Off();
		}
}
