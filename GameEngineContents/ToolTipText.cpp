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
	TextRenderer->SetRenderingOrder(501);

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
	if (CurString != GlobalContentsValue::Contents)
	{
		CurString = GlobalContentsValue::Contents;
		Count = 1;
	}
	ContentsCheck();



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

void ToolTipText::ContentsCheck()
{
	if (GlobalContentsValue::Contents == "Tutorial")
	{
		TextRenderer->GetTransform().SetLocalPosition(float4(100 - (Size.x / 2), 15.5f + (Size.y / 2), 500));
		TextRenderer->SetTexture(GlobalContentsValue::Contents + "Tooltip_" + std::to_string(Count) + ".png");
		TextRenderer->ScaleToTexture();
		Size = TextRenderer->GetTransform().GetLocalScale();
	}
	else
		//TextRenderer->GetTransform().SetLocalPosition(float4(100, -20.5f + (Size.y / 2), 500));
		//TextRenderer->SetPivot(PIVOTMODE::LEFT);
		//TextRenderer->SetTexture(GlobalContentsValue::Contents + "Tooltip_" + std::to_string(Count) + ".png");
		//TextRenderer->ScaleToTexture();
		//Size = TextRenderer->GetTransform().GetLocalScale();
	if (GlobalContentsValue::Contents + "Tooltip_" + std::to_string(Count) == "CommunicationStartToolTip_2")
	{
		TextRenderer->SetTexture(GlobalContentsValue::Contents + "Tooltip_" + std::to_string(Count) + ".png");
		TextRenderer->ScaleToTexture();
		Size = TextRenderer->GetTransform().GetLocalScale();
		if (GameEngineInput::GetInst()->IsDown("MouseClick"));
	}

}


int ToolTipText::Count = 1;