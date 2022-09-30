#pragma once
#include <GameEngineCore/GameEngineStatusWindow.h>


// Ό³Έν :
class GameContentsGUI : public GameEngineGUIWindow
{
public:
	// constrcuter destructer
	GameContentsGUI();
	~GameContentsGUI();

	// delete Function
	GameContentsGUI(const GameContentsGUI& _Other) = delete;
	GameContentsGUI(GameContentsGUI&& _Other) noexcept = delete;
	GameContentsGUI& operator=(const GameContentsGUI& _Other) = delete;
	GameContentsGUI& operator=(GameContentsGUI&& _Other) noexcept = delete;

protected:

private:
	void Initialize(class GameEngineLevel* _Level) override;
	void OnGUI(GameEngineLevel* _Level, float _DeltaTime) override;

};

