#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class Asobu : public DefaultSetTex
{
public:
	// constrcuter destructer
	Asobu();
	~Asobu();

	// delete Function
	Asobu(const Asobu& _Other) = delete;
	Asobu(Asobu&& _Other) noexcept = delete;
	Asobu& operator=(const Asobu& _Other) = delete;
	Asobu& operator=(Asobu&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	GameEngineTextureRenderer* BG;
	Myfont* Font;
};

