#pragma once
#include <GameEngineCore/CoreMinimal.h>


// Ό³Έν :

class GameEngineTextureRenderer;
class WindowIcon : public DefaultSetTex
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

	GameEngineTextureRenderer* Youtube[2];
	GameEngineTextureRenderer* Asobu[2];
	GameEngineTextureRenderer* Neru[2];
	GameEngineTextureRenderer* Okusuri[2];
	GameEngineTextureRenderer* Internet[2];
	GameEngineTextureRenderer* Odekake[2];
	GameEngineTextureRenderer* Tex[2];

	GameEngineCollision* YoutubeCol;
	GameEngineCollision* AsobuCol;
	GameEngineCollision* NeruCol;
	GameEngineCollision* OkusuriCol;
	GameEngineCollision* InternetCol;
	GameEngineCollision* OdekakeCol;
	GameEngineCollision* TexCol;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	void MouseClick();
	bool WindowOn(GameEngineCollision* _This, GameEngineCollision* _Other);
	void Swich(std::string Name_);
};

