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
	SetLocalScale(float4(32, 32));

	GameEngineCollision* Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalScale({ 32.0f,8.0f,2000.0f });
	Collision->GetTransform().SetLocalPosition(float4(0, 12, 0));
	Collision->ChangeOrder(OBJECTORDER::Mouse);
}

void Mouse::Update(float _DeltaTime)
{
	ShowCursor(0);
	float4 Pos = GetLevel()->GetMainCamera()->GetMouseWorldPosition();
	GlobalContentsValue::MousePos = Pos;
	GetTransform().SetWorldPosition(float4(Pos.x, Pos.y , -5000));
}

void Mouse::End()
{
}