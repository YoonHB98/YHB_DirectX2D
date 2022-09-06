#include "PreCompile.h"
#include "StreamAnimation.h"
#include "ToolTipText.h"

void StreamAnimation::Tutorial()
{
		GlobalContentsValue::ChangeTime = 	GlobalContentsValue::ChangeTime + GameEngineTime::GetDeltaTime();
	Time = Time + GameEngineTime::GetDeltaTime();
	StateUpdate(CurType);
}

void StreamAnimation::StateUpdate(AnimationType Type)
{
	switch (Type)
	{
	case AnimationType::A1:
		UpdateA1();
		break;
	case AnimationType::A2:
		UpdateA2();
		break;
	case AnimationType::A3:
		UpdateA3();
		break;
	case AnimationType::A4:
		UpdateA4();
		break;
	case AnimationType::A5:
		UpdateA5();
		break;
	case AnimationType::A6:
		UpdateA6();
		break;
	case AnimationType::A7:
		UpdateA7();
		break;
	case AnimationType::A8:
		UpdateA8();
		break;
	case AnimationType::A9:
		UpdateA9();
		break;
	default:
		break;
	}
}

void StreamAnimation::TextDrawTime(const std::string& Text_, const std::string& Font_, float4 Pos_, float4 Color_, float Size_, float Time)
{

	if (CurText != Text_)
	{
		CurText = Text_;
		CountTime = 0;
		Count = 0;
		EnterCount = 0;
		Text = " ";
		BlankXSize = 0;
	}
	if (Count > Text_.length())
	{ 
	
		return;
	}
	CountTime = CountTime + GameEngineTime::GetDeltaTime();
	float AA = Time / Text_.length();
	if (Text_[Count] == 10
		&& CountTime >= AA)
	{
		EnterCount++;
	}
	if (Text_[Count] < 0)
	{
		if (FirstText)
		{
			Text = "" + Text + Text_[0] + Text_[1];
			Count = Count + 2;
			FirstText = false;
			if (EnterCount == 0)
			{
				BlankXSize++;
			}
		}

		if (CountTime >= AA)
		{
			Text = "" + Text + Text_[Count] + Text_[Count + 1];
			Count = Count + 2;
			CountTime = CountTime - AA;
			if (EnterCount == 0)
			{
				BlankXSize++;
			}
		}
	}
	else
	{
		if (FirstText)
		{
			Text = "" + Text + Text_[0];
			Count = Count + 1;
			FirstText = false;
			if (EnterCount == 0)
			{
				BlankXSize++;
			}
		}

		if (CountTime >= AA)
		{
			Text = "" + Text + Text_[Count];
			Count = Count + 1;
			CountTime = CountTime - AA;
			if (EnterCount == 0)
			{
				BlankXSize++;
			}
		}
	}
	Blank->GetPixelData().MulColor.a = 0.5f;
	Blank->GetTransform().SetWorldPosition(float4(-140, -35 , -520));
	Blank->GetTransform().SetLocalScale(float4(200, 60));
	float4 CurPos = Pos_ - float4(0, EnterCount * 20.0f);
	Font->SetLeftAndRightSort(LeftAndRightSort::CENTER);
	Font->TextDraw(Text,  Font_, CurPos, Color_, Size_);

}

void StreamAnimation::UpdateA1()
{

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd");
		AnimationStart = true;
	}

	if (Time > 2.0f
		&& CurAnim == Animation::End1)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd");
		CurAnim = Animation::Idle1;
		Time = Time - 2.0f;
	}
	else
		if (Time > 0.8f
			&& CurAnim == Animation::Idle1)
		{
			Renderer->ChangeFrameAnimation("cho_idle");
			Time = Time - 1.0f;
			CurAnim = Animation::End1;
		}
	GlobalContentsValue::Tooltip = true;
	if (GlobalContentsValue::ChangeTime > 2.0f)
	{
		GlobalContentsValue::ChangeTime = 2.0f;
	}
	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") &&	GlobalContentsValue::ChangeTime > 1.0f)
		||	GlobalContentsValue::ChangeTime >9.0f)
	{
		GlobalContentsValue::Tooltip = false;
		ToolTipText::Count = ToolTipText::Count + 1;
		CurType = AnimationType::A2;
		Time = 0;
			GlobalContentsValue::ChangeTime = 9.1f;
		AnimationStart = false;
	}
}

