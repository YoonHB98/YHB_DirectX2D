#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class TweetComment : public DefaultSetTex
{
public:
	// constrcuter destructer
	TweetComment();
	~TweetComment();

	// delete Function
	TweetComment(const TweetComment& _Other) = delete;
	TweetComment(TweetComment&& _Other) noexcept = delete;
	TweetComment& operator=(const TweetComment& _Other) = delete;
	TweetComment& operator=(TweetComment&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	float Time;
	void CreateText(const std::string& _Text);
	void MoveY(float Y);
	void LoadingEnd();
	float Bot = 0;
	float YSize = 0;
	int i = 1;
	bool LoadingFirst = true;
	std::string CurContents = "Tutorial";
	bool CurStatus = true;
	std::vector<GameEngineTextureRenderer*> TextVector;
};

