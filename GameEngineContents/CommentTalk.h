#pragma once
#include "DefaultSetTex.h"
#include "CommentTextureRenderer.h"

// Ό³Έν :
class CommentTalk : public DefaultSetTex
{
public:
	// constrcuter destructer
	CommentTalk();
	~CommentTalk();

	// delete Function
	CommentTalk(const CommentTalk& _Other) = delete;
	CommentTalk(CommentTalk&& _Other) noexcept = delete;
	CommentTalk& operator=(const CommentTalk& _Other) = delete;
	CommentTalk& operator=(CommentTalk&& _Other) noexcept = delete;

	void CreateText(const std::string& _Text);
	void TextMove(float Y_, float last);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	void CommentTalkCheckStart();
	int i = 1;
	int Move = 0;
	int Count = 0;
	int TextNum = 0;
	float time = 0;
	GameEngineCollision* CommentTalkCheck;
	Myfont* Font;
	std::vector<CommentTextureRenderer*> Text;
	std::vector<std::pair<GameEngineCollision*, GameEngineCollision*>> Col;
	int MoveStart = 0;
	int ColName = 1;
	bool DeathTime = false;
	CommentTextureRenderer* Trash;
};

