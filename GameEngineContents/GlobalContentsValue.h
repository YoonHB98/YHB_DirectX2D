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

	static bool Asobu;
	static bool Neru;
	static bool Okusuri;
	static bool Internet;
	static bool Odekake;
	static bool Youtube;
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
	static bool Sojae;
	//�ð�
	static int DayTime;
	static bool LineDate;
	//�ൿ
	static bool Out;
	static bool DayTimeChange;
	//�� �����
	static std::string Contents;
	static std::string CommentContents;
	static float ChangeTime;
	static std::string FirstComment;
	static std::string SecondComment;

	//����
	static bool LoveEnd;


	static int RemainTwitnum;
	//bgm
	static std::string BgmName;
	static float BgmSpeed;
	static bool BgmStop;
	//üũ�ϰ� �ִ���
	static bool Check;

	//������
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