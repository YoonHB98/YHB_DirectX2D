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
	TextRenderer = CreateComponent<GameEngineTextureRenderer>();
	TextRenderer->SetTexture("TutorialTooltip_1.png");
	TextRenderer->GetTransform().SetLocalPosition(float4(-36.5, 42, 500));
	TextRenderer->SetRenderingOrder(2);

}

void ToolTipText::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Tooltip)
	{
		Pos = GlobalContentsValue::MousePos;
		GetTransform().SetWorldPosition(float4(Pos.x - 117, Pos.y + 42, -1000));
		if (GlobalContentsValue::TutorialLogin == true)
		{
			GlobalContentsValue::Tooltip = false;
		}
	}
	else
	{
		GetTransform().SetWorldPosition(float4(Pos.x, Pos.y, 540));
		return;
	}
	TextRenderer->SetTexture("TutorialTooltip_" + std::to_string(Count) + ".png");
	TextRenderer->ScaleToTexture();
	Size = TextRenderer->GetTransform().GetLocalScale();
	TextRenderer->GetTransform().SetLocalPosition(float4(100 - (Size.x / 2), 15.5f+ (Size.y / 2), 500));
	if (Count == 7
		&&true == GameEngineInput::GetInst()->IsDown("MouseClick"))
	{
		Count = Count + 1;
		GlobalContentsValue::Tooltip = false;
		GlobalContentsValue::Contents = "";
	}
}

void ToolTipText::End()
{
}

int ToolTipText::Count = 1;