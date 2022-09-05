#include "PreCompile.h"
#include "WindowIcon.h"

WindowIcon::WindowIcon()
{
}

WindowIcon::~WindowIcon()
{
}

void WindowIcon::Start()
{
	{
		Youtube = CreateComponent<GameEngineTextureRenderer>();
		Youtube->SetTexture("icon_desktop_youtube.png");
		Youtube->GetTransform().SetLocalPosition(float4(-305, 230, -10));
		Youtube->GetTransform().SetLocalScale(float4(32, 32));
		YoutubeCol = CreateComponent<GameEngineCollision>();
		YoutubeCol->GetTransform().SetLocalPosition(float4(-305, 230, -30));
		YoutubeCol->GetTransform().SetLocalScale(float4(32, 32));
		YoutubeCol->ChangeOrder(OBJECTORDER::UI);
	}
	{
		Asobu = CreateComponent<GameEngineTextureRenderer>();
		Asobu->SetTexture("icon_desktop_asobu.png");
		Asobu->GetTransform().SetLocalPosition(float4(-305, 165, -10));
		Asobu->GetTransform().SetLocalScale(float4(32, 32));
		AsobuCol = CreateComponent<GameEngineCollision>();
		AsobuCol->GetTransform().SetLocalPosition(float4(-305, 165, 0));
		AsobuCol->GetTransform().SetLocalScale(float4(32, 32));
		AsobuCol->ChangeOrder(OBJECTORDER::UI);
	}
	{
		Neru = CreateComponent<GameEngineTextureRenderer>();
		Neru->SetTexture("icon_desktop_neru.png");
		Neru->GetTransform().SetLocalPosition(float4(-305, 100, -10));
		Neru->GetTransform().SetLocalScale(float4(32, 32));
		NeruCol = CreateComponent<GameEngineCollision>();
		NeruCol->GetTransform().SetLocalPosition(float4(-305, 100, 0));
		NeruCol->GetTransform().SetLocalScale(float4(32, 32));
		NeruCol->ChangeOrder(OBJECTORDER::UI);
	}
	{
		Okusuri = CreateComponent<GameEngineTextureRenderer>();
		Okusuri->SetTexture("icon_desktop_okusuri.png");
		Okusuri->GetTransform().SetLocalPosition(float4(-305, 35, -10));
		Okusuri->GetTransform().SetLocalScale(float4(32, 32));
		OkusuriCol = CreateComponent<GameEngineCollision>();
		OkusuriCol->GetTransform().SetLocalPosition(float4(-305, 35, 0));
		OkusuriCol->GetTransform().SetLocalScale(float4(32, 32));
		OkusuriCol->ChangeOrder(OBJECTORDER::UI);
	}
	{
		Internet = CreateComponent<GameEngineTextureRenderer>();
		Internet->GetTransform().SetLocalPosition(float4(-305, -30, -10));
		Internet->CreateFrameAnimationCutTexture("Internet", FrameAnimation_DESC("icon_desktop_internet.png", 0, 0, 0.1f, false));
		Internet->ChangeFrameAnimation("Internet");
		Internet->GetTransform().SetLocalScale(float4(32, 32));
		InternetCol = CreateComponent<GameEngineCollision>();
		InternetCol->GetTransform().SetLocalPosition(float4(-305, -30, 0));
		InternetCol->GetTransform().SetLocalScale(float4(32, 32));
		InternetCol->ChangeOrder(OBJECTORDER::UI);
	}
	{
		Odekake = CreateComponent<GameEngineTextureRenderer>();
		Odekake->SetTexture("icon_desktop_odekake.png");
		Odekake->GetTransform().SetLocalPosition(float4(-305, -95, -10));
		Odekake->GetTransform().SetLocalScale(float4(32, 32));
		OdekakeCol = CreateComponent<GameEngineCollision>();
		OdekakeCol->GetTransform().SetLocalPosition(float4(-305, -95, 0));
		OdekakeCol->GetTransform().SetLocalScale(float4(32, 32));
		OdekakeCol->ChangeOrder(OBJECTORDER::UI);
	}
	//{
	//	Tex = CreateComponent<GameEngineTextureRenderer>();
	//	Tex->SetTexture("icon_desktop_text.png");
	//	Tex->GetTransform().SetLocalPosition(float4(0, 135, 0));
	//	Tex->GetTransform().SetLocalScale(float4(32, 32));
	//}
	Youtube->GetPixelData().MulColor.a = 0.2f;
	Internet->GetPixelData().MulColor.a = 0.2f;
	Asobu->GetPixelData().MulColor.a = 0.2f;
	Neru->GetPixelData().MulColor.a = 0.2f;
	Okusuri->GetPixelData().MulColor.a = 0.2f;
	Odekake->GetPixelData().MulColor.a = 0.2f;
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
		Youtube->GetPixelData().MulColor.a = 1.0f;
		Internet->GetPixelData().MulColor.a = 1.0f;
		Asobu->GetPixelData().MulColor.a = 1.0f;
		Neru->GetPixelData().MulColor.a = 1.0f;
		Okusuri->GetPixelData().MulColor.a = 1.0f;
		Odekake->GetPixelData().MulColor.a = 1.0f;
	}
	if (MouseCheck(YoutubeCol)
		&& true == GameEngineInput::GetInst()->IsDown("MouseClick"))
	{
		if (GlobalContentsValue::Tooltip)
		{
			Youtube->GetPixelData().MulColor.a = 1.0f;
			GlobalContentsValue::TutorialLogin = true;
		}
	}
	if (GlobalContentsValue::Tooltip)
	{
		Youtube->GetPixelData().MulColor.a = 1.0f;
	}


}

void WindowIcon::End()
{
}
