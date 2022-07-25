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

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Start()
{


	{
		GameEngineCameraActor* actor = CreateActor<GameEngineCameraActor>();
		actor->GetCameraComponent()->SetProjectionMode(CAMERAPROJECTIONMODE::Orthographic);
		actor->GetTransform().SetLocalPosition({ 0.0f, 0.0f, -500.0f });
	}
	//BG
	CreateActor<MainBG>(GameObjectGroup::BackGround);
	CreateActor<SideBG>(GameObjectGroup::BackGround);
	CreateActor<LineMain>(GameObjectGroup::WindowIcon);
	CreateActor<WebCamWindow>(GameObjectGroup::WindowIcon);
	CreateActor<TaskManager>(GameObjectGroup::WindowIcon);
	CreateActor<Bar>(GameObjectGroup::WindowIcon);

	//Icon
	CreateActor<WindowIcon>(GameObjectGroup::WindowIcon);





}
void PlayLevel::Update(float _DeltaTime)
{
	time = time + GameEngineTime::GetDeltaTime();
	if (time > 1.0f)
	{
		time = time - 1.0f;
		CreateActor<Bar>(GameObjectGroup::WindowIcon);
	}

	if (GameEngineInput::GetInst()->IsDown("FreeCameaOnOff"))
	{
		GetMainCameraActor()->FreeCameraModeOnOff();
	}



}
void PlayLevel::End() {}
