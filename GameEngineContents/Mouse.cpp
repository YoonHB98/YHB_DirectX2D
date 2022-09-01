#include "PreCompile.h"
#include "Mouse.h"
#include "LineMain.h"
#include "Stream.h"
#include "WebCamWindow.h"
#include "TaskManager.h"

Mouse* Mouse::Inst_ = new Mouse();
Mouse::Mouse() 
{
}

Mouse::~Mouse() 
{
}

void Mouse::Start()
{
	SetTexture("Cursor.png");
	SetLocalPosition(float4(0, 0, -500));
	SetLocalScale(float4(32, 32));
	Renderer->SetRenderingOrder(2);

	Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalScale({ 32.0f,8.0f,400.0f });
	Collision->GetTransform().SetLocalPosition(float4(0, 12, 0));
	Collision->ChangeOrder(OBJECTORDER::Mouse);

	Collision100 = CreateComponent<GameEngineCollision>();
	Collision100->GetTransform().SetLocalScale({ 32.0f,8.0f,2.0f });
	Collision100->GetTransform().SetLocalPosition(float4(0, 12, -100));
	Collision100->ChangeOrder(OBJECTORDER::Mouse);

	Collision90 = CreateComponent<GameEngineCollision>();
	Collision90->GetTransform().SetLocalScale({ 32.0f,8.0f,2.0f });
	Collision90->GetTransform().SetLocalPosition(float4(0, 12, -90));
	Collision90->ChangeOrder(OBJECTORDER::Mouse);

	Collision80 = CreateComponent<GameEngineCollision>();
	Collision80->GetTransform().SetLocalScale({ 32.0f,8.0f,2.0f });
	Collision80->GetTransform().SetLocalPosition(float4(0, 12, -80));
	Collision80->ChangeOrder(OBJECTORDER::Mouse);

	Collision70 = CreateComponent<GameEngineCollision>();
	Collision70->GetTransform().SetLocalScale({ 32.0f,8.0f,2.0f });
	Collision70->GetTransform().SetLocalPosition(float4(0, 12, -70));
	Collision70->ChangeOrder(OBJECTORDER::Mouse);

	Collision60 = CreateComponent<GameEngineCollision>();
	Collision60->GetTransform().SetLocalScale({ 32.0f,8.0f,2.0f });
	Collision60->GetTransform().SetLocalPosition(float4(0, 12, -60));
	Collision60->ChangeOrder(OBJECTORDER::Mouse);

	Collision40 = CreateComponent<GameEngineCollision>();
	Collision40->GetTransform().SetLocalScale({ 32.0f,8.0f,2.0f });
	Collision40->GetTransform().SetLocalPosition(float4(0, 12, 40));
	Collision40->ChangeOrder(OBJECTORDER::Mouse);

	Collision30 = CreateComponent<GameEngineCollision>();
	Collision30->GetTransform().SetLocalScale({ 32.0f,8.0f,2.0f });
	Collision30->GetTransform().SetLocalPosition(float4(0, 12, 30));
	Collision30->ChangeOrder(OBJECTORDER::Mouse);
}

void Mouse::Update(float _DeltaTime)
{
	ShowCursor(0);
	float4 Pos = GetLevel()->GetMainCamera()->GetMouseWorldPosition();
	GlobalContentsValue::MousePos = Pos;
	GetTransform().SetWorldPosition(float4(Pos.x, Pos.y , 0));

	if (GlobalContentsValue::Stream == true)
	{
		if (bool Check30 = Collision30->IsCollision(CollisionType::CT_OBB, OBJECTORDER::Window, CollisionType::CT_OBB,
			std::bind(&Mouse::ChnageName, this, std::placeholders::_1, std::placeholders::_2))
			&& true == GameEngineInput::GetInst()->IsDown("MouseClick"))
		{
			ChangeNameAll();
		}else
		if (bool Check40 = Collision40->IsCollision(CollisionType::CT_OBB, OBJECTORDER::Window, CollisionType::CT_OBB,
			std::bind(&Mouse::ChnageName, this, std::placeholders::_1, std::placeholders::_2))
			&& true == GameEngineInput::GetInst()->IsDown("MouseClick"))
		{
			ChangeNameAll();
		}
	}else
	if (GlobalContentsValue::Stream == false)
	{
		//충돌이 있으면
		if (bool Check = Collision->IsCollision(CollisionType::CT_OBB, OBJECTORDER::Window, CollisionType::CT_OBB,
			std::bind(&Mouse::MouseCollision, this, std::placeholders::_1, std::placeholders::_2)))
		{
			//맨 앞에 있으면 무시
			if (bool Check100 = Collision100->IsCollision(CollisionType::CT_OBB, OBJECTORDER::Window, CollisionType::CT_OBB,
				std::bind(&Mouse::ChnageName, this, std::placeholders::_1, std::placeholders::_2))
				&& true == GameEngineInput::GetInst()->IsDown("MouseClick"))
			{
				ChangeNameAll();
			}
			else
				if (bool Check90 = Collision90->IsCollision(CollisionType::CT_OBB, OBJECTORDER::Window, CollisionType::CT_OBB,
					std::bind(&Mouse::ChnageName, this, std::placeholders::_1, std::placeholders::_2))
					&& true == GameEngineInput::GetInst()->IsDown("MouseClick"))
				{
					ChangeNameAll();
				}
				else if (bool Check80 = Collision80->IsCollision(CollisionType::CT_OBB, OBJECTORDER::Window, CollisionType::CT_OBB,
					std::bind(&Mouse::ChnageName, this, std::placeholders::_1, std::placeholders::_2))
					&& true == GameEngineInput::GetInst()->IsDown("MouseClick"))
				{
					ChangeNameAll();
				}
				else if (bool Check70 = Collision70->IsCollision(CollisionType::CT_OBB, OBJECTORDER::Window, CollisionType::CT_OBB,
					std::bind(&Mouse::ChnageName, this, std::placeholders::_1, std::placeholders::_2))
					&& true == GameEngineInput::GetInst()->IsDown("MouseClick"))
				{
					ChangeNameAll();
				}
				else if (bool Check60 = Collision60->IsCollision(CollisionType::CT_OBB, OBJECTORDER::Window, CollisionType::CT_OBB,
					std::bind(&Mouse::ChnageName, this, std::placeholders::_1, std::placeholders::_2))
					&& true == GameEngineInput::GetInst()->IsDown("MouseClick"))
				{
					ChangeNameAll();
				}
		}
	
	}

	if (Collision->IsCollision(CollisionType::CT_OBB, OBJECTORDER::Emoticon, CollisionType::CT_OBB,
		std::bind(&Mouse::LineEmoticon, this, std::placeholders::_1, std::placeholders::_2))
		&& true == GameEngineInput::GetInst()->IsDown("MouseClick")
		&&GlobalContentsValue::EomticonStatus == 2)
	{
	}
}

