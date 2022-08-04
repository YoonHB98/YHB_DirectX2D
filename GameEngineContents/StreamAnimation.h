#pragma once
#include "DefaultSetTex.h"


// Ό³Έν :
enum class StreamContents
{
	Tutorial,
};

enum class Animation
{
	Idle1,
	End1,
	Idle2,
	End2,
	Idle3,
	End3,
	Idle4,
	End4,
	Idle5,
	End5,
};

enum class AnimationType
{
	A1,
	A2,
	A3,
	A4,
	A5,
};

class StreamAnimation : public DefaultSetTex
{
public:
	// constrcuter destructer
	StreamAnimation();
	~StreamAnimation();

	// delete Function
	StreamAnimation(const StreamAnimation& _Other) = delete;
	StreamAnimation(StreamAnimation&& _Other) noexcept = delete;
	StreamAnimation& operator=(const StreamAnimation& _Other) = delete;
	StreamAnimation& operator=(StreamAnimation&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

	bool first = true;
	bool AnimationStart = false;
private:
	void ContentsUpdate(StreamContents Contents);
	void Tutorial();
	float Time = 0;
	float ChangeTime = 0;
	void StateUpdate(AnimationType Type);
	StreamContents Contents;
	Animation CurAnim;
	AnimationType CurType  = AnimationType::A1;
	std::map<std::string, StreamContents> ContentsMap;

private:
	void UpdateA1();
	void UpdateA2();
	void UpdateA3();
	void UpdateA4();
	void UpdateA5();
};

