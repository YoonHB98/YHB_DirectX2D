#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :
enum LoginState
{
	Idle,
	Login,
	Data1,
	Welcome,
	Max,
};

class GameEngineTextureRenderer;
class Caution : public DefaultSetTex
{
public:
	// constrcuter destructer
	Caution();
	~Caution();

	// delete Function
	Caution(const Caution& _Other) = delete;
	Caution(Caution&& _Other) noexcept = delete;
	Caution& operator=(const Caution& _Other) = delete;
	Caution& operator=(Caution&& _Other) noexcept = delete;
	GameEngineTextureRenderer* Renderer;
	GameEngineSoundPlayer BgmPlayer;

	GameEngineTextureRenderer* Test;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:
	float Time = 0;
	LoginState CurState_;
	void ChangeState(LoginState _State);
	void StateUpdate();

private:
	int A = 0;

	void IdleStart();
	void LoginStart();
	void Data1Start();
	void WelcomeStart();

	void UpdateIdle();
	void UpdateLogin();
	void UpdateData1();
	void UpdateWelcome();

	bool MouseCheck = false;
	bool MouseCollision(GameEngineCollision* _This, GameEngineCollision* _Other);
	GameEngineCollision* Collision;
};

