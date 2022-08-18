#include "PreCompile.h"
#include "LineMain.h"
#include "LineDate.h"

LineMain::LineMain()
{
}

LineMain::~LineMain()
{
}

void LineMain::Start()
{
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture("LineMain.png");
	Renderer->GetTransform().SetLocalPosition(float4(202, -74));
	Renderer->ScaleToTexture();
}

void LineMain::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Line)
	{
		ChangeZPos(0);
	}
	else
	{
		ChangeZPos(500);
	}
}

void LineMain::End()
{
}


