#include "PreCompile.h"
#include "NotificationText.h"

NotificationText::NotificationText() 
{
}

NotificationText::~NotificationText() 
{
}

void NotificationText::Start()
{
}

void NotificationText::Update(float _DeltaTime)
{
	TextDraw();
	if (GlobalContentsValue::Line)
	{
		Death();
	}
}

void NotificationText::End()
{
}

void NotificationText::TextDraw()
{
	if (first)
	{
		Font = CreateComponent<Myfont>();
		switch (GlobalContentsValue::TextConNum)
		{
		case 0:
			Font->TextDraw("��ۿ� ������ �������...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
			GlobalContentsValue::TextConNum++;
			first = false;
			break;
		case 1:
			Font->TextDraw("��й�ȣ�� angelkawaii...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
			GlobalContentsValue::TextConNum++;
			first = false;
			break;
		default:
			break;
		}
	}
	if (GlobalContentsValue::LineNum != 1)
	{

		Font->SetScreenPostion(float4(710, 492 - Count));
		Count = Count + 25;
	}
	
}
