#pragma once
#include "DefaultSetTex.h"


// ¼³¸í :
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
	A6,
	A7,
	A8,
	A9,
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
	GameEngineTextureRenderer* BG;
	void ContentsUpdate(StreamContents Contents);
	void Tutorial();
	float Time = 0;
	float ChangeTime = 0;
	void StateUpdate(AnimationType Type);
	StreamContents Contents;
	Animation CurAnim;
	AnimationType CurType  = AnimationType::A1;
    std::string  CurText = "Á©ÇÏ!";
	std::map<std::string, StreamContents> ContentsMap;
	float TempTime = 0;
   int TempCount = 0;
private:
 int Count = 0;
	bool FirstText = true;
	float CountTime = 0;
	std::string Text;
	float EndTimer = 0.0f;
 Myfont* Font;
	void TextDrawTime(const std::string& Text_, const std::string& Font_, float4 Pos_, float4 Color_, float Size_, float Time);
	void UpdateA1();
	void UpdateA2();
	void UpdateA3();
	void UpdateA4();
	void UpdateA5();
	void UpdateA6();
	void UpdateA7();
	void UpdateA8();
	void UpdateA9();
	bool StreamEnd = false;
	int EnterCount = 0;
	float BlankXSize = 0;
	AnimationType TextType;
	GameEngineTextureRenderer* Blank;
};

