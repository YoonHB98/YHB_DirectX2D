#include "PreCompile.h"
#include "WindowIcon.h"
#include "BadEndWindow.h"

WindowIcon::WindowIcon()
{
}

WindowIcon::~WindowIcon()
{
}

void WindowIcon::Start()
{
	{
		Youtube[0] = CreateComponent<GameEngineTextureRenderer>();
		Youtube[0]->SetTexture("icon_desktop_youtube.png");
		Youtube[0]->GetTransform().SetLocalPosition(float4(-305, 230, -10));
		Youtube[0]->GetTransform().SetLocalScale(float4(32, 32));
		Youtube[1] = CreateComponent<GameEngineTextureRenderer>();
		Youtube[1]->SetTexture("BangSong.png");
		Youtube[1]->GetTransform().SetLocalPosition(float4(-305,200, -10));
		Youtube[1]->GetTransform().SetLocalScale(float4(32, 16.5));
		YoutubeCol = CreateComponent<GameEngineCollision>();
		YoutubeCol->GetTransform().SetLocalPosition(float4(-305, 230, -30));
		YoutubeCol->GetTransform().SetLocalScale(float4(32, 32));
		YoutubeCol->ChangeOrder(OBJECTORDER::UI);
		YoutubeCol->SetName("Youtube");
	}
	{
		Asobu[0] = CreateComponent<GameEngineTextureRenderer>();
		Asobu[0]->SetTexture("icon_desktop_asobu.png");
		Asobu[0]->GetTransform().SetLocalPosition(float4(-305, 165, -10));
		Asobu[0]->GetTransform().SetLocalScale(float4(32, 32));
		Asobu[1] = CreateComponent<GameEngineTextureRenderer>();
		Asobu[1]->SetTexture("Nolgi.png");
		Asobu[1]->GetTransform().SetLocalPosition(float4(-305, 135, -10));
		Asobu[1]->GetTransform().SetLocalScale(float4(32, 16.5));
		AsobuCol = CreateComponent<GameEngineCollision>();
		AsobuCol->GetTransform().SetLocalPosition(float4(-305, 165, 0));
		AsobuCol->GetTransform().SetLocalScale(float4(32, 32));
		AsobuCol->ChangeOrder(OBJECTORDER::UI);
		AsobuCol->SetName("Asobu");
	}
	{
		Neru[0] = CreateComponent<GameEngineTextureRenderer>();
		Neru[0]->SetTexture("icon_desktop_neru.png");
		Neru[0]->GetTransform().SetLocalPosition(float4(-305, 100, -10));
		Neru[0]->GetTransform().SetLocalScale(float4(32, 32));
		Neru[1] = CreateComponent<GameEngineTextureRenderer>();
		Neru[1]->SetTexture("husik.png");
		Neru[1]->GetTransform().SetLocalPosition(float4(-305, 70, -10));
		Neru[1]->GetTransform().SetLocalScale(float4(32, 16.5));
		NeruCol = CreateComponent<GameEngineCollision>();
		NeruCol->GetTransform().SetLocalPosition(float4(-305, 100, 0));
		NeruCol->GetTransform().SetLocalScale(float4(32, 32));
		NeruCol->ChangeOrder(OBJECTORDER::UI);
		NeruCol->SetName("Neru");
	}
	{
		Okusuri[0] = CreateComponent<GameEngineTextureRenderer>();
		Okusuri[0]->SetTexture("icon_desktop_okusuri.png");
		Okusuri[0]->GetTransform().SetLocalPosition(float4(-305, 35, -10));
		Okusuri[0]->GetTransform().SetLocalScale(float4(32, 32));
		Okusuri[1] = CreateComponent<GameEngineTextureRenderer>();
		Okusuri[1]->SetTexture("YakMukgi.png");
		Okusuri[1]->GetTransform().SetLocalPosition(float4(-305, 5, -10));
		Okusuri[1]->GetTransform().SetLocalScale(float4(32, 16.5));
		OkusuriCol = CreateComponent<GameEngineCollision>();
		OkusuriCol->GetTransform().SetLocalPosition(float4(-305, 35, 0));
		OkusuriCol->GetTransform().SetLocalScale(float4(32, 32));
		OkusuriCol->ChangeOrder(OBJECTORDER::UI);
		OkusuriCol->SetName("Okusuri");
	}
	{
		Internet[0] = CreateComponent<GameEngineTextureRenderer>();
		Internet[0]->GetTransform().SetLocalPosition(float4(-305, -30, -10));
		Internet[0]->CreateFrameAnimationCutTexture("Internet", FrameAnimation_DESC("icon_desktop_internet.png", 0, 0, 0.1f, false));
		Internet[0]->ChangeFrameAnimation("Internet");
		Internet[0]->GetTransform().SetLocalScale(float4(32, 32));
		Internet[1] = CreateComponent<GameEngineTextureRenderer>();
		Internet[1]->SetTexture("Internetname.png");
		Internet[1]->GetTransform().SetLocalPosition(float4(-305, -60, -10));
		Internet[1]->GetTransform().SetLocalScale(float4(32, 16.5));
		InternetCol = CreateComponent<GameEngineCollision>();
		InternetCol->GetTransform().SetLocalPosition(float4(-305, -30, 0));
		InternetCol->GetTransform().SetLocalScale(float4(32, 32));
		InternetCol->ChangeOrder(OBJECTORDER::UI);
		InternetCol->SetName("Internet");
	}
	{
		Odekake[0] = CreateComponent<GameEngineTextureRenderer>();
		Odekake[0]->SetTexture("icon_desktop_odekake.png");
		Odekake[0]->GetTransform().SetLocalPosition(float4(-305, -95, -10));
		Odekake[0]->GetTransform().SetLocalScale(float4(32, 32));
		Odekake[1] = CreateComponent<GameEngineTextureRenderer>();
		Odekake[1]->SetTexture("whaechul.png");
		Odekake[1]->GetTransform().SetLocalPosition(float4(-305, -125, -10));
		Odekake[1]->GetTransform().SetLocalScale(float4(32, 16.5));
		OdekakeCol = CreateComponent<GameEngineCollision>();
		OdekakeCol->GetTransform().SetLocalPosition(float4(-305, -95, 0));
		OdekakeCol->GetTransform().SetLocalScale(float4(32, 32));
		OdekakeCol->ChangeOrder(OBJECTORDER::UI);
		OdekakeCol->SetName("Odekake");
	}
	//{
	//	Tex = CreateComponent<GameEngineTextureRenderer>();
	//	Tex->SetTexture("icon_desktop_text.png");
	//	Tex->GetTransform().SetLocalPosition(float4(0, 135, 0));
	//	Tex->GetTransform().SetLocalScale(float4(32, 32));
	//}
	for (int i = 0; i < 2; i++)
	{
		Youtube[i]->GetPixelData().PlusColor.a = -1.0f;
		Youtube[i]->GetPixelData().MulColor.a = 0.0f;
		Internet[i]->GetPixelData().MulColor.a = 0.0f;
		Asobu[i]->GetPixelData().MulColor.a = 0.0f;
		Neru[i]->GetPixelData().MulColor.a = 0.0f;
		Okusuri[i]->GetPixelData().MulColor.a = 0.0f;
		Odekake[i]->GetPixelData().MulColor.a = 0.0f;
	}

}

