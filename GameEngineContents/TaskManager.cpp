#include "PreCompile.h"
#include "TaskManager.h"

TaskManager::TaskManager()
{
}

TaskManager::~TaskManager()
{
}

void TaskManager::Start()
{
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture("TaskManager.png");
	Renderer->GetTransform().SetLocalPosition(float4(257, 170, 50));
	Renderer->GetTransform().SetLocalScale(float4(199, 178));
}

void TaskManager::Update(float _DeltaTime)
{
	ChangeZPos(0);

}

void TaskManager::End()
{
}
