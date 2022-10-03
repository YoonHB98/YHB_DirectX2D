#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class BadEndWindow : public DefaultSetTex
{
public:
	// constrcuter destructer
	BadEndWindow();
	~BadEndWindow();

	// delete Function
	BadEndWindow(const BadEndWindow& _Other) = delete;
	BadEndWindow(BadEndWindow&& _Other) noexcept = delete;
	BadEndWindow& operator=(const BadEndWindow& _Other) = delete;
	BadEndWindow& operator=(BadEndWindow&& _Other) noexcept = delete;

	GameEngineCollision* MainCol;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:

};