void WindowIcon::Update(float _DeltaTime)
{

	if (GlobalContentsValue::Stream)
	{
		ChangeZPos(500);
		return;
	}
	else
	{
		ChangeZPos(-10);
	}
	if (GlobalContentsValue::Tutorial == false)
	{
		for (int i = 0; i < 2; i++)
		{
			Youtube[i]->GetPixelData().MulColor.a = 1.0f;
			Internet[i]->GetPixelData().MulColor.a = 1.0f;
			Asobu[i]->GetPixelData().MulColor.a = 1.0f;
			Neru[i]->GetPixelData().MulColor.a = 1.0f;
			Okusuri[i]->GetPixelData().MulColor.a = 1.0f;
			Odekake[i]->GetPixelData().MulColor.a = 1.0f;
		}
	}
	if (MouseCheck(YoutubeCol)
		&& true == GameEngineInput::GetInst()->IsDown("MouseClick"))
	{
		if (GlobalContentsValue::Tooltip)
		{
			Youtube[0]->GetPixelData().MulColor.a = 1.0f;
			Youtube[1]->GetPixelData().MulColor.a = 1.0f;
			GlobalContentsValue::TutorialLogin = true;
		}else
			if (GlobalContentsValue::BadEnd)
			{
				GetLevel()->CreateActor<BadEndWindow>();
			}
	}
	if (GlobalContentsValue::BadEnd
		&&GlobalContentsValue::RemainLinenum <= 0)
	{
		Youtube[0]->GetPixelData().MulColor.a = 1.0f;
		Internet[0]->GetPixelData().MulColor.a = 0.0f;
		Asobu[0]->GetPixelData().MulColor.a = 0.0f;
		Neru[0]->GetPixelData().MulColor.a = 0.0f;
		Okusuri[0]->GetPixelData().MulColor.a = 0.0f;
		Odekake[0]->GetPixelData().MulColor.a = 0.0f;

		Youtube[1]->GetPixelData().MulColor.a = 1.0f;
		Internet[1]->GetPixelData().MulColor.a = 0.0f;
		Asobu[1]->GetPixelData().MulColor.a = 0.0f;
		Neru[1]->GetPixelData().MulColor.a = 0.0f;
		Okusuri[1]->GetPixelData().MulColor.a = 0.0f;
		Odekake[1]->GetPixelData().MulColor.a = 0.0f;
	}else
	if (GlobalContentsValue::BadEnd
		&&GlobalContentsValue::Tutorial != true)
	{
		Youtube[0]->GetPixelData().MulColor.a = 0.0f;
		Internet[0]->GetPixelData().MulColor.a = 0.0f;
		Asobu[0]->GetPixelData().MulColor.a = 0.0f;
		Neru[0]->GetPixelData().MulColor.a = 0.0f;
		Okusuri[0]->GetPixelData().MulColor.a = 0.0f;
		Odekake[0]->GetPixelData().MulColor.a = 0.0f;

		Youtube[1]->GetPixelData().MulColor.a = 0.0f;
		Internet[1]->GetPixelData().MulColor.a = 0.0f;
		Asobu[1]->GetPixelData().MulColor.a = 0.0f;
		Neru[1]->GetPixelData().MulColor.a = 0.0f;
		Okusuri[1]->GetPixelData().MulColor.a = 0.0f;
		Odekake[1]->GetPixelData().MulColor.a = 0.0f;
		return;
	}
	else
	{
		Youtube[0]->GetPixelData().MulColor.a = 1.0f;
		Internet[0]->GetPixelData().MulColor.a = 1.0f;
		Asobu[0]->GetPixelData().MulColor.a = 1.0f;
		Neru[0]->GetPixelData().MulColor.a = 1.0f;
		Okusuri[0]->GetPixelData().MulColor.a = 1.0f;
		Odekake[0]->GetPixelData().MulColor.a = 1.0f;

		Youtube[1]->GetPixelData().MulColor.a = 1.0f;
		Internet[1]->GetPixelData().MulColor.a = 1.0f;
		Asobu[1]->GetPixelData().MulColor.a = 1.0f;
		Neru[1]->GetPixelData().MulColor.a = 1.0f;
		Okusuri[1]->GetPixelData().MulColor.a = 1.0f;
		Odekake[1]->GetPixelData().MulColor.a = 1.0f;
	}
	if (GlobalContentsValue::Tooltip)
	{
		Youtube[0]->GetPixelData().MulColor.a = 1.0f;
		Youtube[1]->GetPixelData().MulColor.a = 1.0f;
	}
	if (GlobalContentsValue::Contents == "Tutorial")
	{
		return;
	}
	MouseClick();
}

