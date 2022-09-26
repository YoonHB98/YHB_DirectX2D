#include "PreCompile.h"
#include "StreamAnimation.h"

// 6 "예쁜데" 46 초록
// 13 "왜 천사임?" 53 초록
// 51 "죽지 마셈" 1 31 빨강
// 52.5 "벌서 질리네" 1 32.5 보라 

void StreamAnimation::Talk()
{
	GlobalContentsValue::ChangeTime = GlobalContentsValue::ChangeTime + GameEngineTime::GetDeltaTime();
	Time = Time + GameEngineTime::GetDeltaTime();
	StateUpdate(CurType);
	GlobalContentsValue::Tooltip = false;
}

void StreamAnimation::UpdateB1()
{
	// 0 ~ 1 손 흔드는 모션 

	// 0 ~ 2 텍스트 출력
	// 0 ~ 7 텍스트 유지

	// 6 "예쁜데" 46 초록

	TextDrawTime("텐하!\n인터넷 엔젤, 초텐 짱이야!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 1.0f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd"); // 손 흔드는 모션 1초
		AnimationStart = true;
	}

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") && GlobalContentsValue::ChangeTime > 1.0f)
		|| GlobalContentsValue::ChangeTime > 7.0f)
	{
		CurType = AnimationType::B2;
		Time = 0;
		GlobalContentsValue::ChangeTime = 7.1f;
		AnimationStart = false;
	}
}

void StreamAnimation::UpdateB2()
{
	// 7 ~ 8 가만히
	// 8 ~ 9 눈 깜밖임
	// 반복

	// 7 ~ 9 텍스트 출력
	// 7 ~ 14 텍스트 유지

	// 13 "왜 천사임?" 53 초록

	TextDrawTime("난 인터넷이 정말 좋아\n그야 모두가 이야기를 들어주거든", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 2.0f);

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
		|| GlobalContentsValue::ChangeTime > 14.0f)
	{
		CurType = AnimationType::B3;
		Time = 0;
		GlobalContentsValue::ChangeTime = 14.1f;
		AnimationStart = false;
	}
}
void StreamAnimation::UpdateB3()
{
	// 14 ~ 15 눈 깜빡임
	// 15 ~ 17 가만히
	// 반복

	// 14 ~ 17 텍스트 출력
	// 14 ~ 28 텍스트 유지

	TextDrawTime("현실에서 가장 무서운 건 고독이야\n누구한테도 필요없는 인생은 공포밖에 없으니까", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 2.0f);

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
		|| GlobalContentsValue::ChangeTime > 28.0f)
	{
		CurType = AnimationType::B4;
		Time = 0;
		GlobalContentsValue::ChangeTime = 28.1f;
		AnimationStart = false;
	}
}
void StreamAnimation::UpdateB4()
{
	// 28 ~ 29 양손 볼 감싸기 + 2번 위아래 무빙
	// 29 ~ 43 양손 볼 감싸기

	// 28 ~ 30 텍스트 출력
	// 28 ~ 43 텍스트 유지

	TextDrawTime("아핫! 모두들 정말 좋아 이야기를 들어주네\n너희들을 위해서 나도 열심히 해야지!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 2.0f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_kawaiku"); // 눈 감고 양손 볼 감싸기 + 2번 위아래 무빙 1초간
		AnimationStart = true;
	}

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") && GlobalContentsValue::ChangeTime > 29.0f)
		|| GlobalContentsValue::ChangeTime > 43.0f)
	{
		CurType = AnimationType::B5;
		Time = 0;
		GlobalContentsValue::ChangeTime = 43.1f;
		AnimationStart = false;
	}
}
void StreamAnimation::UpdateB5()
{
	// 43 ~ 44 눈 깜빡임
	// 44 ~ 46 가만히
	// 반복

	// 43 ~ 45 텍스트 출력
	// 43 ~ 51 텍스트 유지

	TextDrawTime("질려버리면 끝장이니까...\n초텐 짱 아직 죽고싶지 않아 해보자!!!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 2.0f);

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
		|| GlobalContentsValue::ChangeTime > 51.0f)
	{
		CurType = AnimationType::B6;
		Time = 0;
		GlobalContentsValue::ChangeTime = 51.1f;
		AnimationStart = false;
	}
}
void StreamAnimation::UpdateB6()
{
	// 51 ~ 58 쳐다보는 눈깔 + 안 깜빡임

	// 51 ~ 52 1 텍스트 출력
	// 51 ~ 55 1 텍스트 유지
	// 55 ~ 55.5 2 텍스트 출력
	// 55 ~ 58 2 텍스트 유지

	// 51 "죽지 마셈" 1 31 빨강
	// 52.5 "벌서 질리네" 1 32.5 보라 

	if (GlobalContentsValue::ChangeTime > 55.0f) {
		TextDrawTime("「" + GlobalContentsValue::FirstComment + " 」", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);
	}
	else {
		TextDrawTime("너희들 반응이나 볼까...", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 1.0f);
	}

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("ChoSuperChat"); // 쳐다보는 눈깔, 깜빡거리지 않음
		AnimationStart = true;
	}

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") && GlobalContentsValue::ChangeTime > 55.5f)
		|| GlobalContentsValue::ChangeTime > 58.0f)
	{
		CurType = AnimationType::B7;
		Time = 0;
		GlobalContentsValue::ChangeTime = 58.1f;
		AnimationStart = false;
	}
}
void StreamAnimation::UpdateB7()
{
	// 58 ~ 58.5 양손 내밀고 1.5초간 양쪽으로 흔듬
	// 58.5 ~ 62 양손 내밀고 가만히

	// 58 ~ 59 텍스트 출력
	// 58 ~ 62 텍스트 유지

	// 62 ~ 64.5 방종 영상
	// 트윗 2개
	// 64.5  트윗 등장
	// 64.5 ~ 70 ~ 트윗 로딩
	// 65.5 1번 트윗
	// 70 2번 트윗

	TextDrawTime("고마워♡ 맨날 얘기하러 와줘!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 1.0f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd"); // 양손 내밀고 1초간 양쪽으로 흔듬
		AnimationStart = true;
	}

	if (GlobalContentsValue::ChangeTime > 62.0f)
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


