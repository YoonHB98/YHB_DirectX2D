#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class Stream : public DefaultSetTex
{
public:
	// constrcuter destructer
	Stream();
	~Stream();

	// delete Function
	Stream(const Stream& _Other) = delete;
	Stream(Stream&& _Other) noexcept = delete;
	Stream& operator=(const Stream& _Other) = delete;
	Stream& operator=(Stream&& _Other) noexcept = delete;

	GameEngineTextureRenderer* Haisin;
	GameEngineSoundPlayer  BgmPlayer;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	int first =true;
};

