#pragma once
#include "DefaultSetTex.h"
#include "CommentTextureRenderer.h"

// Ό³Έν :
class Comment : public DefaultSetTex
{
public:
	// constrcuter destructer
	Comment();
	~Comment();

	// delete Function
	Comment(const Comment& _Other) = delete;
	Comment(Comment&& _Other) noexcept = delete;
	Comment& operator=(const Comment& _Other) = delete;
	Comment& operator=(Comment&& _Other) noexcept = delete;

	void CreateText(const std::string& _Text);
	void TextMove(float Y_, float last);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	void CommentCheckStart();
	int i = 1;
	int Move = 0;
	int Count = 0;
	int TextNum = 0;
	float time = 0;
	GameEngineCollision* CommentCheck;
	std::vector<CommentTextureRenderer*> Text;
	std::vector<std::pair<GameEngineCollision*, GameEngineCollision*>> Col;
	int MoveStart = 0;
	int ColName = 1;
	CommentTextureRenderer* Trash;
};

