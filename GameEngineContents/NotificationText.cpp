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
					Font->TextDraw("��� ������ �� �״ϱ�...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
					GlobalContentsValue::TextConNum++;
					first = false;
					break;
				case 2:
					Font->TextDraw("P~ �� �� �ƾ�! ���� ��...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
					GlobalContentsValue::TextConNum++;
					first = false;
					break;
				case 3:
					Font->TextDraw("[��޻�Ȳ!]...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
					GlobalContentsValue::TextConNum++;
					first = false;
					break;
				case 4:
					Font->TextDraw("���� ������ ��...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
					GlobalContentsValue::TextConNum++;
					first = false;
					break;
				case 5:
					Font->TextDraw("���࿡ ���� ��������...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
					GlobalContentsValue::TextConNum++;
					first = false;
					break;
				case 6:
					Font->TextDraw("���ڱ� ���� 100���...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
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
				Font->TextDraw("���� ���� ����...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
				GlobalContentsValue::TextConNum++;
				first = false;
				break;
			case 2:
				Font->TextDraw("������ �ߴµ� ��...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
				GlobalContentsValue::TextConNum++;
				first = false;
				break;
			case 3:
				Font->TextDraw("�׷��� ��ó�� ��...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
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
				Font->TextDraw("������, �� �� ����...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
				GlobalContentsValue::TextConNum++;
				first = false;
				break;
			case 2:
				Font->TextDraw("������������ �̷���...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
				GlobalContentsValue::TextConNum++;
				first = false;
				break;
			case 3:
				Font->TextDraw("P �����߾�!", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
				GlobalContentsValue::TextConNum++;
				first = false;
				break;
			}
			return;
		}
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
		case 2:
			Font->TextDraw("�Ͼ�~ �����߾�...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
			GlobalContentsValue::TextConNum++;
			first = false;
			break;
		case 3:
			Font->TextDraw("���̼� ������ �����...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
			GlobalContentsValue::TextConNum++;
			first = false;
			break;
		case 4:
			Font->TextDraw("�ȳ�! ��Ʈ���Ӱ� �ǰ�...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
			GlobalContentsValue::TextConNum++;
			first = false;
			break;
		case 5:
			Font->TextDraw("�ȳ�! ��Ʈ���Ӱ� �ǰ�...", "Galmuri9", float4(710, 492), float4(0.271f, 0.3294f, 0.56862f, 1), 10.0f);
			GlobalContentsValue::TextConNum++;
			first = false;
		default:
			break;
		}
	}
}
