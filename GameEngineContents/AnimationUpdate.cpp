#include "PreCompile.h"
#include "StreamAnimation.h"

void StreamAnimation::Tutorial()
{
	ChangeTime = ChangeTime + GameEngineTime::GetDeltaTime();
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
	case AnimationType::A5:
		UpdateA5();
		break;
	default:
		break;
	}
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

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") &&ChangeTime > 1.0f)
		||ChangeTime >9.0f)
	{
		CurType = AnimationType::A2;
		Time = 0;
		ChangeTime = 0;
		AnimationStart = false;
	}
}

void StreamAnimation::UpdateA2()
{
	Renderer->ChangeFrameAnimation("cho_kashikoma");

	if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
		|| ChangeTime > 9.0f)
	{
		CurType = AnimationType::A3;
		Time = 0;
		ChangeTime = 0;
		AnimationStart = false;
	}

}

void StreamAnimation::UpdateA3()
{
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

	if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
		|| ChangeTime > 9.0f)
	{
		CurType = AnimationType::A4;
		Time = 0;
		ChangeTime = 0;
		AnimationStart = false;
	}
}

void StreamAnimation::UpdateA4()
{

}

void StreamAnimation::UpdateA5()
{

}