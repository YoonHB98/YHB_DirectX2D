#include "ContentsCore.h"
//#include "GameEngineContents/TitleLevel.h"

#pragma comment(lib, "GameEngineBase.lib")

ContentsCore::ContentsCore() 
	: GameEngineCore()
{
}

ContentsCore::~ContentsCore() 
{
}

void ContentsCore::UserStart()
{
	// ���ҽ��� �ε��ϴµ�.

	// RTTI �� Ÿ�� Ÿ�� �������̼�
	//CreateLevel<TitleLevel>("Title");

	ChangeLevel("Title");

	// ���������� ����
	// �� ���ӿ��� Ÿ��Ʋȭ��
	//            ��������1
	//            ��������2
}

void ContentsCore::UserUpdate(float _DeltaTime)
{
	// ������ ����Ǿ���.
	// ������ ��� �޼���â�� �������Ѵ�.

	
}

void ContentsCore::UserEnd()
{
	int a = 0;
}