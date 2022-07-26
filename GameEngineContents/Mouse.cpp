#include "PreCompile.h"
#include "Mouse.h"

Mouse::Mouse() 
{
}

Mouse::~Mouse() 
{
}

void Mouse::Start()
{
	SetTexture("Cursor.png");
	SetLocalPosition(float4(0, 0, 0));
	SetLocalScale(float4(16, 16));
}

void Mouse::Update(float _DeltaTime)
{
	ShowCursor(0);
	float4 Pos = GetLevel()->GetMainCamera()->GetMouseWorldPosition();
	Renderer->GetTransform().SetWorldPosition(float4(Pos.x, Pos.y, -500));
}

void Mouse::End()
{
}