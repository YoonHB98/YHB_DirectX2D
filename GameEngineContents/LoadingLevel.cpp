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
		GameEngineInput::GetInst()->CreateKey("LevelChange", 'P');
	}

	// 카메라를 먼저 만들어서 세계를 볼 준비를 하고
	GameEngineCameraActor* CameraActor = CreateActor<GameEngineCameraActor>();
	CameraActor->GetTransform().SetLocalPosition({ 0.0f, 0.0f, -100.0f });
	CameraActor->GetCameraComponent()->SetProjectionMode(CAMERAPROJECTIONMODE::Orthographic);



	// 세상에 보일 오브젝트들을 만들어서
	CreateActor<TitleLogo>(GameObjectGroup::BackGround);

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