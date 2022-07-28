#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class Change : public DefaultSetTex
{
public:
	// constrcuter destructer
	Change();
	~Change();

	// delete Function
	Change(const Change& _Other) = delete;
	Change(Change&& _Other) noexcept = delete;
	Change& operator=(const Change& _Other) = delete;
	Change& operator=(Change&& _Other) noexcept = delete;

	GameEngineTextureRenderer* Bank;
	GameEngineSoundPlayer Sound;

	bool first = true;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	void BootEnd(const FrameAnimation_DESC&);
};

