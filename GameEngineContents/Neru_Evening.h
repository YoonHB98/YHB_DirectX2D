#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class Neru_Evening : public DefaultSetTex
{
public:
	// constrcuter destructer
	Neru_Evening();
	~Neru_Evening();

	// delete Function
	Neru_Evening(const Neru_Evening& _Other) = delete;
	Neru_Evening(Neru_Evening&& _Other) noexcept = delete;
	Neru_Evening& operator=(const Neru_Evening& _Other) = delete;
	Neru_Evening& operator=(Neru_Evening&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	GameEngineTextureRenderer* BG;
	Myfont* Font;
	std::string CheckDayTime(int DayTime);
};

