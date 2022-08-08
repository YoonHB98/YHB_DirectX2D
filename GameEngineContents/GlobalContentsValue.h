#pragma once
#include <GameEngineCore/CoreMinimal.h>


// 설명 :
class GlobalContentsValue
{
public:
	//켜있는지 확인
	static float4 MousePos;
	static bool WebCamWindow;
	static bool Line;
	static bool Change;
	static bool Tooltip;
	//스테이터스
	static int Mental;
	static int Stress;
	static int Affection;
	static int Followers;
	//날짜
	static int Day;
	static bool Tutorial;
	//라인
	static int LineNum;
	static int RemainLinenum;
	static bool Message;
	static bool Stream;
	static int TextConNum;
	static std::string TextContents;
	//시간
	static int DayTime;
	//행동
	static bool Out;
	//뭔 방송임
	static std::string Contents;

private:
	GlobalContentsValue()	{	}

	~GlobalContentsValue()	{	}
};

enum class OBJECTORDER
{
	Mouse,
	UI
};