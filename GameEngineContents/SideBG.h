#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :
enum DayState
{
	night,
	noon,
	evening,
	Max,
};


class GameEngineTextureRenderer;
class SideBG : public GameEngineActor
{
public:
	// constrcuter destructer
	SideBG();
	~SideBG();

	// delete Function
	SideBG(const SideBG& _Other) = delete;
	SideBG(SideBG&& _Other) noexcept = delete;
	SideBG& operator=(const SideBG& _Other) = delete;
	SideBG& operator=(SideBG&& _Other) noexcept = delete;

	GameEngineTextureRenderer* RightBG;
	GameEngineTextureRenderer* LeftBG;
	GameEngineSoundPlayer BgmPlayer;
	DayState CurState_;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	void ChangeState(DayState);
	void StartNight();
	void StartNoon();
	void StartEvening();
};

