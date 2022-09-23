#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :


class GameEngineTextureRenderer;
class NotificationDayTime : public DefaultSetTex
{
public:
	// constrcuter destructer
	NotificationDayTime();
	~NotificationDayTime();

	// delete Function
	NotificationDayTime(const NotificationDayTime& _Other) = delete;
	NotificationDayTime(NotificationDayTime&& _Other) noexcept = delete;
	NotificationDayTime& operator=(const NotificationDayTime& _Other) = delete;
	NotificationDayTime& operator=(NotificationDayTime&& _Other) noexcept = delete;

	GameEngineTextureRenderer* Tuuti;
	GameEngineTextureRenderer* Tuuti2;
	GameEngineTextureRenderer* Line;
	GameEngineSoundPlayer BgmPlayer;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	GameEngineCollision* Collision;
};

