#include "PreCompile.h"
#include "TestLevel.h"
#include "DayChangeWindow.h"

TestLevel::TestLevel() 
{
}

TestLevel::~TestLevel() 
{
}

void TestLevel::Start()
{
	CreateActor<DayChangeWindow>();
}

void TestLevel::Update(float _DeltaTime)
{
	// 레벨 바뀌어서 오면 초기화
	// GetAccTime();

}

void TestLevel::End()
{
	int a = 0;
}