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
#include "Stream_Window.h"

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



}
void PlayLevel::Update(float _DeltaTime)
{
	BGM();


	if (GlobalContentsValue::DayChangeWindow)
	{
		return;
	}
	time = time + GameEngineTime::GetDeltaTime();

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

