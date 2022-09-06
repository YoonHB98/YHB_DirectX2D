#include "PreCompile.h"
#include "CommentTextureRenderer.h"

CommentTextureRenderer::CommentTextureRenderer() 
{
}

CommentTextureRenderer::~CommentTextureRenderer() 
{
}

void CommentTextureRenderer::Start()
{
	GameEngineDefaultRenderer::Start();

	PushRendererToMainCamera();

	SetTextureRendererSetting();
}

void CommentTextureRenderer::SetTextureRendererSetting()
{
	SetPipeLine("CommentTexture");

	FrameData.PosX = 0.0f;
	FrameData.PosY = 0.0f;
	FrameData.SizeX = 1.0f;
	FrameData.SizeY = 1.0f;

	Clip.PosX = 1200.0f;
	Clip.PosY = 0.0f;
	Clip.SizeX = 0.0f;
	Clip.SizeY = 0.0f;

	ShaderResources.SetConstantBufferLink("AtlasData", FrameData);
	ShaderResources.SetConstantBufferLink("Clip", Clip);
}

