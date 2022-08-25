#include "PreCompile.h"
#include "MainBG.h"

MainBG::MainBG()
{
}

MainBG::~MainBG()
{
}

void MainBG::Start()
{
	MiddleBG = CreateComponent<GameEngineTextureRenderer>();
	MiddleBG->SetTexture("bg_main.png");
	MiddleBG->GetTransform().SetLocalScale(float4(718,540,400));
}

void MainBG::Update(float _DeltaTime)
{
}

void MainBG::End()
{
}
