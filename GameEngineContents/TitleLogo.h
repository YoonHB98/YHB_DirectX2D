#pragma once
#include <GameEngineCore/CoreMinimal.h>

// ���� :
class GameEngineTextureRenderer;
class TitleLogo : public GameEngineActor
{
public:
	// constrcuter destructer
	TitleLogo();
	~TitleLogo();

	// delete Function
	TitleLogo(const TitleLogo& _Other) = delete;
	TitleLogo(TitleLogo&& _Other) noexcept = delete;
	TitleLogo& operator=(const TitleLogo& _Other) = delete;
	TitleLogo& operator=(TitleLogo&& _Other) noexcept = delete;
	GameEngineTextureRenderer* Renderer;
	GameEngineSoundPlayer BgmPlayer1;
	GameEngineSoundPlayer BgmPlayer2;
	GameEngineSoundPlayer BgmPlayer3;

	float Time = 0;
	bool CountStart = false;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
	void BootEnd(const FrameAnimation_DESC&);
private:


};

