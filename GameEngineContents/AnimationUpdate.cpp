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

void StreamAnimation::TextDrawTime(const std::string& Text_, const std::string& Font_, float4 Pos_, float4 Color_, float Size_, float Time)
{

	if (CurType !=  TextType)
	{
		TextType = CurType;
		CountTime = 0;
		Count = 0;
		EnterCount = 0;
		Text = " ";
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
	Blank->GetColorData().MulColor.a = 0.5f;
	Blank->GetTransform().SetWorldPosition(float4(-140, -35 , -520));
	Blank->GetTransform().SetLocalScale(float4(200, 60));
	float4 CurPos = Pos_ - float4(BlankXSize * 5, EnterCount * 20);
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
	TextDrawTime("젤하!", "Galmuri9", float4(332, 306), float4(1, 1, 1, 1), 15.0f, 0.5f);
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
	TextDrawTime("초절정 귀요미 천사 쨩 줄여서\n          '초텐 쨩'이야", "Galmuri9", float4(332, 306), float4(1, 1, 1, 1), 15.0f, 1.5f);
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
	TextDrawTime("혼돈에 휩싸인 레이와 시대의\n  인터넷을 비출 한 줄기 빛...", "Galmuri9", float4(332, 306), float4(1, 1, 1, 1), 15.0f, 1.5f);
	TextDrawTime("전자의 바다 위를 떠도는 오타쿠에게 미소를!", "Galmuri9", float4(332, 306), float4(1, 1, 1, 1), 15.0f, 1.5f);
	TextDrawTime("미래의 평화를 약속할게!\n 조울증도 있지만 그래도 맡겨 줘!", "Galmuri9", float4(332, 306), float4(1, 1, 1, 1), 15.0f, 1.5f);
	TextDrawTime("인터넷 엔젤, 지금 여기에 강림!", "Galmuri9", float4(332, 306), float4(1, 1, 1, 1), 15.0f, 1.5f);
}

void StreamAnimation::UpdateA5()
{
	TextDrawTime("앞으로 인터넷에 머무르는 덕후에게\n 천사의 애정을 듬뿍 담아 치유해 줄게", "Galmuri9", float4(332, 306), float4(1, 1, 1, 1), 15.0f, 1.5f);
}

void StreamAnimation::UpdateA6()
{
	TextDrawTime("그리고 기왕 시작한 김에\n    스트리머계의 정점도 찍을 거야!", "Galmuri9", float4(332, 306), float4(1, 1, 1, 1), 15.0f, 1.5f);
}

void StreamAnimation::UpdateA7()
{
	TextDrawTime("꿈은 크게, 팔로워 100만명!!!", "Galmuri9", float4(332, 306), float4(1, 1, 1, 1), 15.0f, 1.5f);
}

void StreamAnimation::UpdateA8()
{
	TextDrawTime("아직 모르는 것들도 많지만 잘 부탁해♪", "Galmuri9", float4(332, 306), float4(1, 1, 1, 1), 15.0f, 1.5f);
}