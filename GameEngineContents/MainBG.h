#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :


class GameEngineTextureRenderer;
class MainBG : public GameEngineActor
{
public:
	// constrcuter destructer
	MainBG();
	~MainBG();

	// delete Function
	MainBG(const MainBG& _Other) = delete;
	MainBG(MainBG&& _Other) noexcept = delete;
	MainBG& operator=(const MainBG& _Other) = delete;
	MainBG& operator=(MainBG&& _Other) noexcept = delete;

	GameEngineTextureRenderer* MiddleBG;
	GameEngineSoundPlayer BgmPlayer;
	CommentTextureRenderer* Day;
	CommentTextureRenderer* DayTime;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:

};

