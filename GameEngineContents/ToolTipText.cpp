#include "PreCompile.h"
#include "ToolTipText.h"

ToolTipText::ToolTipText() 
{
}

ToolTipText::~ToolTipText() 
{
}

void ToolTipText::Start()
{
	SetTexture("TutorialTooltip_login.png");
	SetLocalPosition(float4(0, 42, 500));
	SetLocalScale(float4(203, 53));
}

void ToolTipText::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Tooltip)
	{
		Pos = GlobalContentsValue::MousePos;
		GetTransform().SetWorldPosition(float4(Pos.x - 117, Pos.y + 42, -540));
	}
	else
	{
		GetTransform().SetWorldPosition(float4(Pos.x, Pos.y, 540));
	}
}

void ToolTipText::End()
{
}