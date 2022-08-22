#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :


class GameEngineTextureRenderer;
class LineMain : public DefaultSetTex
{
public:
	static void Destroy()
	{
		if (nullptr != Inst_)
		{
			delete Inst_;
			Inst_ = nullptr;
		}
	}
public:
	// constrcuter destructer
	LineMain();
	~LineMain();

	// delete Function
	LineMain(const LineMain& _Other) = delete;
	LineMain(LineMain&& _Other) noexcept = delete;
	LineMain& operator=(const LineMain& _Other) = delete;
	LineMain& operator=(LineMain&& _Other) noexcept = delete;

	GameEngineTextureRenderer* Renderer;
	GameEngineSoundPlayer BgmPlayer;
	static LineMain* Inst_;
	GameEngineCollision* LineMainCol;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
};

