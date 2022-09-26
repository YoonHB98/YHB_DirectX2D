#pragma once
#include "DefaultSetTex.h"
#include "Stream_Game.h"
#include "Stream_Talk.h"

// Ό³Έν :
class Stream_Window : public DefaultSetTex
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
	Stream_Window();
	~Stream_Window();

	// delete Function
	Stream_Window(const Stream_Window& _Other) = delete;
	Stream_Window(Stream_Window&& _Other) noexcept = delete;
	Stream_Window& operator=(const Stream_Window& _Other) = delete;
	Stream_Window& operator=(Stream_Window&& _Other) noexcept = delete;

	static Stream_Window* Inst_;
	GameEngineCollision* WindowCollision;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	GameEngineCollision* GameCollision;
	GameEngineCollision* CommunicationCollision;
	GameEngineCollision* ExitCollision;
	GameEngineTextureRenderer* Tex;
	bool Click(GameEngineCollision* _This, GameEngineCollision* _Other);
	void MouseClick(std::string Name_);
	std::string Text = " ";
	bool On = false;
	std::string CurString = "";
	void CollisionCheck();
	bool CurStatus = true;
};

