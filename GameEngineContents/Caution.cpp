#include "PreCompile.h"
#include "Caution.h"
#include <GameEngineCore/GEngine.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

Caution::Caution()
{
}

Caution::~Caution()
{
}

void Caution::ChangeState(LoginState _State)
{
	if (CurState_ != _State)
	{

		switch (_State)
		{
		case Login:
			LoginStart();
			break;
		case Data1:
			Data1Start();
			break;
		case Welcome:
			WelcomeStart();
		case Max:
			break;
		default:
			break;
		}
	}

	CurState_ = _State;
}

void Caution::StateUpdate()
{
		switch (CurState_)
		{
		case Idle:
			UpdateIdle();
				break;
		case Login:
			UpdateLogin();
			break;
		case Data1:
			UpdateData1();
			break;
		case Welcome:
			UpdateWelcome();
		case Max:
			break;
		default:
			break;
		}
}





void Caution::Start()
{
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture("SetUp.png");
	Renderer->ScaleToTexture();

}

void Caution::Update(float _DeltaTime)
{

		if (A == 0)
		{
			BgmPlayer = GameEngineSound::SoundPlayControl("OP_PV.wav");
			GameEngineSound::SoundPlayOneShot("Boot_Caution.wav", 0);
			A = 1;
		}

		StateUpdate();
}

void Caution::End()
{
	int a = 0;
}