#include "PreCompile.h"
#include "LineMain.h"

LineMain::LineMain()
{
}

LineMain::~LineMain()
{
}

void LineMain::Start()
{
	// 25 ¿Ã¸®¸é µÊ
	GlobalContentsValue::LineNum = GlobalContentsValue::LineNum + 1;
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture("LineMain.png");
	Renderer->GetTransform().SetLocalPosition(float4(202, -74));
	Renderer->ScaleToTexture();
}

void LineMain::Update(float _DeltaTime)
{


}

void LineMain::End()
{
}
