#pragma once
#include "DefaultSetTex.h"
#include "Neru_Evening.h"
#include "Neru_Night.h"
#include "Neru_Tomorrow.h"

// Ό³Έν :
class Neru_Window : public DefaultSetTex
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
	Neru_Window();
	~Neru_Window();

	// delete Function
	Neru_Window(const Neru_Window& _Other) = delete;
	Neru_Window(Neru_Window&& _Other) noexcept = delete;
	Neru_Window& operator=(const Neru_Window& _Other) = delete;
	Neru_Window& operator=(Neru_Window&& _Other) noexcept = delete;

	static Neru_Window* Inst_;
	GameEngineCollision* WindowCollision;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	GameEngineCollision* EveningCollision;
	GameEngineCollision* NightCollision;
	GameEngineCollision* TommorowCollision;
	GameEngineCollision* ExitCollision;
	GameEngineTextureRenderer* Tex;
	bool Click(GameEngineCollision* _This, GameEngineCollision* _Other);
	std::string Text = " ";
	bool On = false;
	std::string CurString = "";
	void CollisionCheck();
	bool CurStatus = true;
};

