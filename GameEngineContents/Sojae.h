#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class Sojae : public DefaultSetTex
{
public:
	// constrcuter destructer
	Sojae();
	~Sojae();

	// delete Function
	Sojae(const Sojae& _Other) = delete;
	Sojae(Sojae&& _Other) noexcept = delete;
	Sojae& operator=(const Sojae& _Other) = delete;
	Sojae& operator=(Sojae&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	GameEngineCollision* MainCol;
};

