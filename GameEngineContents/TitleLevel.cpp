#include "PreCompile.h"
#include "TitleLevel.h"
#include "Caution.h"
#include "Enums.h"
#include "Mouse.h"
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
	CreateActor<Caution>(GameObjectGroup::BackGround);
	CreateActor<Mouse>();
}

void TitleLevel::Update(float _DeltaTime)
{
	// ���� �ٲ� ���� �ʱ�ȭ
	// GetAccTime();

}

void TitleLevel::End()
{
	int a = 0;
}