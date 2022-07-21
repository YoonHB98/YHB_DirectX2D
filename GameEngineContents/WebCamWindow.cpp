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
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture("WebCam.png");
	Renderer->GetTransform().SetLocalPosition(float4(-90, 120));
	Renderer->ScaleToTexture();
}

void WebCamWindow::Update(float _DeltaTime)
{


}

void WebCamWindow::End()
{
}
