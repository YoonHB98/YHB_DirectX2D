#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class Twitter : public DefaultSetTex
{
public:
	// constrcuter destructer
	Twitter();
	~Twitter();

	// delete Function
	Twitter(const Twitter& _Other) = delete;
	Twitter(Twitter&& _Other) noexcept = delete;
	Twitter& operator=(const Twitter& _Other) = delete;
	Twitter& operator=(Twitter&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	CommentTextureRenderer* TextureRenderer;
	GameEngineTextureRenderer* Loading;
	GameEngineCollision* Exit;
	float Time;
	bool First = true;
};

