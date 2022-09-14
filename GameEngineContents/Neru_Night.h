#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class Neru_Night : public DefaultSetTex
{
public:
	// constrcuter destructer
	Neru_Night();
	~Neru_Night();

	// delete Function
	Neru_Night(const Neru_Night& _Other) = delete;
	Neru_Night(Neru_Night&& _Other) noexcept = delete;
	Neru_Night& operator=(const Neru_Night& _Other) = delete;
	Neru_Night& operator=(Neru_Night&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	GameEngineTextureRenderer* BG;
	Myfont* Font;
	std::string CheckDayTime(int DayTime);
};

