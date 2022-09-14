#include "PreCompile.h"
#include "Neru_Window.h"

Neru_Window* Neru_Window::Inst_ = new Neru_Window();

Neru_Window::Neru_Window()
{
}

Neru_Window::~Neru_Window()
{
}

void Neru_Window::Start()
{
	SetTexture("Neru.png");
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

	EveningCollision = CreateComponent<GameEngineCollision>();
	EveningCollision->GetTransform().SetLocalPosition(float4(-114, -40.5));
	EveningCollision->GetTransform().SetLocalScale(float4(40, 60, 5));
	EveningCollision->ChangeOrder(OBJECTORDER::UI);
	EveningCollision->SetName("Evening");

	NightCollision = CreateComponent<GameEngineCollision>();
	NightCollision->GetTransform().SetLocalPosition(float4(-38, -40.5));
	NightCollision->GetTransform().SetLocalScale(float4(40, 60, 5));
	NightCollision->ChangeOrder(OBJECTORDER::UI);
	NightCollision->SetName("Night");

	TommorowCollision = CreateComponent<GameEngineCollision>();
	TommorowCollision->GetTransform().SetLocalPosition(float4(38, -40.5));
	TommorowCollision->GetTransform().SetLocalScale(float4(40, 60, 5));
	TommorowCollision->ChangeOrder(OBJECTORDER::UI);
	TommorowCollision->SetName("Tomorrow");

	ExitCollision = CreateComponent<GameEngineCollision>();
	ExitCollision->GetTransform().SetLocalPosition(float4(80, 54, -3));
	ExitCollision->GetTransform().SetLocalScale(float4(10, 9));
	ExitCollision->ChangeOrder(OBJECTORDER::Exit);


	Inst_->WindowCollision = CreateComponent<GameEngineCollision>();
	Inst_->WindowCollision->GetTransform().SetLocalPosition(float4(-50, -15));
	Inst_->WindowCollision->GetTransform().SetLocalScale(float4(287, 158));
	Inst_->WindowCollision->ChangeOrder(OBJECTORDER::Window);
	Mouse::Inst_->ChangeNameAll();
	Inst_->WindowCollision->SetName("-100");

	SetName("Neru_Window");
}

void Neru_Window::Update(float _DeltaTime)
{
	if (CurStatus != GlobalContentsValue::Neru)
	{
		CurStatus = GlobalContentsValue::Neru;
		Inst_->WindowCollision->SetName("-100");
		Mouse::Inst_->ChangeNameAll();
	}
	if (GlobalContentsValue::Neru)
	{
		ChangeZPos(static_cast<float>(std::stoi(Inst_->WindowCollision->GetNameConstRef())));
		CollisionCheck();
		if (CurString != GlobalContentsValue::Asobu_Window)
		{
			CurString = GlobalContentsValue::Asobu_Window;
			if (CurString == "Evening")
			{
				GetLevel()->CreateActor<Neru_Evening>();
			}
			if (CurString == "Night")
			{
				GetLevel()->CreateActor<Neru_Night>();
			}
			if (CurString == "Tomorrow")
			{
				GetLevel()->CreateActor<Neru_Tomorrow>();
			}
		}
	}
	else
	{
		ChangeZPos(500);
		return;
	}


	
}

void Neru_Window::End()
{
}

void Neru_Window::CollisionCheck()
{
	GameEngineCollision* Array[5]{ EveningCollision, NightCollision, TommorowCollision };
	for (int i = 0; i < 3; i++)
	{
		if (Array[i]->IsCollision(CollisionType::CT_OBB, OBJECTORDER::Mouse, CollisionType::CT_OBB,
			std::bind(&Neru_Window::Click, this, std::placeholders::_1, std::placeholders::_2)))
		{
			break;
		}
		else
		{
			GlobalContentsValue::Asobu_Window = "";
		}
	}
}

bool Neru_Window::Click(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	std::string numbers[5]{ "Evening", "Night", "Tomorrow" };
	for (int i = 0; i < 3; i++)
	{
		std::string A = _This->GetNameConstRef();
		if (_This->GetNameConstRef() == numbers[i])
		{
			GlobalContentsValue::Asobu_Window = numbers[i];
		}
	}
	return true;
}