#include "PreCompile.h"
#include "Asobu_Window.h"

Asobu_Window* Asobu_Window::Inst_ = new Asobu_Window();

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
	GameCollision->SetName("Game");

	CommunicationCollision = CreateComponent<GameEngineCollision>();
	CommunicationCollision->GetTransform().SetLocalPosition(float4(-38, -40.5));
	CommunicationCollision->GetTransform().SetLocalScale(float4(40, 60,5));
	CommunicationCollision->ChangeOrder(OBJECTORDER::UI);
	CommunicationCollision->SetName("Communication");

	ThatCollision = CreateComponent<GameEngineCollision>();
	ThatCollision->GetTransform().SetLocalPosition(float4(38, -40.5));
	ThatCollision->GetTransform().SetLocalScale(float4(40, 60,5));
	ThatCollision->ChangeOrder(OBJECTORDER::UI);
	ThatCollision->SetName("That");

	ExitCollision = CreateComponent<GameEngineCollision>();
	ExitCollision->GetTransform().SetLocalPosition(float4(80, 54, -3));
	ExitCollision->GetTransform().SetLocalScale(float4(10, 9));
	ExitCollision->ChangeOrder(OBJECTORDER::Exit);


	Inst_->WindowCollision = CreateComponent<GameEngineCollision>();
	Inst_->WindowCollision->GetTransform().SetLocalPosition(float4(-50, -15));
	Inst_->WindowCollision->GetTransform().SetLocalScale(float4(287, 158));
	Inst_->WindowCollision->ChangeOrder(OBJECTORDER::Window);
	Mouse::Inst_->ChangeNameAll();
	Inst_->WindowCollision->SetName("-90");

	SetName("Asobu_Window");
}

void Asobu_Window::Update(float _DeltaTime)
{
	ChangeZPos(static_cast<float>(std::stoi(Inst_->WindowCollision->GetNameConstRef())));
	CollisionCheck();
}

void Asobu_Window::End()
{
}

void Asobu_Window::CollisionCheck()
{
	GameEngineCollision* Array[5]{ GameCollision, CommunicationCollision, ThatCollision };
	On = false;
	for (int i = 0; i < 3; i++)
	{
		if (Array[i]->IsCollision(CollisionType::CT_OBB, OBJECTORDER::Mouse, CollisionType::CT_OBB,
			std::bind(&Asobu_Window::Click, this, std::placeholders::_1, std::placeholders::_2)))
		{
			On = true;
			break;
		}
	}
}

bool Asobu_Window::Click(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	std::string numbers[5]{ "Game", "Communication", "That"};
	for (int i = 0;  i < 3;  i++)
	{
		std::string A = _This->GetNameConstRef();
		if (_This->GetNameConstRef() == numbers[i])
		{
		}
	}
	return true;
}