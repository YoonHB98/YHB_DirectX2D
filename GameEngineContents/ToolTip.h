#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class ToolTip : public DefaultSetTex
{
public:
	// constrcuter destructer
	ToolTip();
	~ToolTip();

	// delete Function
	ToolTip(const ToolTip& _Other) = delete;
	ToolTip(ToolTip&& _Other) noexcept = delete;
	ToolTip& operator=(const ToolTip& _Other) = delete;
	ToolTip& operator=(ToolTip&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	float4 Pos;
};

