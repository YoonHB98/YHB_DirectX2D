#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :


class GameEngineTextureRenderer;
class WebCamWindow : public GameEngineActor
{
public:
	// constrcuter destructer
	WebCamWindow();
	~WebCamWindow();

	// delete Function
	WebCamWindow(const WebCamWindow& _Other) = delete;
	WebCamWindow(WebCamWindow&& _Other) noexcept = delete;
	WebCamWindow& operator=(const WebCamWindow& _Other) = delete;
	WebCamWindow& operator=(WebCamWindow&& _Other) noexcept = delete;

	GameEngineTextureRenderer* Renderer;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:

};

