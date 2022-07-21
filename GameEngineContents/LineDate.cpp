#include "PreCompile.h"
#include "LineDate.h"

LineDate::LineDate()
{
}

LineDate::~LineDate()
{
}

void LineDate::Start()
{
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture("LineDate.png");
	Renderer->GetTransform().SetLocalPosition(float4(202, -74));
	Renderer->ScaleToTexture();
}

void LineDate::Update(float _DeltaTime)
{


}

void LineDate::End()
{
}
