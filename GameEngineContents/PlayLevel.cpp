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


PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Start()
{



	//BG
	CreateActor<MainBG>(GameObjectGroup::BackGround);
	CreateActor<SideBG>(GameObjectGroup::BackGround);
	CreateActor<LineMain>(GameObjectGroup::WindowIcon);
	CreateActor<WebCamWindow>(GameObjectGroup::WindowIcon);
	CreateActor<Mouse>();
	CreateActor<ToolTip>();
	CreateActor<ToolTipText>();
	CreateActor<Stream>(GameObjectGroup::WindowIcon);

	//Icon
	CreateActor<WindowIcon>(GameObjectGroup::WindowIcon);

	//ingame
	CreateActor<LineText>();
	CreateActor<Change>();
	CreateActor<StreamAnimation>();





}
void PlayLevel::Update(float _DeltaTime)
{
	time = time + GameEngineTime::GetDeltaTime();
	if (time > 1.0f)
	{

		time = time - 1.0f;
		if (GlobalContentsValue::Tutorial == false)
		{
			CreateActor<Bar>(GameObjectGroup::WindowIcon);
		}


		if ( GlobalContentsValue::Message)
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
void PlayLevel::End() {}

