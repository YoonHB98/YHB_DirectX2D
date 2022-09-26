#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class Stream_Talk : public DefaultSetTex
{
public:
	// constrcuter destructer
	Stream_Talk();
	~Stream_Talk();

	// delete Function
	Stream_Talk(const Stream_Talk& _Other) = delete;
	Stream_Talk(Stream_Talk&& _Other) noexcept = delete;
	Stream_Talk& operator=(const Stream_Talk& _Other) = delete;
	Stream_Talk& operator=(Stream_Talk&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	GameEngineTextureRenderer* BG;
	Myfont* Font;
	std::string CheckDayTime(int DayTime);
};

