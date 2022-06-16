#pragma once
#include <string>
#include <list>
#include "GameEngineTime.h"
#include "GameEngineDebugObject.h"


class GameEngineUpdateObject : public GameEngineDebugObject
{
public:
	// constrcuter destructer
	GameEngineUpdateObject();
	~GameEngineUpdateObject();

	// delete Function
	GameEngineUpdateObject(const GameEngineUpdateObject& _Other) = delete;
	GameEngineUpdateObject(GameEngineUpdateObject&& _Other) noexcept = delete;
	GameEngineUpdateObject& operator=(const GameEngineUpdateObject& _Other) = delete;
	GameEngineUpdateObject& operator=(GameEngineUpdateObject&& _Other) noexcept = delete;


	inline void On()
	{
		IsUpdate_ = true;
	}

	inline void Off()
	{
		IsUpdate_ = false;
	}

	inline bool IsUpdate()
	{
		return IsUpdate_ && false == IsDeath_ && true == Parent->IsUpdate();
	}

	inline bool IsDeath()
	{
		return IsDeath_ || true == Parent->IsDeath();
	}

	void AddAccTime(float _DeltaTime)
	{
		AccTime_ += _DeltaTime;
	}

	float GetAccTime()
	{
		return AccTime_;
	}

	void ReSetAccTime()
	{
		AccTime_ = 0.0f;
	}

	inline 	void Death()
	{
		IsDeath_ = true;
	}

	void ReleaseUpdate(float _DeltaTime)
	{
		if (false == IsReleaseUpdate_)
		{
			return;
		}

		DeathTime_ -= GameEngineTime::GetDeltaTime();

		if (0.0f >= DeathTime_)
		{
			IsDeath_ = true;
		}
	}

	inline void Death(float _Time)
	{
		IsReleaseUpdate_ = true;
		DeathTime_ = _Time;
	}

	inline int GetOrder()
	{
		return Order_;
	}

	virtual inline void SetOrder(int _Order)
	{
		Order_ = _Order;
	}

	template<typename ParentType>
	ParentType* GetParent()
	{
		return dynamic_cast<ParentType*>(Parent);
	}

	virtual void SetParent(GameEngineUpdateObject* _Parent);

protected:
	// �� ������Ʈ�� ������ �ϱ� �����ߴ�.
	virtual void OnEvent() {}

	// �� ������Ʈ�� ������.
	virtual void OffEvent() {}

	// �� ������Ʈ�� ���������.
	virtual void Start() = 0;

	// �� ������Ʈ�� �����ӱ����ȿ��� ���� �ִ�.
	virtual void Update(float _DeltaTime) = 0;

	// �� ������Ʈ�� �޸𸮰� �����ȴ�.
	virtual void End() = 0;

private:
	int Order_;
	bool IsReleaseUpdate_;
	float DeathTime_;
	float AccTime_;

	bool IsUpdate_;
	bool IsDeath_;

	GameEngineUpdateObject* Parent;
	std::list<GameEngineUpdateObject*> Childs;
};

