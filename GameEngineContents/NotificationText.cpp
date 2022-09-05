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
	if (GlobalContentsValue::Line)
	{
		Off();
		return;
	}
	TextDraw();
}

void NotificationText::End()
{
}

void NotificationText::TextDraw()
{
	if (first)
	{
		Font = CreateComponent<Myfont>();
		Font->SetRenderingOrder(500);
		switch (GlobalContentsValue::TextConNum)
		{
		case 0:
			Font->TextDraw("방송용 계정을 만들었어...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
			GlobalContentsValue::TextConNum++;
			first = false;
			break;
		case 1:
			Font->TextDraw("비밀번호는 angelkawaii...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
			GlobalContentsValue::TextConNum++;
			first = false;
			break;
		case 2:
			Font->TextDraw("하아~ 긴장했어...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
			GlobalContentsValue::TextConNum++;
			first = false;
			break;
		case 3:
			Font->TextDraw("둘이서 열심히 만들어...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
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
