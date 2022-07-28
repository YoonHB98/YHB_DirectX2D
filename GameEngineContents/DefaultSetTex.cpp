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

void DefaultSetTex::ChangeForward(GameEngineTextureRenderer* Renderer, const float z)
{
	float x = Renderer->GetTransformData().LocalPosition.x;
	float y =Renderer->GetTransformData().LocalPosition.y;
	Renderer->GetTransform().SetLocalScale(float4(x,y,z));
}

void DefaultSetTex::ChangeZPos(float Z)
{
	float4 CurPos = GetTransform().GetLocalPosition();
	CurPos.z = Z;
	GetTransform().SetWorldPosition(CurPos);
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
