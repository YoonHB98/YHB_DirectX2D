#include "PreCompile.h"
#include "StreamAnimation.h"

// 6 "���۵�" 46 �ʷ�
// 13 "�� õ����?" 53 �ʷ�
// 51 "���� ����" 1 31 ����
// 52.5 "���� ������" 1 32.5 ���� 

void StreamAnimation::Talk()
{
	GlobalContentsValue::ChangeTime = GlobalContentsValue::ChangeTime + GameEngineTime::GetDeltaTime();
	Time = Time + GameEngineTime::GetDeltaTime();
	StateUpdate(CurType);
	GlobalContentsValue::Tooltip = false;
}

void StreamAnimation::UpdateB1()
{
	// 0 ~ 1 �� ���� ��� 

	// 0 ~ 2 �ؽ�Ʈ ���
	// 0 ~ 7 �ؽ�Ʈ ����

	// 6 "���۵�" 46 �ʷ�
	TextDrawTime("����!\n���ͳ� ����, ���� ¯�̾�!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 1.0f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd"); // �� ���� ��� 1��
		AnimationStart = true;
	}

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") && GlobalContentsValue::ChangeTime > 1.0f)
		|| GlobalContentsValue::ChangeTime > 5.0f)
	{
		CurType = AnimationType::B2;
		Time = 0;
		GlobalContentsValue::ChangeTime = 5.1f;
		AnimationStart = false;
	}
}

