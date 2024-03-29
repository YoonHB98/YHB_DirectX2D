#include "PreCompile.h"
#include <GameEngineBase/GameEngineRandom.h>
#include "LineText.h"
#include "ToolTipText.h"
#include "LineMain.h"
#include "Sojae.h"

int LineText::DCount = 1;
LineText::LineText() 
{
}

LineText::~LineText() 
{
}

void LineText::Start()
{
	ChangeZPos(-5);
}

void LineText::Update(float _DeltaTime)
{
	if (GlobalContentsValue::TextContents != CurTextCon)
	{
		CurTextCon = GlobalContentsValue::TextContents;
		Count = 0;
	}
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
	EmoticonCheck();
	if (GlobalContentsValue::LineNum != 1)
	{
		if (CurTime != GlobalContentsValue::DayTime
			&&(GlobalContentsValue::LineDate == true))
		{
			CurTime = GlobalContentsValue::DayTime;
			GlobalContentsValue::LineDate = false;
			CreateDayTime();
		}else
			if (CurTime != GlobalContentsValue::DayTime && (GlobalContentsValue::Contents == "Tutorial"))
			{
			CurTime = GlobalContentsValue::DayTime;
			CreateDayTime();
			}else
				if (CurTime != GlobalContentsValue::DayTime && (GlobalContentsValue::BadEnd))
				{
					CurTime = GlobalContentsValue::DayTime;
					CreateDayTime();
				}
		if (GlobalContentsValue::Sojae)
		{
			SojaeLine();
			GlobalContentsValue::Sojae = false;
		}
		Count = Count + 1;
		for (int i = 0; i <40; i++)
		{
			if (Count == i)
			{
				if (GlobalContentsValue::TextContents == "LineD")
				{
					CreateText("LineD" + std::to_string(DCount) + ".png");
					DCount++;
				}
				else
				{
					CreateText(GlobalContentsValue::TextContents + std::to_string(i) + ".png");
				}

			}
		}
	}
	if (GlobalContentsValue::Line == false)
	{
		return;
	}
	else
	{
		if (CurEmoticonStatus != GlobalContentsValue::EomticonStatus)
		{
			EmoticonOnOff();
			CurEmoticonStatus = GlobalContentsValue::EomticonStatus;
		}
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
	exceptionCheck(_Text);

	MyTextureRenderer* TextRend = CreateComponent<MyTextureRenderer>();
	TextRend->SetTexture( _Text);
	TextRend->ScaleToTexture();

	float SizeY = 0;
	SizeY = TextRend->GetTransform().GetLocalScale().y;

	TextRend->GetTransform().SetLocalPosition(float4(185,(75 - TextNum) - SizeY/2 ));
	Text.push_back(TextRend);
	MoveStart++;
	if (MoveStart == 5)
	{
		TextMove(20, 0);
		TextNum = TextNum + 60+ 3; 
	}else
	if (MoveStart >= 6)
	{
		if (TextNum > 180.0f)
		{
			TextMove(static_cast<float>(TextNum) - 180.0f,0);
			TextNum = 180;
		}
		TextMove(SizeY + 3, 0);
	}
	else
	{
		TextNum = TextNum + static_cast<int>(SizeY) + 3;
	}
	if (_Text =="Communication3.png")
	{
		GetLevel()->CreateActor<Sojae>();
	}else
		if (_Text == "Game2.png")
		{
			GetLevel()->CreateActor<Sojae>();
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
	GlobalContentsValue::EomticonStatus = 1;
	ChoiceText = CreateComponent<MyTextureRenderer>();
	std::string Choice = "Choice" + std::to_string(ChoiceNum) + ".png";
	ChoiceText->SetTexture(Choice);
	ChoiceText->ScaleToTexture();
	float4 CurScale = ChoiceText->GetTransform().GetLocalScale();
	ChoiceText->GetTransform().SetLocalPosition(float4(344.5f - CurScale.x / 2.0f, -115.0f - CurScale.y /2.0f));

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalScale(float4(40, 10));
	Collision->GetTransform().SetLocalPosition(float4(320, -130, 0));
	Collision->ChangeOrder(OBJECTORDER::UI);

	Collision2 = CreateComponent<GameEngineCollision>();
	Collision2->GetTransform().SetLocalScale(float4(80, 10));
	Collision2->GetTransform().SetLocalPosition(float4(300, -155, 0));
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
		float SizeX = 0;
		std::string Choice = "Choice" + std::to_string(ChoiceNum) + "_1.png";
		if (Choice == "Choice2_1.png")
		{
			Count = Count + 1;
		}
		TextRend->SetTexture(Choice);
		TextRend->ScaleToTexture();
		SizeX = TextRend->GetTransform().GetLocalScale().x;
		SizeY = TextRend->GetTransform().GetLocalScale().y;
		TextRend->GetTransform().SetLocalPosition(float4(337.5f - SizeX/2, 75 - TextNum - SizeY / 2));
		ChoiceText->GetTransform().SetLocalMove(float4(0, 0, 600));
		Text.push_back(TextRend);
		MoveStart++;
		TextMove(SizeY + 3, 0);
		RLineNum();
		GlobalContentsValue::Tooltip = false;
		CheckStart = false;
	}else
		if (MouseCheck(Collision2)
			&& true == GameEngineInput::GetInst()->IsDown("MouseClick"))
		{
			MyTextureRenderer* TextRend = CreateComponent<MyTextureRenderer>();
			float SizeX = 0;
			float SizeY = 0;
			std::string Choice = "Choice" + std::to_string(ChoiceNum) + "_2.png";
			TextRend->SetTexture(Choice);
			TextRend->ScaleToTexture();
			SizeX = TextRend->GetTransform().GetLocalScale().x;
			SizeY = TextRend->GetTransform().GetLocalScale().y;
			TextRend->GetTransform().SetLocalPosition(float4(337.5f -SizeX / 2, 75 - TextNum - SizeY / 2));
			ChoiceText->GetTransform().SetLocalMove(float4(0, 0, 600));
			Text.push_back(TextRend);
			MoveStart++;
			TextMove(SizeY + 3, 0);
			RLineNum();
			GlobalContentsValue::Tooltip = false;
			CheckStart = false;
		}
}

void LineText::CreateDayTime()
{
	MyTextureRenderer* TextRend = CreateComponent<MyTextureRenderer>();
	std::string Time;
	switch (GlobalContentsValue::DayTime)
	{
	case 1:
		Time = "Morning.png";
		break;
	case 2:
		Time = "Evening.png";
		break;
	case 3: 
		Time = "Night.png";
		break;
	case 4:
		return;
	default:
		break;
	}
	TextRend->SetTexture(Time);
	TextRend->ScaleToTexture();

	float SizeY = 0;
	SizeY = TextRend->GetTransform().GetLocalScale().y;

	TextRend->GetTransform().SetLocalPosition(float4(205, (75 - TextNum) - SizeY / 2));
	Text.push_back(TextRend);
	MoveStart++;
	if (MoveStart == 4)
	{
		TextMove(20, 0);
		TextNum = TextNum + 60 + 3;
	}
	else
		if (MoveStart >= 5)
		{
			if (TextNum > 180.0f)
			{
				TextMove(static_cast<float>(TextNum) - 180.0f, 0);
				TextNum = 180;
			}
			TextMove(SizeY + 3, 0);
		}
		else
		{
			TextNum = TextNum + static_cast<int>(SizeY) + 3;
		}
}

void LineText::SojaeLine()
{
	MyTextureRenderer* TextRend = CreateComponent<MyTextureRenderer>();
	TextRend->SetTexture("SojaeLine.png");
	TextRend->ScaleToTexture();

	float SizeY = 0;
	SizeY = TextRend->GetTransform().GetLocalScale().y;

	TextRend->GetTransform().SetLocalPosition(float4(205, (75 - TextNum) - SizeY / 2));
	Text.push_back(TextRend);
	MoveStart++;
	if (MoveStart == 4)
	{
		TextMove(20, 0);
		TextNum = TextNum + 60 + 3;
	}
	else
		if (MoveStart >= 5)
		{
			if (TextNum > 180.0f)
			{
				TextMove(static_cast<float>(TextNum) - 180.0f, 0);
				TextNum = 180;
			}
			TextMove(SizeY + 3, 0);
		}
		else
		{
			TextNum = TextNum + static_cast<int>(SizeY) + 3;
		}
}

void LineText::RLineNum()
{
	GlobalContentsValue::EomticonStatus = 1;
	switch (ChoiceNum)
	{
	case 1:
		GlobalContentsValue::RemainLinenum = 8;
		break;
	case 2:
		GlobalContentsValue::RemainLinenum = 5;
		break;
	case 3:
		GlobalContentsValue::RemainLinenum = 1;
		break;
	default:
		break;
	}
}

void LineText::exceptionCheck(std::string _Text)
{
	for (int i = 0; i < 10; i++)
	{
		if (_Text == "LineD" + std::to_string(i) + ".png")
		{
			CreateDayTime();
		}
	}

	if (_Text == "Tutorial9.png")
	{
		GlobalContentsValue::Tooltip = true;
		ToolTipText::Count = ToolTipText::Count + 1;
		ChoiceTimeStart = true;
	}else
	if (_Text == "Tutorial23.png")
	{
		ChoiceTimeStart = true;
	}else
	if (_Text == "Tutorial17.png")
	{
		ChangeStart = true;
	}else
	if (_Text == "Tutorial28.png")
	{
		GlobalContentsValue::DayTime = GlobalContentsValue::DayTime + 1;
	}
	if (_Text == "Tutorial36.png")
	{
		ChoiceTimeStart = true;
	}else
	if (_Text == "Tutorial37.png")
	{
		GlobalContentsValue::Tooltip = true;
		ToolTipText::Count = ToolTipText::Count + 1;
		GlobalContentsValue::EomticonStatus = 2;
	}
}