#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class StreamAnimation : public DefaultSetTex
{
public:
	// constrcuter destructer
	StreamAnimation();
	~StreamAnimation();

	// delete Function
	StreamAnimation(const StreamAnimation& _Other) = delete;
	StreamAnimation(StreamAnimation&& _Other) noexcept = delete;
	StreamAnimation& operator=(const StreamAnimation& _Other) = delete;
	StreamAnimation& operator=(StreamAnimation&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

	bool first = true;
private:

};

