#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :

class GameEngineTextureRenderer;
class DefaultSetTex : public GameEngineActor
{
public:
	// constrcuter destructer
	DefaultSetTex();
	~DefaultSetTex();

	// delete Function
	DefaultSetTex(const DefaultSetTex& _Other) = delete;
	DefaultSetTex(DefaultSetTex&& _Other) noexcept = delete;
	DefaultSetTex& operator=(const DefaultSetTex& _Other) = delete;
	DefaultSetTex& operator=(DefaultSetTex&& _Other) noexcept = delete;

	GameEngineTextureRenderer* Renderer;
	GameEngineStateManager StateManager;
	bool Stop = false;
	void SetTexture(std::string Name);
	void SetLocalPosition(float4 Pos);
	void SetLocalScale(float4 Scale);
	void ChangeTexture(std::string Name);
	void ChangeForward(GameEngineTextureRenderer* Renderer, float z);
	void ChangeZPos(float Z);

	bool MouseCheck(GameEngineCollision* _Col);
	inline bool MouseCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
	{
		return true;
	}
	GameEngineCollision* Collision;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:

};

