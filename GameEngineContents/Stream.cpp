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
	
	float4 Size = Renderer->GetTransform().GetLocalScale();
	Inst_->StreamMainCol = CreateComponent<GameEngineCollision>();
	Inst_->StreamMainCol->GetTransform().SetLocalPosition(float4(0, 0,0));
	Inst_->StreamMainCol->GetTransform().SetLocalScale(float4(Size.x,Size.y, 2));
	Inst_->StreamMainCol->ChangeOrder(OBJECTORDER::Window);
	Inst_->StreamMainCol->SetName("30");


	SetName("Stream");
}

void Stream::Update(float _DeltaTime)
{

	MouseCheck(Inst_->StreamMainCol);
	if (GlobalContentsValue::Stream == false)
	{
		ChangeZPos(500);
		first = true;
		return;
	}else
	if (GlobalContentsValue::Stream)
	{
		int a = std::stoi(Inst_->StreamMainCol->GetNameConstRef());
		ChangeZPos(std::stoi(Inst_->StreamMainCol->GetNameConstRef()));
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
		TaskManager::Inst_->TaskManagerMainCol->SetName("40");
		first = false;
		Inst_->BgmPlayer = GameEngineSound::SoundPlayControl("mainloop_kenjo.wav", 999);
	}
	if (GlobalContentsValue::ChangeTime > 200.0f)
	{
		TaskManager::Inst_->TaskManagerMainCol->SetName("-90");
		Inst_->BgmPlayer.Stop();
	}

}

void Stream::End()
{

}