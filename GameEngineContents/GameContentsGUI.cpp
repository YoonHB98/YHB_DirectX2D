#include "PreCompile.h"
#include "GameContentsGUI.h"
#include <GameEngineCore/GEngine.h>


GameContentsGUI::GameContentsGUI()
{
}

GameContentsGUI::~GameContentsGUI()
{
}


void GameContentsGUI::Initialize(class GameEngineLevel* _Level)
{

}


void GameContentsGUI::OnGUI(GameEngineLevel* _Level, float _DeltaTime)
{
	int FPS = static_cast<int>(1.0f / _DeltaTime);
	// printf 형식인데 안씀.

	std::string Name = "FPS : " + std::to_string(FPS);
	ImGui::Text(Name.c_str());

	if (true == ImGui::Button("CollisionDebugSwtich"))
	{
		GEngine::CollisionDebugSwitch();
	}

	if (true == ImGui::Button("FreeCameaOnOff"))
	{
		GEngine::GetCurrentLevel()->GetMainCameraActor()->FreeCameraModeOnOff();
	}



	ImGui::Text("StatusUp");
	if (true == ImGui::Button("Follower"))
	{
		GlobalContentsValue::Followers = GlobalContentsValue::Followers + 1000;
	}
	if (true == ImGui::Button("Stress"))
	{
		GlobalContentsValue::Stress = GlobalContentsValue::Stress + 20;
		if (GlobalContentsValue::Stress > 100)
		{
			GlobalContentsValue::Stress = 100;
		}
	}
	if (true == ImGui::Button("Affection"))
	{
		GlobalContentsValue::Affection = GlobalContentsValue::Affection + 20;
		if (GlobalContentsValue::Affection > 100)
		{
			GlobalContentsValue::Affection = 100;
		}
	}
	if (true == ImGui::Button("Mental"))
	{
		GlobalContentsValue::Mental = GlobalContentsValue::Mental + 20;
		if (GlobalContentsValue::Mental > 100)
		{
			GlobalContentsValue::Mental = 100;
		}
	}
}