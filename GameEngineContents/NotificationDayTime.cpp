#include "PreCompile.h"
#include "NotificationDayTime.h"

NotificationDayTime::NotificationDayTime() 
{
}

NotificationDayTime::~NotificationDayTime() 
{
}

void NotificationDayTime::Start()
{
	SetTexture(".png");
	SetLocalPosition(float4(0, 0, 0));
	SetLocalScale(float4(0, 0));
}

void NotificationDayTime::Update(float _DeltaTime)
{
}

void NotificationDayTime::End()
{
}