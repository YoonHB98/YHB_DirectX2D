#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :


class GameEngineTextureRenderer;
class NumUpdate : public GameEngineActor
{
public:
	// constrcuter destructer
	NumUpdate();
	~NumUpdate();

	// delete Function
	NumUpdate(const NumUpdate& _Other) = delete;
	NumUpdate(NumUpdate&& _Other) noexcept = delete;
	NumUpdate& operator=(const NumUpdate& _Other) = delete;
	NumUpdate& operator=(NumUpdate&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:

};

