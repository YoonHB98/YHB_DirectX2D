#pragma once
#include <GameEngineCore/CoreMinimal.h>

// ���� :


class GameEngineTextureRenderer;
class LineDate : public GameEngineActor
{
public:
	// constrcuter destructer
	LineDate();
	~LineDate();

	// delete Function
	LineDate(const LineDate& _Other) = delete;
	LineDate(LineDate&& _Other) noexcept = delete;
	LineDate& operator=(const LineDate& _Other) = delete;
	LineDate& operator=(LineDate&& _Other) noexcept = delete;

	GameEngineTextureRenderer* Renderer;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:

};

