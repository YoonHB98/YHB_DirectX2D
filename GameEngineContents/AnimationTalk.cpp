#include "PreCompile.h"
#include "StreamAnimation.h"

void StreamAnimation::Talk()
{
	GlobalContentsValue::ChangeTime = GlobalContentsValue::ChangeTime + GameEngineTime::GetDeltaTime();
	Time = Time + GameEngineTime::GetDeltaTime();
	StateUpdate(CurType);
}

void StreamAnimation::UpdateB1()
{

}

void StreamAnimation::UpdateB2()
{

}
void StreamAnimation::UpdateB3()
{

}
void StreamAnimation::UpdateB4()
{

}
void StreamAnimation::UpdateB5()
{

}
void StreamAnimation::UpdateB6()
{

}
void StreamAnimation::UpdateB7()
{

}
void StreamAnimation::UpdateB8()
{

}
void StreamAnimation::UpdateB9()
{

}