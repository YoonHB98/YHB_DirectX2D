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
	class YNoiseEffect* YEffect;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
	float TestTime = 0;
private:
	int a = 0;
	float bartime = 0;
	bool first = true;
	bool TutorialFirst = true;
	bool TutorialLoginFirst = true;

	GameEngineSoundPlayer BGMPlayer;
	GameEngineActor* A;

	bool Day2 = true;
	void BGM();
	float CurBgmSpeed = 1.0f;
	void ChangeZ(GameEngineActor* Actor, float Pos);

	GameEngineActor* LineMainActor;
	GameEngineActor* LineTextActor;
	GameEngineActor* StreamAnimationActor;
	GameEngineActor* StreamActor;
	GameEngineActor* CommentActor;
	bool BadEnd = true;
	int CurDay = 0;
};

