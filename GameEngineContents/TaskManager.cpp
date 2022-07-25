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
	Renderer->GetTransform().SetLocalPosition(float4(257, 170, -30));
	Renderer->GetTransform().SetLocalScale(float4(199, 178));
}

void TaskManager::Update(float _DeltaTime)
{


}

void TaskManager::End()
{
}
