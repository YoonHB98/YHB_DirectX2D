#pragma once
#include <GameEngineCore/CoreMinimal.h>


// 설명 :
class GlobalContentsValue
{
public:


	//스테이터스
	static int Mental;
	static int Stress;
	static int Affection;
	static int Followers;
	//날짜
	static int Day;
	//라인
	static int LineNum;
	static int RemainLinenum;
	static bool Message;
	static bool Stream;
	//시간
	static int DayTime;
	//행동
	static bool Out;

private:
	GlobalContentsValue()	{	}

	~GlobalContentsValue()	{	}
};

