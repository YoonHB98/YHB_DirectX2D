#pragma once
#include "DefaultSetTex.h"
#include "CommentTextureRenderer.h"

// Ό³Έν :
class CommentBadEnding : public DefaultSetTex
{
public:
	// constrcuter destructer
	CommentBadEnding();
	~CommentBadEnding();

	// delete Function
	CommentBadEnding(const CommentBadEnding& _Other) = delete;
	CommentBadEnding(CommentBadEnding&& _Other) noexcept = delete;
	CommentBadEnding& operator=(const CommentBadEnding& _Other) = delete;
	CommentBadEnding& operator=(CommentBadEnding&& _Other) noexcept = delete;

	void CreateText(const std::string& _Text);
	void TextMove(float Y_, float last);
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	int i = 1;
	int Move = 0;
	int Count = 0;
	int TextNum = 0;
	float time = 0;
	Myfont* Font;
	std::vector<CommentTextureRenderer*> Text;
	int MoveStart = 0;
	int ColName = 1;
	bool DeathTime = false;
};

