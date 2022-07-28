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
	CreateActor<TaskManager>(GameObjectGroup::WindowIcon);
	CreateActor<Bar>(GameObjectGroup::WindowIcon);
	CreateActor<Mouse>();

	//Icon
	CreateActor<WindowIcon>(GameObjectGroup::WindowIcon);

	//ingame






}
void PlayLevel::Update(float _DeltaTime)
{
	time = time + GameEngineTime::GetDeltaTime();
	if (time > 1.0f)
	{

		time = time - 1.0f;
		CreateActor<Bar>(GameObjectGroup::WindowIcon);

		if ( GlobalContentsValue::Message)
		{
			GlobalContentsValue::RemainLinenum = GlobalContentsValue::RemainLinenum - 1;
			CreateActor<Notification>(GameObjectGroup::WindowIcon);
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



}
void PlayLevel::End() {}
