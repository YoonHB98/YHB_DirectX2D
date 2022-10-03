#pragma once
#include "BadEndWindow.h"

// Ό³Έν :
class BadEndEndWindow : public BadEndWindow
{
public:
	// constrcuter destructer
	BadEndEndWindow();
	~BadEndEndWindow();

	// delete Function
	BadEndEndWindow(const BadEndEndWindow& _Other) = delete;
	BadEndEndWindow(BadEndEndWindow&& _Other) noexcept = delete;
	BadEndEndWindow& operator=(const BadEndEndWindow& _Other) = delete;
	BadEndEndWindow& operator=(BadEndEndWindow&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:

};

