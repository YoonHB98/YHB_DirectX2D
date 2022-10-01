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
	TextDraw();
}

void NotificationText::Update(float _DeltaTime)
{
	if (GlobalContentsValue::LineNum != 1 && GlobalContentsValue::Line == false)
	{

		Font->SetScreenPostion(float4(710.0f, 492.0f - static_cast<float>(Count)));
		Count = Count + 25;
	}

	if (GlobalContentsValue::Line)
	{
		Off();
	}
}

void NotificationText::End()
{
}

void NotificationText::TextDraw()
{
	if (first && GlobalContentsValue::Line == false)
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
		case 4:
			Font->TextDraw("안녕! 스트리머가 되고...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
			GlobalContentsValue::TextConNum++;
			first = false;
			break;
		case 5:
			Font->TextDraw("안녕! 스트리머가 되고...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
			GlobalContentsValue::TextConNum++;
			first = false;
		default:
			break;
		}
	}
}
