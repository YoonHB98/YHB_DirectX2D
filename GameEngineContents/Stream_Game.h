#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class Stream_Game : public DefaultSetTex
{
public:
	// constrcuter destructer
	Stream_Game();
	~Stream_Game();

	// delete Function
	Stream_Game(const Stream_Game& _Other) = delete;
	Stream_Game(Stream_Game&& _Other) noexcept = delete;
	Stream_Game& operator=(const Stream_Game& _Other) = delete;
	Stream_Game& operator=(Stream_Game&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	GameEngineTextureRenderer* BG;
	Myfont* Font;
	std::string CheckDayTime(int DayTime);
};

