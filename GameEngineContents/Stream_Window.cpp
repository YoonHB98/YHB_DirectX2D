#include "PreCompile.h"
#include "Stream_Window.h"
#include "Change.h"

Stream_Window* Stream_Window::Inst_ = new Stream_Window();

Stream_Window::Stream_Window()
{
}

Stream_Window::~Stream_Window()
{
}

void Stream_Window::Start()
{
	SetTexture("StreamWindow.png");
	SetLocalPosition(float4(-75, -83));
	SetLocalScale(float4(488, 326));

	//GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
	//Renderer->SetTexture("BackGroundColor.png");
	//Renderer->GetTransform().SetLocalScale(float4(287, 2));
	//Renderer->GetTransform().SetLocalPosition(float4(-49, -95));
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->SetTexture("BackGroundColor.png");
		Renderer->GetTransform().SetLocalScale(float4(2, 320));
		Renderer->GetTransform().SetLocalPosition(float4(170, -86));
		Renderer->SetPivot(PIVOTMODE::BOT);
	}

	GameCollision = CreateComponent<GameEngineCollision>();
	GameCollision->GetTransform().SetLocalPosition(float4(-195, -31));
	GameCollision->GetTransform().SetLocalScale(float4(210, 30, 5));
	GameCollision->ChangeOrder(OBJECTORDER::UI);
	GameCollision->SetName("Game");

	CommunicationCollision = CreateComponent<GameEngineCollision>();
	CommunicationCollision->GetTransform().SetLocalPosition(float4(-195, 10));
	CommunicationCollision->GetTransform().SetLocalScale(float4(210, 30, 5));
	CommunicationCollision->ChangeOrder(OBJECTORDER::UI);
	CommunicationCollision->SetName("Communication");

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

	SetName("Stream_Window");
}

void Stream_Window::Update(float _DeltaTime)
{
	//듀토리얼이면 무시
	if (GlobalContentsValue::Contents == "Tutorial")
	{
		ChangeZPos(500);
		return;
	}
	if (GlobalContentsValue::BadEnd)
	{
		ChangeZPos(500);
		EndD = true;
		return;
	}else
		if (GlobalContentsValue::GoodEnd)
		{
			ChangeZPos(500);
			return;
		}

	if (EndD)
	{
		ChangeZPos(500);
		return;
	}
	if (CurStatus != GlobalContentsValue::Youtube)
	{
		CurStatus = GlobalContentsValue::Youtube;
		Inst_->WindowCollision->SetName("-100");
		Mouse::Inst_->ChangeNameAll();
	}


	if (GlobalContentsValue::Youtube)
	{
		ChangeZPos(static_cast<float>(std::stoi(Inst_->WindowCollision->GetNameConstRef())));
		CollisionCheck();
		if (CurString != GlobalContentsValue::Stream_Window)
		{
			CurString = GlobalContentsValue::Stream_Window;
			if (CurString == "Game")
			{
				GetLevel()->CreateActor<Stream_Game>();
			}
			if (CurString == "Communication")
			{
				GetLevel()->CreateActor<Stream_Talk>();
			}
		}
	}

	if (GlobalContentsValue::Youtube == false)
	{
		ChangeZPos(500);
		return;
	}



}

void Stream_Window::End()
{
}

void Stream_Window::CollisionCheck()
{
	GameEngineCollision* Array[5]{ GameCollision, CommunicationCollision };
	for (int i = 0; i < 2; i++)
	{
		if (Array[i]->IsCollision(CollisionType::CT_OBB, OBJECTORDER::Mouse, CollisionType::CT_OBB,
			std::bind(&Stream_Window::Click, this, std::placeholders::_1, std::placeholders::_2)))
		{
			break;
		}
		else
		{
			GlobalContentsValue::Stream_Window = "";
		}
	}
}

bool Stream_Window::Click(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	std::string numbersstart[5]{ "GameStart", "CommunicationStart" };
	std::string numbers[5]{ "Game", "Communication" };
	if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
	{
		for (int i = 0; i < 2; i++)
		{
			std::string A = _This->GetNameConstRef();
			if (_This->GetNameConstRef() == numbers[i])
			{
				MouseClick(numbersstart[i]);
				return true;
			}
		}
	}
	else
		for (int i = 0; i < 2; i++)
		{
			std::string A = _This->GetNameConstRef();
			if (_This->GetNameConstRef() == numbers[i])
			{
				GlobalContentsValue::Stream_Window = numbers[i];
			}
		}
	return true;
}

void Stream_Window::MouseClick(std::string Name_)
{
	GlobalContentsValue::Stream_Window = Name_;
	GlobalContentsValue::Contents = Name_;
	GlobalContentsValue::WebCamWindow = false;
	GlobalContentsValue::Line = false;
	GlobalContentsValue::Change = true;
	GetLevel()->CreateActor<Change>();
	GlobalContentsValue::Youtube = false;
}