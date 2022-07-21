#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :


class GameEngineTextureRenderer;
class LineMain : public GameEngineActor
{
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
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:

};

