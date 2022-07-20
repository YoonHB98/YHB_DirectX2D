#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :


class GameEngineTextureRenderer;
class Notification : public GameEngineActor
{
public:
	// constrcuter destructer
	Notification();
	~Notification();

	// delete Function
	Notification(const Notification& _Other) = delete;
	Notification(Notification&& _Other) noexcept = delete;
	Notification& operator=(const Notification& _Other) = delete;
	Notification& operator=(Notification&& _Other) noexcept = delete;

	GameEngineTextureRenderer* Tuuti;
	GameEngineTextureRenderer* Tuuti2;
	GameEngineTextureRenderer* Line;
	GameEngineSoundPlayer BgmPlayer;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:

};

