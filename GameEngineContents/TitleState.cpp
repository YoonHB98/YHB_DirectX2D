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
	if (true == GameEngineInput::GetInst()->IsDown("LevelChange"))
	{
		ChangeState(LoginState::Login);
	}
}

void Caution::UpdateData1()
{
	if (true == GameEngineInput::GetInst()->IsDown("LevelChange"))
	{
		ChangeState(LoginState::Welcome);
	}
}

void Caution::UpdateLogin()
{
	if (true == GameEngineInput::GetInst()->IsDown("LevelChange"))
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