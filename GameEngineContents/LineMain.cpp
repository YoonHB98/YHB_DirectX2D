#include "PreCompile.h"
#include "LineMain.h"
#include "LineDate.h"

LineMain* LineMain::Inst_ = new LineMain();
LineMain::LineMain()
{
}

LineMain::~LineMain()
{
}

void LineMain::Start()
{
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture("LineMain.png");
	Renderer->GetTransform().SetLocalPosition(float4(202, -74));
	Renderer->ScaleToTexture();

	float4 Size = Renderer->GetTransform().GetLocalScale();
	Inst_->LineMainCol = CreateComponent<GameEngineCollision>();
	Inst_->LineMainCol->GetTransform().SetLocalPosition(float4(202, -74));
	Inst_->LineMainCol->GetTransform().SetLocalScale(float4(Size.x, Size.y, 5));
	Inst_->LineMainCol->ChangeOrder(OBJECTORDER::Window);
	Mouse::Inst_->ChangeNameAll();
	Inst_->LineMainCol->SetName("-90");
	SetName("");
}

void LineMain::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Line)
	{
		if (GetNameConstRef() != "")
		{
			if (GetNameConstRef() == "-100F")
			{
				SetName("-100");
			}
			Mouse::Inst_->ChangeNameAll();
			Inst_->LineMainCol->SetName(GetNameConstRef());
			SetName("");
		}
		int A = std::stoi(Inst_->LineMainCol->GetNameConstRef());
		ChangeZPos(std::stoi(Inst_->LineMainCol->GetNameConstRef()));
	}
	else
	{
		ChangeZPos(500);
		return;
	}
}

void LineMain::End()
{
}


