#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class ToolTipText : public DefaultSetTex
{
public:
	// constrcuter destructer
	ToolTipText();
	~ToolTipText();

	// delete Function
	ToolTipText(const ToolTipText& _Other) = delete;
	ToolTipText(ToolTipText&& _Other) noexcept = delete;
	ToolTipText& operator=(const ToolTipText& _Other) = delete;
	ToolTipText& operator=(ToolTipText&& _Other) noexcept = delete;

	static int Count;
	std::string CurString = "";
	float4 Size;
	GameEngineTextureRenderer* TextRenderer;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	float4 Pos;
};

