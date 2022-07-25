#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :

class GameEngineTextureRenderer;
class WindowIcon : public GameEngineActor
{
public:
	// constrcuter destructer
	WindowIcon();
	~WindowIcon();

	// delete Function
	WindowIcon(const WindowIcon& _Other) = delete;
	WindowIcon(WindowIcon&& _Other) noexcept = delete;
	WindowIcon& operator=(const WindowIcon& _Other) = delete;
	WindowIcon& operator=(WindowIcon&& _Other) noexcept = delete;

	GameEngineTextureRenderer* Youtube;
	GameEngineTextureRenderer* Asobu;
	GameEngineTextureRenderer* Neru;
	GameEngineTextureRenderer* Okusuri;
	GameEngineTextureRenderer* Internet;
	GameEngineTextureRenderer* Odekake;
	GameEngineTextureRenderer* Tex;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:

};

