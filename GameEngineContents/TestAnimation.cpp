#include "PreCompile.h"
#include "StreamAnimation.h"

void StreamAnimation::Test()
{
	GlobalContentsValue::ChangeTime = GlobalContentsValue::ChangeTime + GameEngineTime::GetDeltaTime();
	Time = Time + GameEngineTime::GetDeltaTime();
	StateUpdate(CurType);
	GlobalContentsValue::Tooltip = false;
}
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
void StreamAnimation::UpdateT1()
{

	// ㄴㅅㅇㄷ

	// 0 ~ 6 가만히

	// 0 ~ 6 1 텍스트 유지
	// 0 ~ 0 텍스트 순간 출력

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

	if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
	{
		CurType = AnimationType::T2;
		GlobalContentsValue::ChangeTime = 0;
	}


	




}

void StreamAnimation::UpdateT2()
{
	// 6 ~ 7 손 뻗기 애니메이션
	// 7 ~ 11 손 뻗기 유지

	// 6 ~ 11 텍스트 유지
	// 6 ~ 6 텍스트 순간 출력

	TextDrawTime("안녕하세요", "Galmuri9", float4(520, 450), float4(1.0f / 255.0f, 1.0f / 255.0f, 1.0f / 255.0f, 1), 25.0f, 1.0f);

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

	if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
	{
		GlobalContentsValue::ChangeTime = 4.0f;
	}
	else if (GlobalContentsValue::ChangeTime < 3.9f)
	{
		GlobalContentsValue::ChangeTime = 0;
	}


	if (GlobalContentsValue::ChangeTime > 6)
	{
		CurType = AnimationType::T3;
	}



}

void StreamAnimation::UpdateT3()
{
	// 6 ~ 7 손 뻗기 애니메이션
	// 7 ~ 11 손 뻗기 유지

	// 6 ~ 11 텍스트 유지
	// 6 ~ 6 텍스트 순간 출력

	TextDrawTime("안녕!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 30.0f, 0.5f);
	Renderer->ChangeFrameAnimation("cho_akaruku_superchat");
	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_akaruku_superchat"); // 눈감고 양손 내밀고 흔들기
		AnimationStart = true;
	}


}

