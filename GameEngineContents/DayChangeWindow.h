#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class DayChangeWindow : public DefaultSetTex
{
public:
	// constrcuter destructer
	DayChangeWindow();
	~DayChangeWindow();

	// delete Function
	DayChangeWindow(const DayChangeWindow& _Other) = delete;
	DayChangeWindow(DayChangeWindow&& _Other) noexcept = delete;
	DayChangeWindow& operator=(const DayChangeWindow& _Other) = delete;
	DayChangeWindow& operator=(DayChangeWindow&& _Other) noexcept = delete;

	float Time = 0;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	int CurDay = 0;
	GameEngineTextureRenderer* Renderer;
	GameEngineTextureRenderer* Tri;
	GameEngineTextureRenderer* Font;
	float FontA = 1.0f;
	int Count = 0;
	float FirstPos;
	float ChangeTime = 5.0f;
	float DayChangeTime = 0.0f;
	bool First = true;
	void RemainLineCheck();
};

