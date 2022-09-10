#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class Asobu_Game : public DefaultSetTex
{
public:
	// constrcuter destructer
	Asobu_Game();
	~Asobu_Game();

	// delete Function
	Asobu_Game(const Asobu_Game& _Other) = delete;
	Asobu_Game(Asobu_Game&& _Other) noexcept = delete;
	Asobu_Game& operator=(const Asobu_Game& _Other) = delete;
	Asobu_Game& operator=(Asobu_Game&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	GameEngineTextureRenderer* BG;
	Myfont* Font;
	std::string CheckDayTime(int DayTime);
};

