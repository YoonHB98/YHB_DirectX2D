#include "PreCompile.h"
#include "TaskManager.h"

TaskManager* TaskManager::Inst_ = new TaskManager();

TaskManager::TaskManager()
{
}

TaskManager::~TaskManager()
{
}

void TaskManager::Start()
{
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture("TaskManager.png");
	Renderer->GetTransform().SetLocalPosition(float4(257, 170, 0));
	Renderer->GetTransform().SetLocalScale(float4(199, 178));

	float4 Size = Renderer->GetTransform().GetLocalScale();
	Inst_->TaskManagerMainCol = CreateComponent<GameEngineCollision>();
	Inst_->TaskManagerMainCol->GetTransform().SetLocalPosition(float4(257, 170, 0));
	Inst_->TaskManagerMainCol->GetTransform().SetLocalScale(float4(199, 178, 2));
	Inst_->TaskManagerMainCol->ChangeOrder(OBJECTORDER::Window);
	Inst_->TaskManagerMainCol->SetName("-90");

	SetName("");

}

void TaskManager::Update(float _DeltaTime)
{
	std::string A = Inst_->TaskManagerMainCol->GetNameConstRef();
	if (GlobalContentsValue::Stream == true)
	{
		if (GetNameConstRef() != "")
		{
			if (GetNameConstRef() == "-100F")
			{
				SetName("-100");
			}
			Mouse::Inst_->ChangeNameAll();
			Inst_->TaskManagerMainCol->SetName(GetNameConstRef());
			SetName("");
		}
		std::string A = Inst_->TaskManagerMainCol->GetNameConstRef();
		if (Inst_->TaskManagerMainCol->GetNameConstRef() == ("40"))
		{
			ChangeZPos(300);
			Inst_->TaskManagerMainCol->GetTransform().SetLocalPosition(float4(257, 170, -260));
			return;
		}
		else
			if (Inst_->TaskManagerMainCol->GetNameConstRef() == ("30"))
			{
				ChangeZPos(-1000);
				Inst_->TaskManagerMainCol->GetTransform().SetLocalPosition(float4(257, 170, 1030));
				return;
			}
	}
	
	ChangeZPos(std::stoi(Inst_->TaskManagerMainCol->GetNameConstRef()));

}

void TaskManager::End()
{
}
