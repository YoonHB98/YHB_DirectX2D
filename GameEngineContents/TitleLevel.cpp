#include "PreCompile.h"
#include "TitleLevel.h"
#include "Caution.h"
#include "Enums.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineBase/GameEngineInput.h>

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}


void TitleLevel::Start()
{
	if (false == GameEngineInput::GetInst()->IsKey("LevelChange"))
	{
		GameEngineInput::GetInst()->CreateKey("LevelChange", 'P');
	}


	CreateActor<Caution>(GameObjectGroup::BackGround);

}

void TitleLevel::Update(float _DeltaTime)
{
	// 레벨 바뀌어서 오면 초기화
	// GetAccTime();

}

void TitleLevel::End()
{
	int a = 0;
}