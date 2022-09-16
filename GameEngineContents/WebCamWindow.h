#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :


class GameEngineTextureRenderer;
class WebCamWindow : public DefaultSetTex
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
	WebCamWindow();
	~WebCamWindow();

	// delete Function
	WebCamWindow(const WebCamWindow& _Other) = delete;
	WebCamWindow(WebCamWindow&& _Other) noexcept = delete;
	WebCamWindow& operator=(const WebCamWindow& _Other) = delete;
	WebCamWindow& operator=(WebCamWindow&& _Other) noexcept = delete;

	static WebCamWindow* Inst_;
	GameEngineCollision* WebCamMainCol;


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

	void IdleStart(const StateInfo& _Info);
	void IdleUpdate(float _DeltaTime, const StateInfo& _Info);

	void ActiveStart(const StateInfo& _Info);
	void ActiveUpdate(float _DeltaTime, const StateInfo& _Info);
private:
	GameEngineTextureRenderer* Ame;
	GameEngineTextureRenderer* BG;
	GameEngineTextureRenderer* BGNC;
	GameEngineCollision* ClickCol;

	GameEngineSoundPlayer BgmPlayer;
	bool BgmOn = true;

};

