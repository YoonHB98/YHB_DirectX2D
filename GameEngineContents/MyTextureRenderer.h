#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :

struct MyColorData
{
	float4 MulColor;
	float4 PlusColor;

	MyColorData()
		: MulColor(float4::WHITE)
		, PlusColor(float4::ZERO)
	{

	}
};



class MyTextureRenderer : public GameEngineTextureRenderer
{
public:
	// constrcuter destructer
	MyTextureRenderer();
	~MyTextureRenderer();

	// delete Function
	MyTextureRenderer(const MyTextureRenderer& _Other) = delete;
	MyTextureRenderer(MyTextureRenderer&& _Other) noexcept = delete;
	MyTextureRenderer& operator=(const MyTextureRenderer& _Other) = delete;
	MyTextureRenderer& operator=(MyTextureRenderer&& _Other) noexcept = delete;
	MyColorData& GetColorData()
	{
		return ColorData;
	}
protected:
	void Start() override;

	void SetTextureRendererSetting();


private:
	float4 FrameData;
    MyColorData ColorData;
};

