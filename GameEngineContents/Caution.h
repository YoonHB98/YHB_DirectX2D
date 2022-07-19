#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :
enum LoginState
{
	Login,
	Data1,
	Max,
};

class GameEngineTextureRenderer;
class Caution : public GameEngineActor
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

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:
	LoginState CurState_;
	void ChangeState(LoginState _State);
	void StateUpdate();

private:
	void LoginStart();
	void Data1Start();

};

