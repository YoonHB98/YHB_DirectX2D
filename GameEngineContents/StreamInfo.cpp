#include "PreCompile.h"
#include "StreamAnimation.h"


void StreamAnimation::StreamInfomation()
{
	if (GlobalContentsValue::Stream != true
		&& InfoFirst == true)
	{
		InfoFirst = false;
		Info[0]->TextDraw(" ", "NanumBarunGothicBold", float4(180, 340), float4(222 / 255, 215 / 255, 1, 1), 14);
		Info[1]->TextDraw(" " + std::to_string(GlobalContentsValue::Day), "NanumBarunGothicBold", float4(180, 365), float4(137.0f / 255.0f, 135.0f / 255.0f, 135.0f / 255.0f, 1), 11);
		return;
	}
	if (GlobalContentsValue::Stream == false)
	{
		return;
	}

	if (GlobalContentsValue::Contents == "Tutorial")
	{
		Info[0]->TextDraw("����  ����!", "NanumBarunGothicBold", float4(180, 340), float4(222 / 255, 215 / 255, 1, 1), 14);
		Info[0]->SetRenderingOrder(500);
		Info[1]->TextDraw("189��  ��û  ��    ��    ���  ������:  DAY" + std::to_string(GlobalContentsValue::Day)  , "NanumBarunGothicBold", float4(180, 365), float4(137.0f / 255.0f,135.0f / 255.0f, 135.0f/255.0f, 1), 11);
		Info[1]->SetRenderingOrder(501);
		InfoFirst = true;
	}

}