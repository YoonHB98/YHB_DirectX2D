#pragma once
#include "DefaultSetTex.h"
#include "Asobu_Game.h"
#include "Asobu_Talk.h"
#include "Asobu_That.h"

// Ό³Έν :
class Asobu_Window : public DefaultSetTex
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
	Asobu_Window();
	~Asobu_Window();

	// delete Function
	Asobu_Window(const Asobu_Window& _Other) = delete;
	Asobu_Window(Asobu_Window&& _Other) noexcept = delete;
	Asobu_Window& operator=(const Asobu_Window& _Other) = delete;
	Asobu_Window& operator=(Asobu_Window&& _Other) noexcept = delete;

	static Asobu_Window* Inst_;
	GameEngineCollision* WindowCollision;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	GameEngineCollision* GameCollision;
	GameEngineCollision* CommunicationCollision;
	GameEngineCollision* ThatCollision;
	GameEngineCollision* ExitCollision;
	GameEngineTextureRenderer* Tex;
	bool Click(GameEngineCollision* _This, GameEngineCollision* _Other);
	std::string Text = " ";
	bool On = false;
	void CollisionCheck();
};

