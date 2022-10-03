#include "PreCompile.h"
#include "StreamAnimation.h"
#include "BadEndEndWindow.h"

void StreamAnimation::BadEnding()
{
	GlobalContentsValue::ChangeTime = GlobalContentsValue::ChangeTime + GameEngineTime::GetDeltaTime();
	Time = Time + GameEngineTime::GetDeltaTime();
	StateUpdate(CurType);
	GlobalContentsValue::Tooltip = false;
}
// ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ
void StreamAnimation::UpdateC1()
{
	// ㄴㅅㅇㄷ

	// 0 ~ 6 가만히

	// 0 ~ 6 1 텍스트 유지
	// 0 ~ 0 텍스트 순간 출력

	TextDrawTime("그럼,", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("stream_cho_sayonara1"); // 가만히 
		AnimationStart = true;
	}

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick"))
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
	// 6 ~ 7 손 뻗기 애니메이션
	// 7 ~ 11 손 뻗기 유지

	// 6 ~ 11 텍스트 유지
	// 6 ~ 6 텍스트 순간 출력

	TextDrawTime("가볼까", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("stream_cho_sayonara2"); // 손 뻗기 1초
		AnimationStart = true;
	}

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick"))
		|| GlobalContentsValue::ChangeTime > 11.0f)
	{
		CurType = AnimationType::C3;
		Time = 0;
		GlobalContentsValue::ChangeTime = 11.1f;
		AnimationStart = false;
		GameEngineSound::SoundPlayOneShot("dosa.wav");
	}
}

void StreamAnimation::UpdateC3()
{

	TextDrawTime("   ", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 1.5f);
	TextDrawTime("바이바이", "Galmuri9", float4(332, 306), float4(222 / 255, 215 / 255, 1, 1), 15.0f, 0.5f);

	if (AnimationStart == false)
	{
		Renderer->ChangeFrameAnimation("stream_cho_sayonara3"); 
		AnimationStart = true;
	}

	if ((true == GameEngineInput::GetInst()->IsDown("MouseClick"))
		|| GlobalContentsValue::ChangeTime > 18.0f)
	{
		Time = 0;
		if (Ending)
		{
			AnimationStart = false;
			GetLevel()->CreateActor<BadEndEndWindow>();
			Ending = false;
		}

	}
}
