#include "PreCompile.h"
#include "Caution.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

void Caution::LoginStart()
{
	Renderer->SetTexture("Login.png");
}

void Caution::Data1Start()
{
	Renderer->SetTexture("Data1.png");
}

void Caution::WelcomeStart()
{
	Renderer->SetTexture("Welcome.png");
}

void Caution::UpdateIdle()
{
	if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
		&&MouseCheck)
	{
		ChangeState(LoginState::Login);
	}
}

void Caution::UpdateData1()
{
	Collision->GetTransform().SetLocalPosition(float4{ 0,-62.5f,0 });
	Collision->GetTransform().SetLocalScale({ 98.0f, 19.0f, -200.0f });
	if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
		&&MouseCheck)
	{
		ChangeState(LoginState::Welcome);
	}
}

void Caution::UpdateLogin()
{
	Collision->GetTransform().SetLocalPosition(float4{ -140,16,0 });
	Collision->GetTransform().SetLocalScale({ 52.0f, 52.0f, -200.0f });
	if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
		&&MouseCheck)
	{
		GameEngineSound::SoundPlayOneShot("command_execute.wav");
		ChangeState(LoginState::Data1);
	}

}

void Caution::UpdateWelcome()
{
	Time = Time + GameEngineTime::GetDeltaTime();
	if (Time > 1.0f)
	{
		Time = Time - 99999;
		GameEngineSound::SoundPlayOneShot("Notification.wav", 1);
		BgmPlayer.Stop();
		GEngine::ChangeLevel("Play");
	}
}

bool Caution::MouseCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	return true;
}
