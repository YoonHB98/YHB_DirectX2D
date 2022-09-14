#include "PreCompile.h"
#include "Neru_Window.h"

Neru_Window::Neru_Window() 
{
}

Neru_Window::~Neru_Window() 
{
}

void Neru_Window::Start()
{
	SetTexture(".png");
	SetLocalPosition(float4(0, 0, 0));
	SetLocalScale(float4(0, 0));
}

void Neru_Window::Update(float _DeltaTime)
{
}

void Neru_Window::End()
{
}