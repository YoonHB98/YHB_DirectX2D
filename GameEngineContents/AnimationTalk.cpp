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
	TextDrawTime("젤하!\n인터넷 엔젤, 초텐 짱이야!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 1.0f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd"); // 손 흔드는 모션 1초
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
	// 7 ~ 8 가만히
	// 8 ~ 9 눈 깜밖임
	// 반복

	// 7 ~ 9 텍스트 출력
	// 7 ~ 14 텍스트 유지

	// 13 "왜 천사임?" 53 초록

	TextDrawTime("인터넷은 정말 최고야.\n모두 내 이야기를 들어 주는걸!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 1.0f);

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
	// 14 ~ 15 눈 깜빡임
	// 15 ~ 17 가만히
	// 반복

	// 14 ~ 17 텍스트 출력
	// 14 ~ 28 텍스트 유지
	TextDrawTime("현실에서 가장 무서운 건 고독이야\n누구도 원하지 않는 삶이란 공포 그 자체니까", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 1.0f);

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
	// 28 ~ 29 양손 볼 감싸기 + 2번 위아래 무빙
	// 29 ~ 43 양손 볼 감싸기

	// 28 ~ 30 텍스트 출력
	// 28 ~ 43 텍스트 유지

	TextDrawTime("헤헤, 모두 넘 좋아! 이야기를 들어주는\n너희 모두를 위해서라도 열심히 해야지!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 1.5f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_kawaiku_superchat"); // 눈 감고 양손 볼 감싸기 + 2번 위아래 무빙 1초간
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
	// 43 ~ 44 눈 깜빡임
	// 44 ~ 46 가만히
	// 반복

	// 43 ~ 45 텍스트 출력
	// 43 ~ 51 텍스트 유지

	TextDrawTime("모두가 싫어하면 거기서 끝인걸...\n초텐은 아직 죽고 싶지 않아. 아자아자!!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 1.5f);

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
	// 51 ~ 58 쳐다보는 눈깔 + 안 깜빡임

	// 51 ~ 52 1 텍스트 출력
	// 51 ~ 55 1 텍스트 유지
	// 55 ~ 55.5 2 텍스트 출력
	// 55 ~ 58 2 텍스트 유지

	// 51 "죽지 마셈" 1 31 빨강
	// 52.5 "벌서 질리네" 1 32.5 보라 




		TextDrawTime("잡담 시간이야!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255), 15.0f, 0.5f);

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
		TextDrawTime("「" + GlobalContentsValue::FirstComment + " 」", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);
		ClickTime(41.1f);
	}
	else
		if (GlobalContentsValue::ChangeTime < 52.0f)
		{
			if (GlobalContentsValue::FirstComment == "완죤 내 스탈!")
			{
				if (CurAnim != Animation::Idle3 && CurAnim != Animation::End3)
				{
					Time = 0.0f;
					CurAnim = Animation::Idle3;
				}
				if (GlobalContentsValue::ChangeTime < 46.0f)
				{
					TextDrawTime("고마워♡ 매일 와서 말해 줘!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.3f);
					ClickTime(52.1f);
				}
			}
			else
				if (GlobalContentsValue::FirstComment == "어째서 천사임?")
				{
					if (CurAnim != Animation::Idle2 && CurAnim != Animation::End2)
					{
						Time = 0.0f;
						CurAnim = Animation::Idle2;
					}
						TextDrawTime("그건 말야... 넘 귀여워서지\n 난 태어날 때부터 천사였는걸", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.6f);
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
					TextDrawTime("「" + GlobalContentsValue::SecondComment + " 」", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);
					ClickTime(56.1f);
				}
				else
					if (GlobalContentsValue::ChangeTime < 61.0f)
					{
						if (GlobalContentsValue::SecondComment == "완죤 내 스탈!")
						{
							if (CurAnim != Animation::Idle3 && CurAnim != Animation::End3)
							{
								Time = 0.0f;
								CurAnim = Animation::Idle3;
							}if (GlobalContentsValue::ChangeTime < 67.0f)
							{
								TextDrawTime("고마워♡ 매일 와서 말해 줘!", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);
								ClickTime(67.1f);
							}
						}
						else
							if (GlobalContentsValue::SecondComment == "어째서 천사임?")
							{
								if (CurAnim != Animation::Idle2 && CurAnim != Animation::End2)
								{
									Time = 0.0f;
									CurAnim = Animation::Idle2;
								}
								TextDrawTime("그건 말야... 넘 귀여워서지\n 난 태어날 때부터 천사였는걸", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 1.0f);
								ClickTime(67.1f);
							}
					}

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd"); // 양손 내밀고 1초간 양쪽으로 흔듬
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


