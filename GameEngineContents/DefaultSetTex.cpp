#include "PreCompile.h"
#include "DefaultSetTex.h"

DefaultSetTex::DefaultSetTex()
{
}

DefaultSetTex::~DefaultSetTex()
{
}

void DefaultSetTex::SetTexture(std::string Name)
{
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture(Name);
}

void DefaultSetTex::SetLocalPosition(float4 Pos)
{
	Renderer->GetTransform().SetLocalPosition(Pos);
}

void DefaultSetTex::SetLocalScale(float4 Scale)
{
	Renderer->GetTransform().SetLocalScale(Scale);
}

void DefaultSetTex::Start()
{
}

void DefaultSetTex::Update(float _DeltaTime)
{
}

void DefaultSetTex::End()
{
}
