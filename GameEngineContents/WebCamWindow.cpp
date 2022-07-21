#include "PreCompile.h"
#include "WebCamWindow.h"

WebCamWindow::WebCamWindow()
{
}

WebCamWindow::~WebCamWindow()
{
}

void WebCamWindow::Start()
{
	// 25 ¿Ã¸®¸é µÊ
	GlobalContentsValue::LineNum = GlobalContentsValue::LineNum + 1;
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture("WebCamWindow.png");
	Renderer->GetTransform().SetLocalPosition(float4(202, -74));
	Renderer->ScaleToTexture();
}

void WebCamWindow::Update(float _DeltaTime)
{


}

void WebCamWindow::End()
{
}