void StreamAnimation::UpdateA2()
{
	TextDrawTime("����!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 0.5f);
	Renderer->ChangeFrameAnimation("cho_kashikoma");

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") &&GlobalContentsValue::Check == false)
		|| 	GlobalContentsValue::ChangeTime > 18.0f)
	{
		CurType = AnimationType::A3;
		Time = 0;
			GlobalContentsValue::ChangeTime = 18.1f;
		AnimationStart = false;
	}

}

void StreamAnimation::UpdateA3()
{
	TextDrawTime("������ �Ϳ�� õ�� » �ٿ���\n'���� »'�̾�", "Galmuri9", float4(332, 306), float4(222/255,215/255,1,1), 15.0f, 1.5f);
	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd");
		AnimationStart = true;
	}

	if (Time > 2.0f
		&& CurAnim == Animation::End1)
	{
		Renderer->ChangeFrameAnimation("cho_idle");
		CurAnim = Animation::Idle1;
		Time = Time - 2.0f;
	}
	else
		if (Time > 1.0f
			&& CurAnim == Animation::Idle1)
		{
			Renderer->ChangeFrameAnimation("cho_idleEnd");
			Time = Time - 1.0f;
			CurAnim = Animation::End1;
		}

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") && GlobalContentsValue::Check == false)
		|| 	GlobalContentsValue::ChangeTime > 27.0f)
	{
		CurType = AnimationType::A4;
		Time = 0;
			GlobalContentsValue::ChangeTime = 27.1f;
		AnimationStart = false;
	}
}

