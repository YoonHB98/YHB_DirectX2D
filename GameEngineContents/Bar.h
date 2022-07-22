#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :


class GameEngineTextureRenderer;
class Bar : public GameEngineActor
{
public:
	// constrcuter destructer
	Bar();
	~Bar();

	// delete Function
	Bar(const Bar& _Other) = delete;
	Bar(Bar&& _Other) noexcept = delete;
	Bar& operator=(const Bar& _Other) = delete;
	Bar& operator=(Bar&& _Other) noexcept = delete;

	GameEngineTextureRenderer* Mental;
	GameEngineTextureRenderer* Stress;
	GameEngineTextureRenderer* Affection;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	float time;
	float time2;
	int count = 0;
};

