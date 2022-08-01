#include "PreCompile.h"
#include "LoadingLevel.h"
#include "TitleLogo.h"
#include "Enums.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineBase/GameEngineInput.h>

LoadingLevel::LoadingLevel() 
{
}

LoadingLevel::~LoadingLevel() 
{
}


void LoadingLevel::Start() 
{
	if (false == GameEngineInput::GetInst()->IsKey("LevelChange"))
	{
		GameEngineInput::GetInst()->CreateKey("MouseClick", VK_LBUTTON);
	}

	if (false == GameEngineInput::GetInst()->IsKey("FreeCameaOnOff"))
	{
		GameEngineInput::GetInst()->CreateKey("FreeCameaOnOff", 'O');
	}



	CreateActor<TitleLogo>(GameObjectGroup::BackGround);
	ShowCursor(0);

}

void LoadingLevel::Update(float _DeltaTime)
{


	// 레벨 바뀌어서 오면 초기화
	// GetAccTime();
	
}

void LoadingLevel::End() 
{
	int a = 0;
}