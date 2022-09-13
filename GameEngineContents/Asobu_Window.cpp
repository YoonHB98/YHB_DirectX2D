#include "PreCompile.h"
#include "Asobu_Window.h"

Asobu_Window::Asobu_Window() 
{
}

Asobu_Window::~Asobu_Window() 
{
}

void Asobu_Window::Start()
{
	SetTexture(".png");
	SetLocalPosition(float4(0, 0, 0));
	SetLocalScale(float4(0, 0));
}

void Asobu_Window::Update(float _DeltaTime)
{
}

void Asobu_Window::End()
{
}