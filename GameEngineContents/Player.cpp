#include "PreCompile.h"
#include "Player.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>

Player::Player()
{
}

Player::~Player()
{
}

GameEngineRenderer* CurRenderer;


void Player::Start()
{
	if (false == GameEngineInput::GetInst()->IsKey("Rot+"))
	{
		GameEngineInput::GetInst()->CreateKey("Rot+", 'G');
		GameEngineInput::GetInst()->CreateKey("Rot-", 'H');
	}



	GetTransform().SetLocalScale({ 1, 1, 1 });

	{
		CurRenderer = CreateComponent<GameEngineRenderer>();
		CurRenderer->GetTransform().SetLocalScale({ 100, 100, 100 });
	}

	{
		GameEngineRenderer* Renderer = CreateComponent<GameEngineRenderer>();
		Renderer->GetTransform().SetParent(CurRenderer->GetTransform());
		Renderer->GetTransform().SetLocalPosition({ 1.0f, 0.0f, 0.0f });
		Renderer->GetTransform().DebugOn();
		Renderer->DebugOn();
	}
}

void Player::Update(float _DeltaTime)
{
	if (true == GameEngineInput::GetInst()->IsPress("Rot+"))
	{
		CurRenderer->GetTransform().SetLocalRotate({ 0.0f, 0.0f, 360.0f * _DeltaTime });
	}
	if (true == GameEngineInput::GetInst()->IsPress("Rot-"))
	{
		CurRenderer->GetTransform().SetLocalRotate({ 0.0f, 0.0f, -360.0f * _DeltaTime });
	}
}