#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class NotificationText : public DefaultSetTex
{
public:
	// constrcuter destructer
	NotificationText();
	~NotificationText();

	// delete Function
	NotificationText(const NotificationText& _Other) = delete;
	NotificationText(NotificationText&& _Other) noexcept = delete;
	NotificationText& operator=(const NotificationText& _Other) = delete;
	NotificationText& operator=(NotificationText&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	void TextDraw();
	bool first = true;
	Myfont* Font;
	int Count = 0;
};
