#pragma once
#include "DefaultSetTex.h"

// Ό³Έν :
class Neru_Window : public DefaultSetTex
{
public:
	// constrcuter destructer
	Neru_Window();
	~Neru_Window();

	// delete Function
	Neru_Window(const Neru_Window& _Other) = delete;
	Neru_Window(Neru_Window&& _Other) noexcept = delete;
	Neru_Window& operator=(const Neru_Window& _Other) = delete;
	Neru_Window& operator=(Neru_Window&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:

};

