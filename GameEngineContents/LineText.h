#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class LineText : public DefaultSetTex
{
public:
	// constrcuter destructer
	LineText();
	~LineText();

	// delete Function
	LineText(const LineText& _Other) = delete;
	LineText(LineText&& _Other) noexcept = delete;
	LineText& operator=(const LineText& _Other) = delete;
	LineText& operator=(LineText&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
	int ChoiceNum = 0;
	float ChoiceTime = 0;
	bool ChoiceTimeStart = false;

	void CreateText(std::string _Text);
	void TextMove(float Y_, float last);
	void CreateChoice();
	void Check();
	bool CheckStart = false;
	int Move = 0;
	int TextNum = 0;
	int Count = 0;
	float time = 0;
	bool Tutorial = false;
	int MoveStart = 0;
	float ChangeTime = 0;
	bool ChangeStart = false;
	int CurTime = 0;
	int CurEmoticonStatus = 2;
	void RLineNum();
	float EmoticonTime = 0;
	std::string ReactionName = "";
	std::string CurTextCon = "";
	bool EmoticonTimeStart = false;
	GameEngineCollision* EmoticonCollision1;
	GameEngineCollision* EmoticonCollision2;
	GameEngineCollision* EmoticonCollision3;
	GameEngineCollision* EmoticonCollision4;
	GameEngineCollision* EmoticonCollision5;
	GameEngineCollision* EmoticonCollision6;
	GameEngineCollision* EmoticonCollision7;
	GameEngineCollision* EmoticonCollision8;
private:
	MyTextureRenderer* ChoiceText;
	GameEngineCollision* Collision;
	GameEngineCollision* Collision2;
	std::vector<MyTextureRenderer*> Text;

	void CreateDayTime();
	void EmoticonON();
	void EmoticonOnOff();
	void EmoticonCheck();
	int Reaction();
	void exceptionCheck(std::string _Text_);
	std::vector<GameEngineTextureRenderer*> EmoticonRenderer;
};