void StreamAnimation::UpdateB2()
{
	// 7 ~ 8 ������
	// 8 ~ 9 �� ������
	// �ݺ�

	// 7 ~ 9 �ؽ�Ʈ ���
	// 7 ~ 14 �ؽ�Ʈ ����

	// 13 "�� õ����?" 53 �ʷ�

	TextDrawTime("���ͳ��� ���� �ְ��.\n��� �� �̾߱⸦ ��� �ִ°�!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 1.0f);

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

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") && GlobalContentsValue::ChangeTime > 8.0f)
		|| GlobalContentsValue::ChangeTime > 10.0f)
	{
		CurType = AnimationType::B3;
		Time = 0;
		GlobalContentsValue::ChangeTime = 10.1f;
		AnimationStart = false;
	}
}
void StreamAnimation::UpdateB3()
{
	// 14 ~ 15 �� ������
	// 15 ~ 17 ������
	// �ݺ�

	// 14 ~ 17 �ؽ�Ʈ ���
	// 14 ~ 28 �ؽ�Ʈ ����
	TextDrawTime("���ǿ��� ���� ������ �� ���̾�\n������ ������ �ʴ� ���̶� ���� �� ��ü�ϱ�", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 1.0f);

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

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") && GlobalContentsValue::ChangeTime > 15.0f)
		|| GlobalContentsValue::ChangeTime > 18.0f)
	{
		CurType = AnimationType::B4;
		Time = 0;
		GlobalContentsValue::ChangeTime = 18.1f;
		AnimationStart = false;
		CurAnim = Animation::Idle1;
	}
}
void StreamAnimation::UpdateB4()
{
	// 28 ~ 29 ��� �� ���α� + 2�� ���Ʒ� ����
	// 29 ~ 43 ��� �� ���α�

	// 28 ~ 30 �ؽ�Ʈ ���
	// 28 ~ 43 �ؽ�Ʈ ����

	TextDrawTime("����, ��� �� ����! �̾߱⸦ ����ִ�\n���� ��θ� ���ؼ��� ������ �ؾ���!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 1.5f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_kawaiku_superchat"); // �� ���� ��� �� ���α� + 2�� ���Ʒ� ���� 1�ʰ�
		AnimationStart = true;
	}

	if (CurAnim == Animation::End1)
	{
		Renderer->ChangeFrameAnimation("cho_kawaiku_superchat2");
		CurAnim = Animation::Idle1;
		Time = Time - 2.0f;
	}
	else
		if (Time > 1.0f
			&& CurAnim == Animation::Idle1)
		{
			Renderer->ChangeFrameAnimation("cho_kawaiku_superchat");
			Time = Time - 1.0f;
			CurAnim = Animation::End1;
		}

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") && GlobalContentsValue::ChangeTime > 29.0f)
		|| GlobalContentsValue::ChangeTime > 24.0f)
	{
		CurType = AnimationType::B5;
		Time = 0;
		GlobalContentsValue::ChangeTime = 24.1f;
		AnimationStart = false;
	}
}
void StreamAnimation::UpdateB5()
{
	// 43 ~ 44 �� ������
	// 44 ~ 46 ������
	// �ݺ�

	// 43 ~ 45 �ؽ�Ʈ ���
	// 43 ~ 51 �ؽ�Ʈ ����

	TextDrawTime("��ΰ� �Ⱦ��ϸ� �ű⼭ ���ΰ�...\n������ ���� �װ� ���� �ʾ�. ���ھ���!!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 1.5f);

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

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") && GlobalContentsValue::ChangeTime > 44.0f)
		|| GlobalContentsValue::ChangeTime > 32.0f)
	{
		CurType = AnimationType::B6;
		Time = 0;
		GlobalContentsValue::ChangeTime = 32.1f;
		AnimationStart = false;
	}
}
void StreamAnimation::UpdateB6()
{
	// 51 ~ 58 �Ĵٺ��� ���� + �� ������

	// 51 ~ 52 1 �ؽ�Ʈ ���
	// 51 ~ 55 1 �ؽ�Ʈ ����
	// 55 ~ 55.5 2 �ؽ�Ʈ ���
	// 55 ~ 58 2 �ؽ�Ʈ ����

	// 51 "���� ����" 1 31 ����
	// 52.5 "���� ������" 1 32.5 ���� 




		TextDrawTime("��� �ð��̾�!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 0.5f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd"); 
		AnimationStart = true;
	}

	if (GlobalContentsValue::FirstComment == "")
	{
		GlobalContentsValue::ChangeTime = 130.1f;
		CurType = AnimationType::B7;
		return;
	}
	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") && GlobalContentsValue::ChangeTime > 55.5f)
		|| GlobalContentsValue::ChangeTime > 37.0f)
	{
		CurType = AnimationType::B7;
		Time = 0;
		GlobalContentsValue::ChangeTime = 37.1f;
		AnimationStart = false;
	}
}
void StreamAnimation::UpdateB7()
{
	// 58 ~ 58.5 ��� ���а� 1.5�ʰ� �������� ���
	// 58.5 ~ 62 ��� ���а� ������

	// 58 ~ 59 �ؽ�Ʈ ���
	// 58 ~ 62 �ؽ�Ʈ ����

	// 62 ~ 64.5 ���� ����
	// Ʈ�� 2��
	// 64.5  Ʈ�� ����
	// 64.5 ~ 70 ~ Ʈ�� �ε�
	// 65.5 1�� Ʈ��
	// 70 2�� Ʈ��
	if (Time > 2.0f
		&& CurAnim == Animation::End3)
	{
		Renderer->ChangeFrameAnimation("cho_akaruku_superchat");
		CurAnim = Animation::Idle3;
		Time = Time - 2.0f;
	}
	else
		if (Time > 3.0f
			&& CurAnim == Animation::Idle3)
		{
			Renderer->ChangeFrameAnimation("cho_akaruku_superchat2");
			Time = Time - 3.0f;
			CurAnim = Animation::End3;
		}

	if (Time >1.0f
		&& CurAnim == Animation::End2)
	{
		Renderer->ChangeFrameAnimation("cho_idle");
		CurAnim = Animation::Idle2;
		Time = Time - 1.0f;
	}
	else
		if (Time > 1.0f
			&& CurAnim == Animation::Idle2)
		{
			Renderer->ChangeFrameAnimation("cho_idleEnd");
			Time = Time - 1.0f;
			CurAnim = Animation::End2;
		}


	if (GlobalContentsValue::ChangeTime < 41.0f)
	{
		TextDrawTime("��" + GlobalContentsValue::FirstComment + " ��", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);
		ClickTime(41.1f);
	}
	else
		if (GlobalContentsValue::ChangeTime < 52.0f)
		{
			if (GlobalContentsValue::FirstComment == "���� �� ��Ż!")
			{
				if (CurAnim != Animation::Idle3 && CurAnim != Animation::End3)
				{
					Time = 0.0f;
					CurAnim = Animation::Idle3;
				}
				if (GlobalContentsValue::ChangeTime < 46.0f)
				{
					TextDrawTime("������ ���� �ͼ� ���� ��!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.3f);
					ClickTime(52.1f);
				}
			}
			else
				if (GlobalContentsValue::FirstComment == "��°�� õ����?")
				{
					if (CurAnim != Animation::Idle2 && CurAnim != Animation::End2)
					{
						Time = 0.0f;
						CurAnim = Animation::Idle2;
					}
						TextDrawTime("�װ� ����... �� �Ϳ�������\n �� �¾ ������ õ�翴�°�", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.6f);
						ClickTime(52.1f);
				}

		}
		else
			if (GlobalContentsValue::SecondComment == "")
			{
				GlobalContentsValue::ChangeTime = 130.1f;
			}
			else
				if (GlobalContentsValue::ChangeTime < 56.0f)
				{
					TextDrawTime("��" + GlobalContentsValue::SecondComment + " ��", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);
					ClickTime(56.1f);
				}
				else
					if (GlobalContentsValue::ChangeTime < 61.0f)
					{
						if (GlobalContentsValue::SecondComment == "���� �� ��Ż!")
						{
							if (CurAnim != Animation::Idle3 && CurAnim != Animation::End3)
							{
								Time = 0.0f;
								CurAnim = Animation::Idle3;
							}if (GlobalContentsValue::ChangeTime < 67.0f)
							{
								TextDrawTime("������ ���� �ͼ� ���� ��!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);
								ClickTime(67.1f);
							}
						}
						else
							if (GlobalContentsValue::SecondComment == "��°�� õ����?")
							{
								if (CurAnim != Animation::Idle2 && CurAnim != Animation::End2)
								{
									Time = 0.0f;
									CurAnim = Animation::Idle2;
								}
								TextDrawTime("�װ� ����... �� �Ϳ�������\n �� �¾ ������ õ�翴�°�", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 1.0f);
								ClickTime(67.1f);
							}
					}

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd"); // ��� ���а� 1�ʰ� �������� ���
		AnimationStart = true;
	}

	if (GlobalContentsValue::ChangeTime > 72.0f)
	{
		AnimationStart = false;
		Renderer->ChangeFrameAnimation("ChoEnd");
		TextDrawTime("   ", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 1.5f);
		if (StreamEnd == false)
		{
			StreamEnd = true;
			GameEngineSoundPlayer BGM = GameEngineSound::SoundPlayControl("endHaishin.wav", 0);
		}
		if (StreamEnd == true)
		{
			EndTimer = EndTimer + GameEngineTime::GetDeltaTime();
			if (EndTimer > 1.0f)
			{
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
				{
					EndTimer = 0.0f;
					GlobalContentsValue::Stream = false;
					GlobalContentsValue::ChangeTime = 0.0f;
					GlobalContentsValue::Twitter = true;
					GlobalContentsValue::Tooltip = false;
					GlobalContentsValue::RemainTwitnum = 2;
				}
				else if (EndTimer > 3.0f)
				{
					EndTimer = 0.0f;
					GlobalContentsValue::Stream = false;
					GlobalContentsValue::ChangeTime = 0.0f;
					GlobalContentsValue::Twitter = true;
					GlobalContentsValue::Tooltip = false;
					GlobalContentsValue::RemainTwitnum = 2;

				}
			}
		}
		return;
	}
}


