#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :


class GameEngineTextureRenderer;
class TaskManager : public DefaultSetTex
{
public:
	static void Destroy()
	{
		if (nullptr != Inst_)
		{
			delete Inst_;
			Inst_ = nullptr;
		}
	}
public:
	// constrcuter destructer
	TaskManager();
	~TaskManager();

	// delete Function
	TaskManager(const TaskManager& _Other) = delete;
	TaskManager(TaskManager&& _Other) noexcept = delete;
	TaskManager& operator=(const TaskManager& _Other) = delete;
	TaskManager& operator=(TaskManager&& _Other) noexcept = delete;

	static TaskManager* Inst_;
	GameEngineTextureRenderer* Renderer;
	GameEngineCollision* TaskManagerMainCol;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:

};

