#include "PreCompile.h"
#include "GameEngineActor.h"
#include "GameEngineComponent.h"
#include "GameEngineTransformComponent.h"

GameEngineActor::GameEngineActor()
	:ParentLevel(nullptr)
{

}

GameEngineActor::~GameEngineActor()
{
}

void GameEngineActor::Start() {}
void GameEngineActor::Update(float _DeltaTime) {}
void GameEngineActor::End() {}

void GameEngineActor::ComponentUpdate(float _ScaleDeltaTime, float _DeltaTime)
{
	for (GameEngineComponent* Com : AllComList)
	{
		Com->AddAccTime(_DeltaTime);
		Com->Update(_ScaleDeltaTime);
	}
}
void GameEngineActor::DetachObject()
{
	GameEngineUpdateObject::DetachObject();

	GetTransform().DetachTransform();
}

void GameEngineActor::SetParent(GameEngineUpdateObject* _Object)
{
	GameEngineUpdateObject::SetParent(_Object);

	{
		GameEngineTransformBase* Actor = nullptr;
		if (Actor = dynamic_cast<GameEngineTransformBase*>(_Object))
		{
			GetTransform().SetParentTransform(Actor->GetTransform());
			return;
		}
	}

	MsgBoxAssert("Ʈ�������� ���� ������Ʈ�� Ʈ�������� �ִ� �θ� ���̷��� �߽��ϴ�.");
}