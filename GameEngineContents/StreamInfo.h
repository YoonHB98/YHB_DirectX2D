#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class StreamInfo : public DefaultSetTex
{
public:
	// constrcuter destructer
	StreamInfo();
	~StreamInfo();

	// delete Function
	StreamInfo(const StreamInfo& _Other) = delete;
	StreamInfo(StreamInfo&& _Other) noexcept = delete;
	StreamInfo& operator=(const StreamInfo& _Other) = delete;
	StreamInfo& operator=(StreamInfo&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	Myfont* Info[5];
	float time = 0.0f;
	int Num = 0;
};

