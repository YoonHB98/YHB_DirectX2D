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
	static bool Twitter;
	static bool TutorialLogin;
	static bool DayChangeWindow;
	static bool BgmOn;

	static bool Asobu;
	static bool Neru;
	static bool Okusuri;
	static bool Internet;
	static bool Odekake;
	static bool Youtube;
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
	static int EomticonStatus;
	static std::string TextContents;
	static std::string CurEmoticonName;
	static bool Sojae;
	//시간
	static int DayTime;
	static bool LineDate;
	//행동
	static bool Out;
	static bool DayTimeChange;
	//뭔 방송임
	static std::string Contents;
	static std::string CommentContents;
	static float ChangeTime;
	static std::string FirstComment;
	static std::string SecondComment;

	//엔딩
	static bool LoveEnd;


	static int RemainTwitnum;
	//bgm
	static std::string BgmName;
	static float BgmSpeed;
	static bool BgmStop;
	//체크하고 있는지
	static bool Check;

	//윈도우
	static std::string Asobu_Window;
	static std::string Stream_Window;

	static bool Console;

private:
	GlobalContentsValue()	{	}

	~GlobalContentsValue()	{	}
};

enum class OBJECTORDER
{
	Mouse,
	UI,
	SuperChat,
	Window,
	Emoticon,
	Exit,
	Click
};