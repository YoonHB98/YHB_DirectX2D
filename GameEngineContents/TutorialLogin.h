#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class TutorialLogin : public DefaultSetTex
{
public:
	// constrcuter destructer
	TutorialLogin();
	~TutorialLogin();

	// delete Function
	TutorialLogin(const TutorialLogin& _Other) = delete;
	TutorialLogin(TutorialLogin&& _Other) noexcept = delete;
	TutorialLogin& operator=(const TutorialLogin& _Other) = delete;
	TutorialLogin& operator=(TutorialLogin&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	GameEngineCollision* Collision;
	Myfont* Font;
	std::string Text = " ";
	bool first;
	bool PassWord = false;

};

