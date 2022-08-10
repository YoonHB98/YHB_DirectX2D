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
	SetTexture("TutorialTooltip_1.png");
	SetLocalPosition(float4(-36.5, 42, 500));

}

void ToolTipText::Update(float _DeltaTime)
{
	SetTexture("TutorialTooltip_" + std::to_string(Count) + ".png");
	Renderer->ScaleToTexture();
	Size = Renderer->GetTransform().GetLocalScale();
	SetLocalPosition(float4(100 - (Size.x / 2), 42, 500));
	if (GlobalContentsValue::Tooltip)
	{
		Pos = GlobalContentsValue::MousePos;
		GetTransform().SetWorldPosition(float4(Pos.x - 117, Pos.y + 42, -540));
		if (GlobalContentsValue::TutorialLogin == true)
		{
			GlobalContentsValue::Tooltip = false;
		}
	}
	else
	{
		GetTransform().SetWorldPosition(float4(Pos.x, Pos.y, 540));
	}
}

void ToolTipText::End()
{
}

int ToolTipText::Count = 1;