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


TestLevel::TestLevel() 
{
}

TestLevel::~TestLevel() 
{
}

void TestLevel::Start()
{
	//CreateActor<Stream>();
	CreateActor<StreamAnimation>();

//	CreateActor<LineText>();
	//CreateActor<Change>(GameObjectGroup::WindowIcon);
	//CreateActor<StreamAnimation>(GameObjectGroup::WindowIcon);
	//CreateActor<Comment>(GameObjectGroup::WindowIcon);
	//CreateActor<Twitter>(GameObjectGroup::WindowIcon);
	//CreateActor<TweetComment>(GameObjectGroup::WindowIcon);
}

void TestLevel::Update(float _DeltaTime)
{
	GlobalContentsValue::Stream = true;
	// 레벨 바뀌어서 오면 초기화
	// GetAccTime();

}

void TestLevel::End()
{
	int a = 0;
}