void WindowIcon::End()
{
}

void WindowIcon::MouseClick()
{
	GameEngineCollision* Array[6]{NeruCol, InternetCol, AsobuCol, OkusuriCol, OdekakeCol, YoutubeCol};
	for (int i = 0; i < 6; i++)
	{
		if (Array[i]->IsCollision(CollisionType::CT_OBB, OBJECTORDER::Mouse, CollisionType::CT_OBB,
			std::bind(&WindowIcon::WindowOn, this, std::placeholders::_1, std::placeholders::_2)))
		{
		}
	}

}

bool WindowIcon::WindowOn(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
	{
		std::string Name = _This->GetNameConstRef();
		WindowIcon::Swich(Name);
	}

	return true;
}

void WindowIcon::Swich(std::string Name_)
{
	if (Name_ == "Asobu")
	{
		GlobalContentsValue::Asobu = true;
	}else
		if (Name_ == "Neru")
		{
			GlobalContentsValue::Neru = true;
		}
		else
			if (Name_ == "Okusuri")
			{
				GlobalContentsValue::Okusuri = true;
			}
			else
				if (Name_ == "Internet")
				{
					GlobalContentsValue::Internet = true;
				}
				else
					if (Name_ == "Odekake")
					{
						GlobalContentsValue::Odekake = true;
					}
					else
						if (Name_ == "Youtube")
						{
							GlobalContentsValue::Youtube = true;
						}
}