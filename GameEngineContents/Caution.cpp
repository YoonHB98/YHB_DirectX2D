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
		case Max:
			break;
		default:
			break;
		}
	}

	CurState_ = _State;
}




void Caution::Start()
{
	// 1280 720

}

void Caution::Update(float _DeltaTime)
{
			Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 960, 540, 0 });
		Renderer->SetTexture("SetUp.png");
		if (GlobalContentsValue::Title == false)
		{
			BgmPlayer = GameEngineSound::SoundPlayControl("OP_PV.wav");
			GameEngineSound::SoundPlayOneShot("Boot_Caution.wav", 0);
			GlobalContentsValue::Title = true;
		}
		if (true == GameEngineInput::GetInst()->IsDown("LevelChange"))
		{
			Renderer->SetTexture("login.png");
		}
}

void Caution::End()
{
	int a = 0;
}