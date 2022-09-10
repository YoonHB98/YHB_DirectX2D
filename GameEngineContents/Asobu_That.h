#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class Asobu_That : public DefaultSetTex
{
public:
	// constrcuter destructer
	Asobu_That();
	~Asobu_That();

	// delete Function
	Asobu_That(const Asobu_That& _Other) = delete;
	Asobu_That(Asobu_That&& _Other) noexcept = delete;
	Asobu_That& operator=(const Asobu_That& _Other) = delete;
	Asobu_That& operator=(Asobu_That&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	GameEngineTextureRenderer* BG;
	Myfont* Font;
	std::string CheckDayTime(int DayTime);
};

