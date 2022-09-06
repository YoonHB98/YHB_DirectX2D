#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :


class GameEngineTextureRenderer;
class Bar : public DefaultSetTex
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
	void BarMake();
	void BarMove();
	std::vector<CommentTextureRenderer*> MentalStack;
	std::vector<CommentTextureRenderer*> StressStack;
	std::vector<CommentTextureRenderer*> AffectionStack;
	float time;
	float time2;
	int BarCount = 0;
	float BarTime= 0;
	int count = 0;
	bool StartCheck = false;
};

