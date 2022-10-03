#include "PreCompile.h"
#include "PlayLevel.h"
#include "GlobalContentsValue.h"
#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineBase/GameEngineInput.h>
#include "Enums.h"
#include "MainBG.h"
#include "SideBG.h"
#include "WindowIcon.h"
#include "Notification.h"
#include "LineMain.h"
#include "WebCamWindow.h"
#include "TaskManager.h"
#include "Bar.h"
#include "Mouse.h"
#include "LineText.h"
#include "Change.h"
#include "Stream.h"
#include "StreamAnimation.h"
#include "ToolTip.h"
#include "NotificationText.h"
#include "TutorialLogin.h"
#include "ToolTipText.h"
#include "Comment.h"
#include "Twitter.h"
#include "TweetComment.h"
#include "DayChangeWindow.h"
#include "Asobu_Window.h"
#include "Neru_Window.h"
#include "CommentTalk.h"
#include "Stream_Window.h"
#include "NotificationDayTime.h"
#include "YNoiseEffect.h"
#include "CommentBadEnding.h"
#include "CommentGoodEnding.h"

float PlayLevel::time = 0;

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Start()
{




	//Line
	LineMainActor = CreateActor<LineMain>(GameObjectGroup::WindowIcon);
	LineTextActor = CreateActor<LineText>();
	LineTextActor->SetParent(LineMainActor);

	//stream
	StreamActor = CreateActor<Stream>(GameObjectGroup::UI);
	CommentActor = CreateActor<Comment>(GameObjectGroup::WindowIcon);
	StreamAnimationActor = CreateActor<StreamAnimation>(GameObjectGroup::WindowIcon);
	CommentActor->SetParent(StreamActor);
	StreamAnimationActor->SetParent(StreamActor);

	CreateActor<WebCamWindow>(GameObjectGroup::WindowIcon);
	CreateActor<Mouse>(GameObjectGroup::WindowIcon);
	CreateActor<ToolTip>(GameObjectGroup::WindowIcon);
	CreateActor<ToolTipText>(GameObjectGroup::WindowIcon);
	
	CreateActor<DayChangeWindow>(GameObjectGroup::UI);

	//BG
	CreateActor<WindowIcon>(GameObjectGroup::WindowIcon);
	CreateActor<MainBG>(GameObjectGroup::BackGround);
	CreateActor<SideBG>(GameObjectGroup::BackGround);

	//ingame
	CreateActor<Change>(GameObjectGroup::WindowIcon);
	GameEngineActor* Twit =  CreateActor<Twitter>(GameObjectGroup::WindowIcon);
	GameEngineActor* TwitCom = CreateActor<TweetComment>(GameObjectGroup::WindowIcon);
	TwitCom->SetParent(Twit);
	CreateActor<Asobu_Window>();
	CreateActor<Neru_Window>();
	CreateActor<Stream_Window>();


	YEffect = GetMainCamera()->GetCameraRenderTarget()->AddEffect<YNoiseEffect>();
	YEffect->Off();
}
void PlayLevel::Update(float _DeltaTime)
{
	BGM();
	if (CurDay != GlobalContentsValue::Day
		&& GlobalContentsValue::Mental > 80)
	{
		GlobalContentsValue::BgmOn = true;
		GlobalContentsValue::BadEnd = true;
		GlobalContentsValue::BgmName = "NoSalvationNoAngels.wav";
		GlobalContentsValue::RemainLinenum = 8;
		GlobalContentsValue::TextContents = "BadEnding";
		GlobalContentsValue::CommentContents = "BadEnding";
		GlobalContentsValue::Contents = "BadEndingStream";
		CurDay = GlobalContentsValue::Day;
		time = 0.0f;
	}

	if (CurDay != GlobalContentsValue::Day
		&& GlobalContentsValue::Followers > 10000)
	{
		CurDay = GlobalContentsValue::Day;
		GlobalContentsValue::BgmOn = true;
		GlobalContentsValue::BadEnd = false;
		GlobalContentsValue::GoodEnd = true;
		GlobalContentsValue::BgmName = "mainloop_happyarranged.wav";
		GlobalContentsValue::RemainLinenum = 5;
		GlobalContentsValue::TextContents = "GoodEnding";
		GlobalContentsValue::CommentContents = "GoodEnding";
		GlobalContentsValue::Contents = "GoodEndingStream";
		time = 0.0f;
	}

	if (GlobalContentsValue::BadEndChange)
	{
		BadEnd = false;
		GlobalContentsValue::BadEndChange = false;
		CreateActor<Change>();
		GlobalContentsValue::Change = true;
		YEffect->On();
	}

	if (GlobalContentsValue::BadEndLoadEnd)
	{
		YEffect->Off();
	}
	if (GlobalContentsValue::CommentContents == "BadEnding")
	{
		CreateActor<CommentBadEnding>();
		GlobalContentsValue::CommentContents = "";
	}
	if (time < 0.0f)
	{
		time = 0.0f;
	}
	if (GlobalContentsValue::Console)
	{
		CreateActor<NotificationDayTime>();
		GlobalContentsValue::Console = false;
	}

	TestTime = TestTime + _DeltaTime;
	if (GlobalContentsValue::DayChangeWindow)
	{
		time = 0.0f;
		return;
	}
	time = time + GameEngineTime::GetDeltaTime();
	if (time > 2.4f && GlobalContentsValue::RemainLinenum <= 0 && GlobalContentsValue::GoodEnd)
	{
		GlobalContentsValue::GoodEnd = false;
		GlobalContentsValue::Change = true;
		CreateActor<Change>();
	}
	if (time > 2.5f
		|| true == GameEngineInput::GetInst()->IsDown("MouseClick"))
	{
		time = 0.0f;
		if (GlobalContentsValue::Message)
		{
			GlobalContentsValue::RemainLinenum = GlobalContentsValue::RemainLinenum - 1;
			CreateActor<Notification>(GameObjectGroup::BackGround);
			CreateActor<NotificationText>(GameObjectGroup::WindowIcon);
		}
	}
	if (GlobalContentsValue::RemainLinenum <= 0)
	{
		GlobalContentsValue::Message = false;
	}
	if (GlobalContentsValue::RemainLinenum > 0)
	{
		GlobalContentsValue::Message = true;
	}
	if (GameEngineInput::GetInst()->IsDown("FreeCameaOnOff"))
	{
		GetMainCameraActor()->FreeCameraModeOnOff();
	}
	if (GlobalContentsValue::TutorialLogin
		&&TutorialLoginFirst)
	{
		TutorialLoginFirst = false;
		CreateActor<TutorialLogin>(GameObjectGroup::WindowIcon);
	}

	//듀토리얼이 끝나면 작업관리자 생성
	if (GlobalContentsValue::Tutorial == false
		&& TutorialFirst)
	{
		GameEngineActor* TaskManagerActor = CreateActor<TaskManager>(GameObjectGroup::WindowIcon);
		GameEngineActor* BarActor = CreateActor<Bar>(GameObjectGroup::WindowIcon);
		BarActor->SetParent(TaskManagerActor);
		TutorialFirst = false;
	}
	if (GlobalContentsValue::Day == 2&&Day2)
	{
		Day2 = false;
		CreateActor<NotificationText>(GameObjectGroup::WindowIcon);
	}
	if (GlobalContentsValue::CommentContents == "CommunicationStart")
	{
		CreateActor<CommentTalk>();
		GlobalContentsValue::DayTime = GlobalContentsValue::DayTime + 1;
		GlobalContentsValue::CommentContents = "";
	}
	if (GlobalContentsValue::CommentContents == "GoodEnding")
	{
		CreateActor<CommentGoodEnding>();
		GlobalContentsValue::CommentContents = "";
	}
	CurDay = GlobalContentsValue::Day;
}
void PlayLevel::End() {  }

void PlayLevel::ChangeZ(GameEngineActor* Actor, float Pos)
{
	
}

void PlayLevel::BGM()
{
	if (GlobalContentsValue::BgmStop)
	{
		BGMPlayer.Stop();
	}

	if (GlobalContentsValue::BgmOn)
	{
		BGMPlayer.Stop();
		BGMPlayer = GameEngineSound::SoundPlayControl(GlobalContentsValue::BgmName, 999);
		GlobalContentsValue::BgmOn = false;
	}
	else
	{
		if (CurBgmSpeed != GlobalContentsValue::BgmSpeed)
		{
			CurBgmSpeed = GlobalContentsValue::BgmSpeed;
				BGMPlayer.PlaySpeed(GlobalContentsValue::BgmSpeed);
		}
		return;
	}
}

