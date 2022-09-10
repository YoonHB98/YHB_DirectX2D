#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class Asobu_Talk : public DefaultSetTex
{
public:
	// constrcuter destructer
	Asobu_Talk();
	~Asobu_Talk();

	// delete Function
	Asobu_Talk(const Asobu_Talk& _Other) = delete;
	Asobu_Talk(Asobu_Talk&& _Other) noexcept = delete;
	Asobu_Talk& operator=(const Asobu_Talk& _Other) = delete;
	Asobu_Talk& operator=(Asobu_Talk&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	GameEngineTextureRenderer* BG;
	Myfont* Font;
	std::string CheckDayTime(int DayTime);
};