void StreamAnimation::UpdateA4()
{
	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_angelEnd");
		AnimationStart = true;
	}
	if (Time > 2.0f
		&& CurAnim == Animation::End1)
	{
		Renderer->ChangeFrameAnimation("cho_angel");
		CurAnim = Animation::Idle1;
		Time = Time - 2.0f;
	}
	else
		if (Time > 1.0f
			&& CurAnim == Animation::Idle1)
		{
			Renderer->ChangeFrameAnimation("cho_angelEnd");
			Time = Time - 1.0f;
			CurAnim = Animation::End1;
		}

	if ( 	GlobalContentsValue::ChangeTime > 59.0f)
	{
		CurType = AnimationType::A5;
		Time = 0;
			GlobalContentsValue::ChangeTime = 59.1f;
		AnimationStart = false;
	}
	if (	GlobalContentsValue::ChangeTime < 35.0f)
	{
		ClickTime(35.1f);
		TextDrawTime("ȥ���� �۽��� ���̿� �ô���\n���ͳ��� ���� �� �ٱ� ��...", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 1.5f);
	}
	else
		if(	GlobalContentsValue::ChangeTime < 43.0f)
		{
			ClickTime(43.1f);
			TextDrawTime("������ �ٴ� ���� ������ ��Ÿ���� �̼Ҹ�!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 1.5f);
		}
		else
		if (	GlobalContentsValue::ChangeTime < 51.0f)
			{
			ClickTime(51.2f);
				TextDrawTime("�̷��� ��ȭ�� ����Ұ�!\n �������� ������ �׷��� �ð� ��!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 1.5f);
			}
		else
		if (	GlobalContentsValue::ChangeTime < 59.0f)
			{
			ClickTime(59.1f);
			TextDrawTime("���ͳ� ����, ���� ���⿡ ����!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 1.5f);
			}
}

void StreamAnimation::UpdateA5()
{
	if (Time > 4.0f
		&& CurAnim == Animation::End1)
	{
		Renderer->ChangeFrameAnimation("cho_kawaiku");
		CurAnim = Animation::Idle1;
		Time = Time - 4.0f;
	}
	else
		if (Time > 1.0f
			&& CurAnim == Animation::Idle1)
		{
			Renderer->ChangeFrameAnimation("cho_kawaiku2");
			Time = Time - 1.0f;
			CurAnim = Animation::End1;
		}
	TextDrawTime("������ ���ͳݿ� �ӹ����� ���Ŀ���\n õ���� ������ ��� ��� ġ���� �ٰ�", "Galmuri9", float4(332, 306), float4(222/255,215/255,1,1), 15.0f, 1.5f);
	ClickTime(69.1f);
	if (	GlobalContentsValue::ChangeTime > 69.0f)
	{
		CurType = AnimationType::A6;
		Time = 0;
			GlobalContentsValue::ChangeTime = 69.1f;
		AnimationStart = false;
	}

}


void StreamAnimation::UpdateA6()
{
	if (Time > 3.0f
		&& CurAnim == Animation::End1)
	{
		Renderer->ChangeFrameAnimation("cho_teachEnd");
		CurAnim = Animation::Idle1;
		Time = Time - 3.0f;
	}
	else
		if (Time > 1.0f
			&& CurAnim == Animation::Idle1)
		{
			Renderer->ChangeFrameAnimation("cho_teach");
			Time = Time - 1.0f;
			CurAnim = Animation::End1;
		}
	TextDrawTime("�׸��� ��� ������ �迡\n��Ʈ���Ӱ��� ������ ���� �ž�!", "Galmuri9", float4(332, 306), float4(222/255,215/255,1,1), 15.0f, 1.5f);
	ClickTime(77.1f);
	if (	GlobalContentsValue::ChangeTime > 77.0f)
	{
		CurType = AnimationType::A7;
		Time = 0;
			GlobalContentsValue::ChangeTime = 77.1f;
		AnimationStart = false;
	}
}

void StreamAnimation::UpdateA7()
{
	Renderer->ChangeFrameAnimation("pointing");
	TextDrawTime("���� ũ��, �ȷο� 100����!!!", "Galmuri9", float4(332, 306), float4(222/255,215/255,1,1), 15.0f, 1.5f);
	ClickTime(85.1f);
	if (	GlobalContentsValue::ChangeTime > 85.0f)
	{
		CurType = AnimationType::A8;
		Time = 0;
			GlobalContentsValue::ChangeTime = 85.1f;
		AnimationStart = false;
	}
}

void StreamAnimation::UpdateA8()
{
	TextDrawTime("���� �𸣴� �͵鵵 ������ �� ��Ź�آ�", "Galmuri9", float4(332, 306), float4(222/255,215/255,1,1), 15.0f, 1.5f);
	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd");
		AnimationStart = true;
	}

	if (Time > 2.0f
		&& CurAnim == Animation::End1)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd");
		CurAnim = Animation::Idle1;
		Time = Time - 2.0f;
	}
	else
		if (Time > 0.8f
			&& CurAnim == Animation::Idle1)
		{
			Renderer->ChangeFrameAnimation("cho_idle");
			Time = Time - 1.0f;
			CurAnim = Animation::End1;
		}
	ClickTime(91.1f);
	if (GlobalContentsValue::ChangeTime > 91.0f)
	{
		CurType = AnimationType::A9;
		Time = 0;
		GlobalContentsValue::ChangeTime = 91.1f;
		AnimationStart = false;
	}

}

