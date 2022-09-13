#include "PreCompile.h"
#include "TestLevel.h"
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
#include "LineMain.h"
#include "LineText.h"
#include "Mouse.h"
#include "Twitter.h"
#include "Asobu_Talk.h"
#include "Asobu_Game.h"
#include "Asobu_That.h"
#include "Asobu_Window.h"


TestLevel::TestLevel() 
{
}

TestLevel::~TestLevel() 
{
}

void TestLevel::Start()
{	
	CreateActor<MainBG>(GameObjectGroup::BackGround);
	CreateActor<SideBG>(GameObjectGroup::BackGround);
	//CreateActor<WindowIcon>();
	CreateActor<Asobu_That>();
	CreateActor<Asobu_Window>();
	//GameEngineActor* StreamActor = CreateActor<Stream>(GameObjectGroup::UI);
	//GameEngineActor* CommentActor = CreateActor<Comment>(GameObjectGroup::WindowIcon);
	//GameEngineActor* StreamAnimationActor = CreateActor<StreamAnimation>(GameObjectGroup::WindowIcon);
	//CommentActor->SetParent(StreamActor);
	//StreamAnimationActor->SetParent(StreamActor);
	//CreateActor<Stream>();
	//CreateActor<StreamAnimation>();
	//CreateActor<LineMain>();
	//CreateActor<Mouse>();
	//CreateActor<LineText>();
	//CreateActor<Twitter>();
	//CreateActor<Change>(GameObjectGroup::WindowIcon);
	//CreateActor<StreamAnimation>(GameObjectGroup::WindowIcon);
	//CreateActor<Comment>(GameObjectGroup::WindowIcon);
	//CreateActor<Twitter>(GameObjectGroup::WindowIcon);
	//CreateActor<TweetComment>(GameObjectGroup::WindowIcon);
}

void TestLevel::Update(float _DeltaTime)
{
	GlobalContentsValue::Stream = true;
	//time = time + _DeltaTime;
	//if (time > 5.0f
	//	&& time < 8.0f)
	//{
	//	time = 10.0f;
	//	GlobalContentsValue::Followers = GlobalContentsValue::Followers + 1000;
	//}

	/*if (GameEngineInput::GetInst()->IsDown("FreeCameaOnOff"))
	{
		GetMainCameraActor()->FreeCameraModeOnOff();
	}
	GlobalContentsValue::Line = true;
	GlobalContentsValue::EomticonStatus = 2;
	if (time > 2.5f
		|| true == GameEngineInput::GetInst()->IsDown("MouseClick"))
	{
		time = time - 2.5f;
		if (GlobalContentsValue::Message)
		{
			GlobalContentsValue::RemainLinenum = GlobalContentsValue::RemainLinenum -1;
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
	}*/
	// 레벨 바뀌어서 오면 초기화
	// GetAccTime();

}

void TestLevel::End()
{
	int a = 0;
}