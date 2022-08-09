#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class LineText : public DefaultSetTex
{
public:
	// constrcuter destructer
	LineText();
	~LineText();

	// delete Function
	LineText(const LineText& _Other) = delete;
	LineText(LineText&& _Other) noexcept = delete;
	LineText& operator=(const LineText& _Other) = delete;
	LineText& operator=(LineText&& _Other) noexcept = delete;

	GameEngineTextureRenderer* Renderer1;
	GameEngineTextureRenderer* Renderer2;
	GameEngineTextureRenderer* Renderer3;
	GameEngineTextureRenderer* Renderer4;
	GameEngineTextureRenderer* Renderer5;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

	void CreateText(std::string _Text);
	int TextNum = 0;
	int Count = 0;
	float time = 0;
	bool Tutorial = false;
private:
	std::vector<GameEngineTextureRenderer*> Text;
};

