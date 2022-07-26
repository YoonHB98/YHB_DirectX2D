#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :


class GameEngineTextureRenderer;
class TaskManager : public DefaultSetTex
{
public:
	// constrcuter destructer
	TaskManager();
	~TaskManager();

	// delete Function
	TaskManager(const TaskManager& _Other) = delete;
	TaskManager(TaskManager&& _Other) noexcept = delete;
	TaskManager& operator=(const TaskManager& _Other) = delete;
	TaskManager& operator=(TaskManager&& _Other) noexcept = delete;

	GameEngineTextureRenderer* Renderer;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:

};

