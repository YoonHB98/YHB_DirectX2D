#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class SuperChat : public DefaultSetTex
{
public:
	// constrcuter destructer
	SuperChat();
	~SuperChat();

	// delete Function
	SuperChat(const SuperChat& _Other) = delete;
	SuperChat(SuperChat&& _Other) noexcept = delete;
	SuperChat& operator=(const SuperChat& _Other) = delete;
	SuperChat& operator=(SuperChat&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	float Time;
	CommentTextureRenderer* ChatRenderer;
	float4 CurPos;
	float Angle;
	float4 AngleDir;
};

