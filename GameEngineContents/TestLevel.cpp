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
	// ���� �ٲ� ���� �ʱ�ȭ
	// GetAccTime();

}

void TestLevel::End()
{
	int a = 0;
}