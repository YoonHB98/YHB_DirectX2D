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
		Youtube->GetTransform().SetLocalPosition(float4(-305, 230, -30));
		Youtube->GetTransform().SetLocalScale(float4(32, 32));
	}
	{
		Asobu = CreateComponent<GameEngineTextureRenderer>();
		Asobu->SetTexture("icon_desktop_asobu.png");
		Asobu->GetTransform().SetLocalPosition(float4(-305, 165, 0));
		Asobu->GetTransform().SetLocalScale(float4(32, 32));
	}
	{
		Neru = CreateComponent<GameEngineTextureRenderer>();
		Neru->SetTexture("icon_desktop_neru.png");
		Neru->GetTransform().SetLocalPosition(float4(-305, 100, 0));
		Neru->GetTransform().SetLocalScale(float4(32, 32));
	}
	{
		Okusuri = CreateComponent<GameEngineTextureRenderer>();
		Okusuri->SetTexture("icon_desktop_okusuri.png");
		Okusuri->GetTransform().SetLocalPosition(float4(-305, 35, 0));
		Okusuri->GetTransform().SetLocalScale(float4(32, 32));
	}
	{
		Internet = CreateComponent<GameEngineTextureRenderer>();
		Internet->GetTransform().SetLocalPosition(float4(-305, -30,0));
		Internet->GetTransform().SetLocalScale(float4(32, 32));
		Internet->CreateFrameAnimationCutTexture("Internet", FrameAnimation_DESC("icon_desktop_internet.png", 0, 0, 0.1f, false));
		Internet->ChangeFrameAnimation("Internet");
	}
	{
		Odekake = CreateComponent<GameEngineTextureRenderer>();
		Odekake->SetTexture("icon_desktop_odekake.png");
		Odekake->GetTransform().SetLocalPosition(float4(-305, -95, 0));
		Odekake->GetTransform().SetLocalScale(float4(32, 32));
	}
	{
		Tex = CreateComponent<GameEngineTextureRenderer>();
		Tex->SetTexture("icon_desktop_text.png");
		Tex->GetTransform().SetLocalPosition(float4(0, 135, 0));
		Tex->GetTransform().SetLocalScale(float4(32, 32));
	}
}

void WindowIcon::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Tutorial)
	{
		Youtube->GetColorData().MulColor.a = 1.0f;
		Internet->GetColorData().MulColor.a = 0.2f;
		Asobu->GetColorData().MulColor.a = 0.2f;
		Neru->GetColorData().MulColor.a = 0.2f;
		Okusuri->GetColorData().MulColor.a = 0.2f;
		Odekake->GetColorData().MulColor.a = 0.2f;
		Tex->GetColorData().MulColor.a = 0.2f;
	}

}

void WindowIcon::End()
{
}
