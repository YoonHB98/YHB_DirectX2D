#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :
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


};

