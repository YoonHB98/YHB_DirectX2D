#include "PreCompile.h"
#include "StreamAnimation.h"

void StreamAnimation::BadEnding()
{
	GlobalContentsValue::ChangeTime = GlobalContentsValue::ChangeTime + GameEngineTime::GetDeltaTime();
	Time = Time + GameEngineTime::GetDeltaTime();
	StateUpdate(CurType);
	GlobalContentsValue::Tooltip = false;
}
// �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�
void StreamAnimation::UpdateC1()
{
	// ��������

	// 0 ~ 6 ������

	// 0 ~ 6 1 �ؽ�Ʈ ����
	// 0 ~ 0 �ؽ�Ʈ ���� ���

	TextDrawTime("�׷�,", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd"); // ������ 
		AnimationStart = true;
	}

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") && GlobalContentsValue::ChangeTime > 1.0f)
		|| GlobalContentsValue::ChangeTime > 6.0f)
	{
		CurType = AnimationType::C2;
		Time = 0;
		GlobalContentsValue::ChangeTime = 6.1f;
		AnimationStart = false;
	}

}

void StreamAnimation::UpdateC2()
{
	// 6 ~ 7 �� ���� �ִϸ��̼�
	// 7 ~ 11 �� ���� ����

	// 6 ~ 11 �ؽ�Ʈ ����
	// 6 ~ 6 �ؽ�Ʈ ���� ���

	TextDrawTime("������", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd"); // �� ���� 1��
		AnimationStart = true;
	}

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") && GlobalContentsValue::ChangeTime > 7.0f)
		|| GlobalContentsValue::ChangeTime > 11.0f)
	{
		CurType = AnimationType::C3;
		Time = 0;
		GlobalContentsValue::ChangeTime = 11.1f;
		AnimationStart = false;
	}
}

void StreamAnimation::UpdateC3()
{
	// 11 ~ 18 ������?

	// 11 ~ 18 �ؽ�Ʈ ����
	// 11 ~ 11 �ؽ�Ʈ ���� ���

	TextDrawTime("���̹���", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd"); // ������?
		AnimationStart = true;
	}

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") && GlobalContentsValue::ChangeTime > 12.0f)
		|| GlobalContentsValue::ChangeTime > 18.0f)
	{
		Time = 0;
		AnimationStart = false;
	}
}

// �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