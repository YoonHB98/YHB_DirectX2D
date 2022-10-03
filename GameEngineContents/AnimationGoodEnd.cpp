#include "PreCompile.h"
#include "StreamAnimation.h"

void StreamAnimation::GoodEnding()
{
	GlobalContentsValue::ChangeTime = GlobalContentsValue::ChangeTime + GameEngineTime::GetDeltaTime();
	Time = Time + GameEngineTime::GetDeltaTime();
	StateUpdate(CurType);
	GlobalContentsValue::Tooltip = false;
}


void StreamAnimation::UpdateD1()
{
	// ¿À¸¥´« ¿À¸¥¼Õ ºêÀÌ 0.5ÃÊ

	// 0 ~ 5 ÅÙÇÏ!

	TextDrawTime("ÅÙÇÏ!,", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_kashikoma");
		AnimationStart = true;
	}

	if (((true == GameEngineInput::GetInst()->IsDown("MouseClick"))&& (GlobalContentsValue::ChangeTime > 1.0f))
		||( GlobalContentsValue::ChangeTime > 5.0f))
	{
		CurType = AnimationType::D2;
		Time = 0;
		GlobalContentsValue::ChangeTime = 5.1f;
		AnimationStart = false;
	}
}

void StreamAnimation::UpdateD2()
{
	// ´« ±ôºý

	// 2 ~ 7

	TextDrawTime("ÀÌ°Å ºÁ!,", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);

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

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick"))
		|| GlobalContentsValue::ChangeTime > 7.0f)
	{
		CurType = AnimationType::D3;
		Time = 0;
		GlobalContentsValue::ChangeTime = 7.1f;
		AnimationStart = false;
	}
}

void StreamAnimation::UpdateD3()
{
	// 7 ~ 10

	// ¾çº¼ °¨½Î±â + À®Å©?

	TextDrawTime("¿¡ÇìÇì ±ôÂ¦ ³î¶úÁö?,", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_kawaiku"); // ¾çº¼ °¨½Î±â + À®Å©?
		AnimationStart = true;
	}

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick"))
		|| GlobalContentsValue::ChangeTime > 10.0f)
	{
		CurType = AnimationType::D4;
		Time = 0;
		GlobalContentsValue::ChangeTime = 10.1f;
		AnimationStart = false;
	}
}

void StreamAnimation::UpdateD4()
{
	// 10 ~ 13.5

	// ¾çº¼ °¨½Î±â, ´«°¨±â

	TextDrawTime("µåµð¾î!! ÃÊÅÙ Â¯ÀÇ ¼º! »ç¹ö·È¾î!,", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_kawaiku_superchat"); // ¾çº¼ °¨½Î±â, ´«°¨±â
		AnimationStart = true;
	}

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick"))
		|| GlobalContentsValue::ChangeTime > 13.5f)
	{
		CurType = AnimationType::D5;
		Time = 0;
		GlobalContentsValue::ChangeTime = 13.6f;
		AnimationStart = false;
	}
}

void StreamAnimation::UpdateD5()
{
	// 13.5 ~ 16.5

	// ´« ±ôºý

	TextDrawTime("Àå¼Ò´Â ¾Ë·ÁÁÙ ¼ö ¾øÁö¸¸ ¸»¾ß,", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);

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

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick"))
		|| GlobalContentsValue::ChangeTime > 16.5f)
	{
		CurType = AnimationType::D6;
		Time = 0;
		GlobalContentsValue::ChangeTime = 16.6f;
		AnimationStart = false;
	}
}

void StreamAnimation::UpdateD6()
{
	// 16.5 ~ 23

	// ¾ç¼Õ ¼Ò¸Å ÀÚ±â °¡¸£Å°°í ´«±ôºý

	TextDrawTime("¾î¾î¾î¾î¾öÃ» ÁÁÀº µ¥¢½,", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("stream_cho_kobiru"); // ¾ç¼Õ¼Ò¸Å
		AnimationStart = true;
	}


	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") )
		|| GlobalContentsValue::ChangeTime > 23.0f)
	{
		CurType = AnimationType::D7;
		Time = 0;
		GlobalContentsValue::ChangeTime = 23.1f;
		AnimationStart = false;
	}
}

