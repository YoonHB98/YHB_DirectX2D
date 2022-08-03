#include "PreCompile.h"
#include "StreamAnimation.h"

void StreamAnimation::Tutorial()
{
	Time = Time + GameEngineTime::GetDeltaTime();
	Renderer->ChangeFrameAnimation("cho_kashikoma");
}