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
	SetTexture("Asobu.png");
	SetLocalPosition(float4(-50, -15));
	SetLocalScale(float4(287, 158));

	GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture("BackGroundColor.png");
	Renderer->GetTransform().SetLocalScale(float4(287, 2));
	Renderer->GetTransform().SetLocalPosition(float4(-49, -95));
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("BackGroundColor.png");
		Renderer->GetTransform().SetLocalScale(float4(2, 147));
		Renderer->GetTransform().SetLocalPosition(float4(93, -20.5));
	}

	GameCollision = CreateComponent<GameEngineCollision>();
	GameCollision->GetTransform().SetLocalPosition(float4(-38, -40.5));
	GameCollision->GetTransform().SetLocalScale(float4(40, 60, 5));
	GameCollision->ChangeOrder(OBJECTORDER::UI);

	CommunicationCollision = CreateComponent<GameEngineCollision>();
	CommunicationCollision->GetTransform().SetLocalPosition(float4(-38, -40.5));
	CommunicationCollision->GetTransform().SetLocalScale(float4(40, 60,5));
	CommunicationCollision->ChangeOrder(OBJECTORDER::UI);

	ThatCollision = CreateComponent<GameEngineCollision>();
	ThatCollision->GetTransform().SetLocalPosition(float4(38, -40.5));
	ThatCollision->GetTransform().SetLocalScale(float4(40, 60,5));
	ThatCollision->ChangeOrder(OBJECTORDER::UI);

	ExitCollision = CreateComponent<GameEngineCollision>();
	ExitCollision->GetTransform().SetLocalPosition(float4(80, 54, -3));
	ExitCollision->GetTransform().SetLocalScale(float4(10, 9));
	ExitCollision->ChangeOrder(OBJECTORDER::UI);

	WindowCollision = CreateComponent<GameEngineCollision>();
	WindowCollision->GetTransform().SetLocalPosition(float4(-50, -15));
	WindowCollision->GetTransform().SetLocalScale(float4(287, 158));
	WindowCollision->ChangeOrder(OBJECTORDER::Window);


	ChangeZPos(-80);
}

void Asobu_Window::Update(float _DeltaTime)
{
}

void Asobu_Window::End()
{
}