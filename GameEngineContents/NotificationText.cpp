#include "PreCompile.h"
#include "NotificationText.h"
#include "LineText.h"

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
		if (GlobalContentsValue::TextContents == "LineD")
		{
			switch (LineText::DCount)
			{
				case 1:
					Font->TextDraw("방송 열심히 할 테니까...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
					GlobalContentsValue::TextConNum++;
					first = false;
					break;
				case 2:
					Font->TextDraw("P~ 밥 다 됐어! 지금 바...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
					GlobalContentsValue::TextConNum++;
					first = false;
					break;
				case 3:
					Font->TextDraw("[긴급상황!]...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
					GlobalContentsValue::TextConNum++;
					first = false;
					break;
				case 4:
					Font->TextDraw("잠들기 전까지 돈...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
					GlobalContentsValue::TextConNum++;
					first = false;
					break;
				case 5:
					Font->TextDraw("만약에 내가 격투게임...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
					GlobalContentsValue::TextConNum++;
					first = false;
					break;
				case 6:
					Font->TextDraw("갑자기 방이 100배로...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
					GlobalContentsValue::TextConNum++;
					first = false;
					break;
			}
			return;
		}
		else if (GlobalContentsValue::TextContents == "BadEnding")
		{
			switch (GlobalContentsValue::TextConNum)
			{
			case 1:
				Font->TextDraw("아핫 왠지 지쳐...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
				GlobalContentsValue::TextConNum++;
				first = false;
				break;
			case 2:
				Font->TextDraw("열심히 했는데 팔...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
				GlobalContentsValue::TextConNum++;
				first = false;
				break;
			case 3:
				Font->TextDraw("그런데 상처만 많...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
				GlobalContentsValue::TextConNum++;
				first = false;
				break;
			}
				return;
		}
		else if (GlobalContentsValue::TextContents == "GoodEnding")
		{
			switch (GlobalContentsValue::TextConNum)
			{
			case 1:
				Font->TextDraw("에헤헤, 한 달 동안...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
				GlobalContentsValue::TextConNum++;
				first = false;
				break;
			case 2:
				Font->TextDraw("정신차려보니 이렇게...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
				GlobalContentsValue::TextConNum++;
				first = false;
				break;
			case 3:
				Font->TextDraw("P 수고했어!", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
				GlobalContentsValue::TextConNum++;
				first = false;
				break;
			}
			return;
		}
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
