#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :
struct PixelData1
{
	float4 MulColor;
	float4 PlusColor;
	float4 Slice;

	PixelData1()
		: MulColor(float4::WHITE)
		, PlusColor(float4::ZERO)
		, Slice(float4::ZERO)
	{

	}
};

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
	float4 Color;
	PixelData1 PixelDataInst;
	void SetTextureRendererSetting();
protected:
	void Start() override;

private:
	float4 FrameData;
	MyColorData ColorData;
};

