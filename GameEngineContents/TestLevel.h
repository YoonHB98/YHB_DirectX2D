#pragma once
#include <GameEngineCore/GameEngineLevel.h>


// Ό³Έν :
class TestLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	TestLevel();
	~TestLevel();

	// delete Function
	TestLevel(const TestLevel& _Other) = delete;
	TestLevel(TestLevel&& _Other) noexcept = delete;
	TestLevel& operator=(const TestLevel& _Other) = delete;
	TestLevel& operator=(TestLevel&& _Other) noexcept = delete;

	class YNoiseEffect* YEffect;
	Myfont* Font;
	std::string Text;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
private:
	float time;
	bool BadEnd = true;
	int CurDay = 0;
};

