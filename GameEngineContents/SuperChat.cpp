#include "PreCompile.h"
#include "SuperChat.h"
#include <GameEngineBase/GameEngineRandom.h>

SuperChat::SuperChat() 
{
}

SuperChat::~SuperChat() 
{
}

void SuperChat::Start()
{
	GameEngineSound::SoundPlayOneShot("haisin_superchat.wav");
	int Random = GameEngineRandom::MainRandom.RandomInt(0,4);
	ChatRenderer = CreateComponent<CommentTextureRenderer>();
	switch (Random)
	{
	case 0:
		ChatRenderer->SetTexture("icon_bear.png");
		break;
	case 1:
		ChatRenderer->SetTexture("icon_mendako.png");
		break;
	case 2:
		ChatRenderer->SetTexture("icon_pien_cat.png");
	case 3:
		ChatRenderer->SetTexture("icon_tea.png");
		break;
	case 4:
		ChatRenderer->SetTexture("icon_heart.png");
		break;
	default:
		break;
	}
	float RandomY = GameEngineRandom::MainRandom.RandomFloat(-200.0f, 170.0f);
	float RandomX = GameEngineRandom::MainRandom.RandomFloat(-270.0f, 300.0f);
	ChatRenderer->GetTransform().SetLocalPosition(float4(RandomX, RandomY, -300));
	ChatRenderer->GetTransform().SetLocalScale(float4(64, 64)); 
	ChatRenderer->PixelDataInst.Slice.y = 500.0f;
	ChatRenderer->SetRenderingOrder(501);
	Death(3.0f);
}

void SuperChat::Update(float _DeltaTime)
{
	Time = Time + _DeltaTime;
	if (Time < 0.2f)
	{
		ChatRenderer->GetTransform().SetLocalRotate(float4(0, 0, 200.0f* _DeltaTime));
	}else
		if (Time < 0.4f)
		{
			ChatRenderer->GetTransform().SetLocalRotate(float4(0, 0, -200.0f * _DeltaTime));
		}else
			if (Time < 0.6f)
			{
				ChatRenderer->GetTransform().SetLocalRotate(float4(0, 0, -200.0f * _DeltaTime));
			}else
				if (Time < 0.8f)
				{
					ChatRenderer->GetTransform().SetLocalRotate(float4(0, 0, 200.0f * _DeltaTime));
				}
				else
					if (Time < 1.0f)
					{
						ChatRenderer->GetTransform().SetLocalRotate(float4(0, 0, 100.0f * _DeltaTime));
					}
					else
						if (Time < 1.2f)
						{
							ChatRenderer->GetTransform().SetLocalRotate(float4(0, 0, -100.0f * _DeltaTime));
						}
						else
							if (Time < 1.4f)
							{
								ChatRenderer->GetTransform().SetLocalRotate(float4(0, 0, -100.0f * _DeltaTime));
							}
							else
								if (Time < 1.6f)
								{
									ChatRenderer->GetTransform().SetLocalRotate(float4(0, 0, 100.0f * _DeltaTime));
								}


	if (Time > 2.0f)
	{
		ChatRenderer->GetTransform().SetLocalScale(float4(64.0f - ((Time - 2.0f) * 6.0f) *16.0f, 64.0f - ((Time - 2.0f) * 6.0f) * 16.0f));
		ChatRenderer->GetTransform().SetLocalMove(float4(0, -500 * _DeltaTime, 0));
	}
	if (((Time - 2.0f) * 6.0f) * 16.0f >= 64)
	{
		ChatRenderer->GetTransform().SetLocalScale(float4(0, 0));
	}


}

void SuperChat::End()
{
}