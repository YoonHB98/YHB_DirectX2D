#include "PreCompile.h"
#include "StreamInfo.h"

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

	if (GlobalContentsValue::Contents == "Tutorial")
	{
		Info[0]->TextDraw("초텐  등장!", "NanumBarunGothicBold", float4(180, 340), float4(222 / 255, 215 / 255, 1, 1), 14);
		Info[0]->SetRenderingOrder(500);
		Info[1]->TextDraw("189명  시청  중    ·    방송  시작일:  DAY" + std::to_string(GlobalContentsValue::Day)  , "NanumBarunGothicBold", float4(180, 365), float4(137.0f / 255.0f,135.0f / 255.0f, 135.0f/255.0f, 1), 11);
		Info[1]->SetRenderingOrder(501);
	}

}

void StreamInfo::End()
{

}