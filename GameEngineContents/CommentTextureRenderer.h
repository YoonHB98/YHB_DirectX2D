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
	MyColorData& GetPixelData()
	{
		return ColorData;
	}

	float4 Clip;

	void SetTextureRendererSetting();
protected:
	void Start() override;

private:
	float4 FrameData;
	MyColorData ColorData;
};

