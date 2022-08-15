#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :

class CommentTextureRenderer : public GameEngineTextureRenderer
{
public:
	// constrcuter destructer
	CommentTextureRenderer();
	~CommentTextureRenderer();

	// delete Function
	CommentTextureRenderer(const CommentTextureRenderer& _Other) = delete;
	CommentTextureRenderer(CommentTextureRenderer&& _Other) noexcept = delete;
	CommentTextureRenderer& operator=(const CommentTextureRenderer& _Other) = delete;
	CommentTextureRenderer& operator=(CommentTextureRenderer&& _Other) noexcept = delete;
	MyColorData& GetColorData()
	{
		return ColorData;
	}

	float4 Clip;
protected:
	void Start() override;

	void SetTextureRendererSetting();
private:
	float4 FrameData;
	MyColorData ColorData;
};

