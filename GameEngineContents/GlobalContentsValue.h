#pragma once
#include <GameEngineCore/CoreMinimal.h>


// ���� :
class GlobalContentsValue
{
public:


	//�������ͽ�
	static int Mental;
	static int Stress;
	static int Affection;
	static int Followers;
	//��¥
	static int Day;
	//����
	static int LineNum;
	static int RemainLinenum;
	static bool Message;
	static bool Stream;
	//�ð�
	static int DayTime;
	//�ൿ
	static bool Out;

private:
	GlobalContentsValue()	{	}

	~GlobalContentsValue()	{	}
};

