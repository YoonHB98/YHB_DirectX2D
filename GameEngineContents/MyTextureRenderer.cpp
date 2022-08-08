#include "PreCompile.h"
#include "MyTextureRenderer.h"



MyTextureRenderer::MyTextureRenderer() 
{
}

MyTextureRenderer::~MyTextureRenderer() 
{
}

void MyTextureRenderer::SetTextureRendererSetting()
{

	SetPipeLine("TextureAtlas");

	FrameData.PosX = 0.0f;
	FrameData.PosY = 0.0f;
	FrameData.SizeX = 1.0f;
	FrameData.SizeY = 1.0f;

	ShaderResources.SetConstantBufferLink("AtlasData", FrameData);
	ShaderResources.SetConstantBufferLink("MyColorData", ColorData);

}