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
	MiddleBG->ScaleToTexture();
}

void MainBG::Update(float _DeltaTime)
{
}

void MainBG::End()
{
}
