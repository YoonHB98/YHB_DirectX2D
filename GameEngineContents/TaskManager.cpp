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


}

void TaskManager::Update(float _DeltaTime)
{
	GlobalContentsValue::Stream = true;
	if (GlobalContentsValue::Stream == true)
	{
		if (Inst_->TaskManagerMainCol->GetNameConstRef() == ("40"))
		{
			ChangeZPos(1000);
			Inst_->TaskManagerMainCol->GetTransform().SetLocalPosition(float4(257, 170, -960));
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
