#include "PreCompile.h"
#include "GameEngineActor.h"
#include "GameEngineComponent.h"
#include "GameEngineTransformComponent.h"

GameEngineActor::GameEngineActor()
	:ParentLevel(nullptr)
{
	Transform.GameEngineUpdateObject::SetParent(this);
}

GameEngineActor::~GameEngineActor()
{
	for (GameEngineComponent* Com : AllComList)
	{
		delete Com;
	}

	for (GameEngineTransformComponent* Com : AllTransComList)
	{
		delete Com;
	}
}

void GameEngineActor::Start() {}
void GameEngineActor::Update(float _DeltaTime) {}

void GameEngineActor::ComponentUpdate(float _ScaleDeltaTime, float _DeltaTime)
{
	for (GameEngineComponent* Com : AllComList)
	{
		Com->AddAccTime(_DeltaTime);
		Com->Update(_ScaleDeltaTime);
	}
}

void GameEngineActor::SettingTransformComponent(GameEngineTransformComponent* TransCom)
{
	TransCom->GetTransform().SetParent(GetTransform());
}

void GameEngineActor::ComponentCalculateTransform()
{
	for (GameEngineTransformComponent* Com : AllTransComList)
	{
		Com->GetTransform().CalculateWorld();
	}
}