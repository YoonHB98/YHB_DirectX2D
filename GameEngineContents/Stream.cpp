#include "PreCompile.h"
#include "Stream.h"
#include "StreamAnimation.h"
#include "PlayLevel.h"
#include "ToolTipText.h"
#include "TaskManager.h"

Stream* Stream::Inst_ = new Stream();

Stream::Stream() 
{
}

Stream::~Stream() 
{
}

void Stream::Start()
{
	SetTexture("Stream.png");
	SetLocalPosition(float4(0, 0));
	Renderer->ScaleToTexture();

	Haisin = CreateComponent<GameEngineTextureRenderer>();
	Haisin->SetTexture("Haisin.png");
	Haisin->GetTransform().SetLocalPosition(float4(0,-5));
	Haisin->GetTransform().SetLocalScale(float4(662, 440));
	
	Inst_->StreamMainCol = CreateComponent<GameEngineCollision>();
	Inst_->StreamMainCol->GetTransform().SetLocalPosition(float4(0, -5,0));
	Inst_->StreamMainCol->GetTransform().SetLocalScale(float4(662,440, 4));
	Inst_->StreamMainCol->ChangeOrder(OBJECTORDER::Window);
	Mouse::Inst_->ChangeNameAll();
	Inst_->StreamMainCol->SetName("-90");


	SetName("Stream");
}

void Stream::Update(float _DeltaTime)
{
	if (CurStatus != GlobalContentsValue::Stream)
	{
		Mouse::Inst_->ChangeNameAll();
		Mouse::Inst_->ChangeNameAll();
		Inst_->StreamMainCol->SetName("-100");
	}
	if (GlobalContentsValue::Stream == false)
	{
		ChangeZPos(500);
		first = true;
		return;
	}else
	if (GlobalContentsValue::Stream)
	{
		int a = std::stoi(Inst_->StreamMainCol->GetNameConstRef());
		ChangeZPos(static_cast<float>(std::stoi(Inst_->StreamMainCol->GetNameConstRef())));
	}
	if (GlobalContentsValue::Stream
		&&first)
	{
		if (Tutorial)
		{
			GlobalContentsValue::Tooltip = true;
			ToolTipText::Count = ToolTipText::Count + 1;
			Tutorial = false;
		}
		first = false;
		GlobalContentsValue::BgmOn = true;
		if (GlobalContentsValue::BadEnd == true)
		{
			GlobalContentsValue::BgmName = "wind.wav";
		}
		else
		{
			GlobalContentsValue::BgmName = "mainloop_kenjo.wav";
		}

	}
	if (GlobalContentsValue::ChangeTime > 200.0f)
	{
		TaskManager::Inst_->TaskManagerMainCol->SetName("-90");
	}

}

void Stream::End()
{

}