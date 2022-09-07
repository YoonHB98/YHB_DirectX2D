#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class TutorialLogin : public DefaultSetTex
{
public:
	static void Destroy()
	{
		if (nullptr != Inst_)
		{
			delete Inst_;
			Inst_ = nullptr;
		}
	}
	// constrcuter destructer
	TutorialLogin();
	~TutorialLogin();
	static TutorialLogin* Inst_;

	GameEngineCollision* TutorialLoginCol;
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
	GameEngineCollision* Collision2;
	GameEngineTextureRenderer* Tex;
	Myfont* Font;
	std::string Text = " ";
	bool first = true;
	bool PassWord = false;

};

