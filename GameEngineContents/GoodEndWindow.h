#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class GoodEndWindow : public DefaultSetTex
{
public:
	// constrcuter destructer
	GoodEndWindow();
	~GoodEndWindow();

	// delete Function
	GoodEndWindow(const GoodEndWindow& _Other) = delete;
	GoodEndWindow(GoodEndWindow&& _Other) noexcept = delete;
	GoodEndWindow& operator=(const GoodEndWindow& _Other) = delete;
	GoodEndWindow& operator=(GoodEndWindow&& _Other) noexcept = delete;

	GameEngineCollision* MainCol;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:

};