void Mouse::End()
{
}

bool Mouse::MouseCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	return true;
}

bool Mouse::ChnageName(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	if (GlobalContentsValue::Stream == true
		&& true == GameEngineInput::GetInst()->IsDown("MouseClick"))
	{
		std::string Name = _Other->GetActor()->GetNameConstRef();
		GetActorName(Name, "30F");
		std::string CurName = Stream::Inst_->StreamMainCol->GetNameConstRef();
		CurName = TaskManager::Inst_->TaskManagerMainCol->GetNameConstRef();
	}
	else
		if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
		{
			std::string Name = _Other->GetActor()->GetNameConstRef();
			GetActorName(Name, "-100F");
		}

	return true;
}

bool Mouse::LineEmoticon(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	if (GlobalContentsValue::Line == true
		&& GlobalContentsValue::EomticonStatus == 2
		&& true == GameEngineInput::GetInst()->IsDown("MouseClick"))
	{
		GlobalContentsValue::CurEmoticonName = _Other->GetNameConstRef();
	}

	return true;
}

void Mouse::ChangeNameAll()
{
	if (nullptr != LineMain::Inst_->LineMainCol)
	{
		std::string CurName = LineMain::Inst_->LineMainCol->GetNameConstRef();
		CurName = CurNameChange(CurName);
		LineMain::Inst_->LineMainCol->SetName(CurName);
	}
	if (nullptr != WebCamWindow::Inst_->WebCamMainCol)
	{
		std::string CurName = WebCamWindow::Inst_->WebCamMainCol->GetNameConstRef();
		CurName = CurNameChange(CurName);
		WebCamWindow::Inst_->WebCamMainCol->SetName(CurName);
	}
	if (nullptr != Stream::Inst_->StreamMainCol
		&& GlobalContentsValue::Stream == true)
	{
		std::string CurName = Stream::Inst_->StreamMainCol->GetNameConstRef();
		CurName = CurNameChange(CurName);
		Stream::Inst_->StreamMainCol->SetName(CurName);
	}
	if (nullptr != TaskManager::Inst_->TaskManagerMainCol)
	{
		std::string CurName = TaskManager::Inst_->TaskManagerMainCol->GetNameConstRef();
		CurName = CurNameChange(CurName);
		TaskManager::Inst_->TaskManagerMainCol->SetName(CurName);
	}

}

std::string Mouse::CurNameChange(std::string string)
{
	if (string == "-100F")
	{
		string = "-100";
	}
	else if (string == "-100")
	{
		string = "-90";
	}
	else if (string == "-90")
	{
		string = "-80";
	}
	else if (string == "-80")
	{
		string = "-70";
	}
	else if (string == "-70")
	{
		string = "-60";
	}
	else if (string == "30F")
	{
		string = "30";
	}
	else if (string == "30")
	{
		string = "40";
	}
	return string;
}


void Mouse::GetActorName(std::string Name_, std::string ZPos)
{
	if (Name_ == "Line")
	{
		LineMain::Inst_->LineMainCol->SetName(ZPos);
	}else
		if (Name_ == "Stream")
		{
			Stream::Inst_->StreamMainCol->SetName(ZPos);
		}else
			if (Name_ == "WebCamWindow")
			{
				WebCamWindow::Inst_->WebCamMainCol->SetName(ZPos);
			}
			else
				if (Name_ == "TaskManager")
				{
					TaskManager::Inst_->TaskManagerMainCol->SetName(ZPos);
				}
}
