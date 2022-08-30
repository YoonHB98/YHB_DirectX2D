#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class Mouse : public DefaultSetTex
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
public:
	// constrcuter destructer
	Mouse();
	~Mouse();

	// delete Function
	Mouse(const Mouse& _Other) = delete;
	Mouse(Mouse&& _Other) noexcept = delete;
	Mouse& operator=(const Mouse& _Other) = delete;
	Mouse& operator=(Mouse&& _Other) noexcept = delete;
	void ChangeNameAll();
	static  Mouse* Inst_;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

	bool MouseCollision(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool ChnageName(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool LineEmoticon(GameEngineCollision* _This, GameEngineCollision* _Other);
	std::string CurNameChange(std::string string);
private:
	GameEngineCollision* Collision;
	GameEngineCollision* Collision100;
	GameEngineCollision* Collision90;
	GameEngineCollision* Collision80;
	GameEngineCollision* Collision70;
	GameEngineCollision* Collision60;

	GameEngineCollision* Collision40;
	GameEngineCollision* Collision30;
};

