#include "PreCompile.h"
#include "StreamInfo.h"
#include "GameEngineBase/GameEngineRandom.h"

StreamInfo::StreamInfo()
{
}

StreamInfo::~StreamInfo()
{
}

void StreamInfo::Start()
{
	Info[0] = CreateComponent<Myfont>();
	Info[1] = CreateComponent<Myfont>();
}

void StreamInfo::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Stream != true)
	{
		Death();
	}
	if (GlobalContentsValue::Stream == false)
	{
		return;
	}
	if (time > 1.0f)
	{
		time = time - 1.0f;
		Num = GameEngineRandom::MainRandom.RandomInt(0, 10);
	}
	if (GlobalContentsValue::Contents == "Tutorial")
	{
		Info[0]->TextDraw("����  ����!", "NanumBarunGothicBold", float4(180, 340), float4(222 / 255, 215 / 255, 1, 1), 14);
		Info[0]->SetRenderingOrder(500);
		Info[1]->TextDraw(std::to_string(189 + Num) + "��  ��û  ��    ��    ���  ������:  DAY" + std::to_string(GlobalContentsValue::Day)  , "NanumBarunGothicBold", float4(180, 365), float4(137.0f / 255.0f,135.0f / 255.0f, 135.0f/255.0f, 1), 11);
		Info[1]->SetRenderingOrder(501);
	}
	if (GlobalContentsValue::Contents == "CommunicationStream")
	{
		Info[0]->TextDraw("���ͳ���  ���̵�����  �ð�", "NanumBarunGothicBold", float4(180, 340), float4(222 / 255, 215 / 255, 1, 1), 14);
		Info[0]->SetRenderingOrder(500);
		Info[1]->TextDraw(std::to_string(201 + Num *2)+"��  ��û  ��    ��    ���  ������ : DAY" + std::to_string(GlobalContentsValue::Day), "NanumBarunGothicBold", float4(180, 365), float4(137.0f / 255.0f, 135.0f / 255.0f, 135.0f / 255.0f, 1), 11);
		Info[1]->SetRenderingOrder(501);
	}
	if (GlobalContentsValue::Contents == "GoodEndingStream")
	{
		Info[0]->TextDraw("����Ʈ��  ���~~", "NanumBarunGothicBold", float4(180, 340), float4(222 / 255, 215 / 255, 1, 1), 14);
		Info[0]->SetRenderingOrder(500);
		Info[1]->TextDraw(std::to_string(246990 + Num * 5) + "��  ��û  ��    ��    ���  ������:  DAY" + std::to_string(GlobalContentsValue::Day), "NanumBarunGothicBold", float4(180, 365), float4(137.0f / 255.0f, 135.0f / 255.0f, 135.0f / 255.0f, 1), 11);
		Info[1]->SetRenderingOrder(501);
	}
	if (GlobalContentsValue::Contents == "BadEndingStream")
	{
		Info[0]->TextDraw("�ۺ�  ���", "NanumBarunGothicBold", float4(180, 340), float4(222 / 255, 215 / 255, 1, 1), 14);
		Info[0]->SetRenderingOrder(500);
		Info[1]->TextDraw(std::to_string(43270 + Num)+"��  ��û  ��    ��    ���  ������:  DAY" + std::to_string(GlobalContentsValue::Day), "NanumBarunGothicBold", float4(180, 365), float4(137.0f / 255.0f, 135.0f / 255.0f, 135.0f / 255.0f, 1), 11);
		Info[1]->SetRenderingOrder(501);
	}

}

void StreamInfo::End()
{

}