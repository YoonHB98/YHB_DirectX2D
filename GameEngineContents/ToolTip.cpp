#include "PreCompile.h"
#include "ToolTip.h"

ToolTip::ToolTip() 
{
}

ToolTip::~ToolTip() 
{
}

void ToolTip::Start()
{
	SetTexture("pien_tutorial.png");
	SetLocalPosition(float4(0, 42, 0));
	SetLocalScale(float4(56, 56));
}

void ToolTip::Update(float _DeltaTime)
{
	Pos = GlobalContentsValue::MousePos;
	GetTransform().SetWorldPosition(float4(Pos.x, Pos.y, -540));
}

void ToolTip::End()
{
}