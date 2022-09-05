#pragma once
#include <GameEngineCore/CoreMinimal.h>


// ���� :
class GlobalContentsValue
{
public:
	//���ִ��� Ȯ��
	static float4 MousePos;
	static bool WebCamWindow;
	static bool Line;
	static bool Change;
	static bool Tooltip;
	static bool Twitter;
	static bool TutorialLogin;
	static bool DayChangeWindow;
	static bool BgmOn;
	//�������ͽ�
	static int Mental;
	static int Stress;
	static int Affection;
	static int Followers;
	//��¥
	static int Day;
	static bool Tutorial;
	//����
	static int LineNum;
	static int RemainLinenum;
	static bool Message;
	static bool Stream;
	static int TextConNum;
	static int EomticonStatus;
	static std::string TextContents;
	static std::string CurEmoticonName;
	//�ð�
	static int DayTime;
	//�ൿ
	static bool Out;
	//�� �����
	static std::string Contents;
	static float ChangeTime;
	static std::string FirstComment;
	static std::string SecondComment;

	static int RemainTwitnum;
	//bgm
	static std::string BgmName;
	static int BgmSpeed;
	static bool BgmStop;
	//üũ�ϰ� �ִ���
	static bool Check;

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
	Exit
};