void StreamAnimation::UpdateD7()
{
	// 23 ~ 27.5

	// ¾ç¼Õ ÆîÃÄ¼­ ³»¹Ð°í Èçµë

	TextDrawTime("¸ðµÎÀÇ ´öºÐÀÌ¾ß °¨»ç!!,", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_akaruku_superchat"); // ´«°¨°í ¾ç¼Õ ³»¹Ð°í Èçµé±â
		AnimationStart = true;
	}

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") )
		|| GlobalContentsValue::ChangeTime > 27.5f)
	{
		CurType = AnimationType::D8;
		Time = 0;
		GlobalContentsValue::ChangeTime = 27.6f;
		AnimationStart = false;
	}

	// -> ±âº» idle
	// ±×·³ ¶Ç º¸ÀÚ!

	// -> ´«°¨À¸¸ç Çã°ø Å°½º?
	// ¢Ó½ÂÃµ¢Ó
}

void StreamAnimation::UpdateD8()
{
	// 27.5 ~ 37

	// ÇÑ¼Õ ³»¹Ð¸ç ºêÀÌ

	TextDrawTime("¾ÕÀ¸·Îµµ ÀÀ¿ø Àß ºÎÅ¹ÇØ!,", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("stream_cho_peace"); // ÇÑ¼Õ ³»¹Ð¸ç ºêÀÌ
		AnimationStart = true;
	}

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") )
		|| GlobalContentsValue::ChangeTime > 37.0f)
	{
		CurType = AnimationType::D9;
		Time = 0;
		GlobalContentsValue::ChangeTime = 37.1f;
		AnimationStart = false;
	}

	// -> ±âº» idle
	// ±×·³ ¶Ç º¸ÀÚ!

	// -> ´«°¨À¸¸ç Çã°ø Å°½º?
	// ¢Ó½ÂÃµ¢Ó
}

void StreamAnimation::UpdateD9()
{
	// 37 ~ 43.5

	// ´« ±ôºý 

	TextDrawTime("±×·³ ¶Ç º¸ÀÚ!,", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("cho_idleEnd"); // ¾ç¼Õ¼Ò¸Å
		AnimationStart = true;
	}

	if (Time > 2.0f
		&& CurAnim == Animation::End1)
	{
		Renderer->ChangeFrameAnimation("cho_idle"); // ´«±ôºý
		CurAnim = Animation::Idle1;
		Time = Time - 2.0f;
	}
	else
		if (Time > 1.0f
			&& CurAnim == Animation::Idle1)
		{
			Renderer->ChangeFrameAnimation("cho_idleEnd"); // ¾ç¼Õ¼Ò¸Å
			Time = Time - 1.0f;
			CurAnim = Animation::End1;
		}

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick") )
		|| GlobalContentsValue::ChangeTime > 43.5f)
	{
		CurType = AnimationType::D10;
		Time = 0;
		GlobalContentsValue::ChangeTime = 43.6f;
		AnimationStart = false;
	}
}

void StreamAnimation::UpdateD10()
{
	// 43.5 ~ 45

	// ´«°¨À¸¸ç Çã°ø Å°½º?

	TextDrawTime("¢Ó½ÂÃµ¢Ó,", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("stream_cho_h_superchat"); // Çã°ø Å°½º
		AnimationStart = true;
	}

	if (GlobalContentsValue::ChangeTime > 45.0f)
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
					GlobalContentsValue::Tooltip = false;
					GlobalContentsValue::RemainLinenum = 2;
				}
				else if (EndTimer > 3.0f)
				{
					EndTimer = 0.0f;
					GlobalContentsValue::Stream = false;
					GlobalContentsValue::ChangeTime = 0.0f;
					GlobalContentsValue::Tooltip = false;
					GlobalContentsValue::RemainLinenum = 2;

				}
			}
		}
		return;
	}
}