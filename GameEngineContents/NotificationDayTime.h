#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
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

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:

};

