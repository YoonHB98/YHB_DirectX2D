#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// ���� :
class PlayLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	PlayLevel();
	~PlayLevel();

	// delete Function
	PlayLevel(const PlayLevel& _Other) = delete;
	PlayLevel(PlayLevel&& _Other) noexcept = delete;
	PlayLevel& operator=(const PlayLevel& _Other) = delete;
	PlayLevel& operator=(PlayLevel&& _Other) noexcept = delete;
	static float time;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:
	int a = 0;
	float bartime = 0;
	bool first = true;
	bool TutorialFirst = true;
	bool TutorialLoginFirst = true;

	GameEngineActor* A;

	void ChangeZ(GameEngineActor* Actor, float Pos);
};

