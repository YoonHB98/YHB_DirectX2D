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

float PlayLevel::time = 0;

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Start()
{



	//BG

	CreateActor<LineMain>(GameObjectGroup::WindowIcon);
	CreateActor<WebCamWindow>(GameObjectGroup::WindowIcon);
	CreateActor<Mouse>(GameObjectGroup::WindowIcon);
	CreateActor<ToolTip>(GameObjectGroup::WindowIcon);
	CreateActor<ToolTipText>(GameObjectGroup::WindowIcon);
	CreateActor<Stream>(GameObjectGroup::UI);
	CreateActor<DayChangeWindow>(GameObjectGroup::UI);

	//Icon
	CreateActor<WindowIcon>(GameObjectGroup::WindowIcon);
	CreateActor<MainBG>(GameObjectGroup::BackGround);
	CreateActor<SideBG>(GameObjectGroup::BackGround);
	//ingame
	CreateActor<LineText>();
	CreateActor<Change>(GameObjectGroup::WindowIcon);
	CreateActor<StreamAnimation>(GameObjectGroup::WindowIcon);
	CreateActor<Comment>(GameObjectGroup::WindowIcon);
	CreateActor<Twitter>(GameObjectGroup::WindowIcon);
	CreateActor<TweetComment>(GameObjectGroup::WindowIcon);



}
void PlayLevel::Update(float _DeltaTime)
{
	BGM();


	if (GlobalContentsValue::DayChangeWindow)
	{
		return;
	}
	time = time + GameEngineTime::GetDeltaTime();
	//bartime = bartime + GameEngineTime::GetDeltaTime();
	//if (time < -0.01f)
	//{
	//	time = 0.0f;
	//}
	//if (bartime > 1.0f)
	//{
	//	bartime = bartime - 1.0f;
	//	if (GlobalContentsValue::Tutorial == false)
	//	{
	//		CreateActor<Bar>(GameObjectGroup::WindowIcon);
	//	}
	//}
	if (time > 2.5f
		|| true == GameEngineInput::GetInst()->IsDown("MouseClick"))
	{
		time = time - 2.5f;
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
		CreateActor<TaskManager>(GameObjectGroup::WindowIcon);
		CreateActor<Bar>(GameObjectGroup::WindowIcon);
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

