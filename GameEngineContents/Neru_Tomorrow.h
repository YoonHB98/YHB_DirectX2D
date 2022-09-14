#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class Neru_Tomorrow : public DefaultSetTex
{
public:
	// constrcuter destructer
	Neru_Tomorrow();
	~Neru_Tomorrow();

	// delete Function
	Neru_Tomorrow(const Neru_Tomorrow& _Other) = delete;
	Neru_Tomorrow(Neru_Tomorrow&& _Other) noexcept = delete;
	Neru_Tomorrow& operator=(const Neru_Tomorrow& _Other) = delete;
	Neru_Tomorrow& operator=(Neru_Tomorrow&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	GameEngineTextureRenderer* BG;
	Myfont* Font;
	std::string CheckDayTime(int DayTime);
};