void StreamAnimation::UpdateA9()
{
	if (GlobalContentsValue::FirstComment == "")
	{
		GlobalContentsValue::ChangeTime = 130.1f;
	}
	if (GlobalContentsValue::ChangeTime < 96.0f)
	{
		TextDrawTime("��� �о��", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);
		ClickTime(96.1f);
	}else
	if (GlobalContentsValue::ChangeTime < 102.0f)
	{
		TextDrawTime("��"+ GlobalContentsValue::FirstComment + " ��", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);
		ClickTime(102.1f);
	}else
		if (GlobalContentsValue::ChangeTime < 110.0f)
		{
			if (GlobalContentsValue::FirstComment == "����")
			{
				if (CurAnim != Animation::Idle2 && CurAnim != Animation::End2)
				{
					Time = 0.0f;
					CurAnim = Animation::Idle2;
				}
				if (GlobalContentsValue::ChangeTime<106.0f)
				{
					TextDrawTime("�ʳ� ����", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.3f);
					ClickTime(106.1f);
				}else	
				if (GlobalContentsValue::ChangeTime < 110.0f)
				{
					TextDrawTime("�Ƽ��� �����̾�", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.3f);
					ClickTime(110.1f);
				}
			}else
				if (GlobalContentsValue::FirstComment == "�� �༭ ����")
				{
					if (CurAnim != Animation::Idle3 && CurAnim != Animation::End3)
					{
						Time = 0.0f;
						CurAnim = Animation::Idle3;
					}
					TextDrawTime("������, �����̴ٳ�", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.6f);
					ClickTime(110.1f);
				}
			
		}else
			if (GlobalContentsValue::SecondComment == "")
			{
				GlobalContentsValue::ChangeTime = 130.1f;
			}else
			if (GlobalContentsValue::ChangeTime < 115.0f)
			{
				TextDrawTime("��" + GlobalContentsValue::SecondComment + " ��", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);
				ClickTime(115.1f);
			}else
				if (GlobalContentsValue::ChangeTime < 123.0f)
				{
					if (GlobalContentsValue::SecondComment == "����")
					{
						if (CurAnim != Animation::Idle2 && CurAnim != Animation::End2)
						{
							Time = 0.0f;
							CurAnim = Animation::Idle2;
						}if (GlobalContentsValue ::ChangeTime <119.0f)
						{
							TextDrawTime("�ʳ� ����", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);
							ClickTime(119.1f);
						}else
						if (GlobalContentsValue::ChangeTime < 123.0f)
						{
							TextDrawTime("�Ƽ��� �����̾�", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);
							ClickTime(123.1f);
						}
					}
					else
						if (GlobalContentsValue::SecondComment == "�� �༭ ����")
						{
							if (CurAnim != Animation::Idle3 && CurAnim != Animation::End3)
							{
								Time = 0.0f;
								CurAnim = Animation::Idle3;
							}
							TextDrawTime("������, �����̴ٳ�", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);
							ClickTime(123.1f);
						}
				}

			if (GlobalContentsValue::ChangeTime>123.0f)
			{
				GlobalContentsValue::ChangeTime = 250.0f;
			}
			if (GlobalContentsValue::ChangeTime > 123.0f)
			{
				Renderer->ChangeFrameAnimation("ChoEnd");
				TextDrawTime("   ", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 1.5f);
				if (GlobalContentsValue::Contents == "Tutorial")
				{
					GlobalContentsValue::Tooltip = true;
				}
				if (StreamEnd == false)
				{
					ToolTipText::Count = ToolTipText::Count + 1;
					StreamEnd = true;
					GameEngineSoundPlayer BGM = GameEngineSound::SoundPlayControl("endHaishin.wav", 0);
				}
				if (StreamEnd == true)
				{
					EndTimer = EndTimer + GameEngineTime::GetDeltaTime();
					if (EndTimer > 1.0f)
					{
					if (GlobalContentsValue::Contents == "Tutorial")
						{
			/*			if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
							{
							EndTimer = 0.0f;
							GlobalContentsValue::Stream = false;
							GlobalContentsValue::ChangeTime = 0.0f;
							GlobalContentsValue::Twitter = true;
							GlobalContentsValue::Tooltip = false;
							GlobalContentsValue::RemainTwitnum = 2;
						}else
							if (EndTimer > 3.0f
								|| true == GameEngineInput::GetInst()->IsDown("MouseClick"))
								{
								EndTimer = 0.0f;
								GlobalContentsValue::Stream = false;
								GlobalContentsValue::ChangeTime = 0.0f;
								GlobalContentsValue::Twitter = true;
								GlobalContentsValue::Tooltip = false;
								GlobalContentsValue::RemainTwitnum = 2;
								}*/
						}
					}
				}
				return;
			}
	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd");
		AnimationStart = true;
	}

	if (Time > 2.0f
		&& CurAnim == Animation::End1)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd");
		CurAnim = Animation::Idle1;
		Time = Time - 2.0f;
	}
	else
		if (Time > 0.8f
			&& CurAnim == Animation::Idle1)
		{
			Renderer->ChangeFrameAnimation("cho_idle");
			Time = Time - 0.8f;
			CurAnim = Animation::End1;
		}
	if (CurAnim == Animation::Idle3)
	{
		Renderer->ChangeFrameAnimation("ChoNyo");
	}
	else if (CurAnim == Animation::Idle2)
	{
		Renderer->ChangeFrameAnimation("ChoSuperChat");
	}



}


void StreamAnimation::ClickTime(float Time_)
{
	if (true == GameEngineInput::GetInst()->IsDown("MouseClick") && GlobalContentsValue::Check == false)
	{
		GlobalContentsValue::ChangeTime = Time_;
	}
}