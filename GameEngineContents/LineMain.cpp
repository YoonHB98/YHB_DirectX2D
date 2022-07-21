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

void LineMain::LineDate()
{
	/*if (CurDayState != )
	{

	}*/
}
