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
	Renderer->GetTransform().SetLocalPosition(float4(202, -74,-30));
	Renderer->ScaleToTexture();
}

void LineMain::Update(float _DeltaTime)
{


}

void LineMain::End()
{
}


