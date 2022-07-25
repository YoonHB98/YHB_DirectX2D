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
		Asobu->GetTransform().SetLocalPosition(float4(-305, 165, -30));
		Asobu->GetTransform().SetLocalScale(float4(32, 32));
	}
	{
		Neru = CreateComponent<GameEngineTextureRenderer>();
		Neru->SetTexture("icon_desktop_neru.png");
		Neru->GetTransform().SetLocalPosition(float4(-305, 100, -30));
		Neru->GetTransform().SetLocalScale(float4(32, 32));
	}
	{
		Okusuri = CreateComponent<GameEngineTextureRenderer>();
		Okusuri->SetTexture("icon_desktop_okusuri.png");
		Okusuri->GetTransform().SetLocalPosition(float4(-305, 35, -30));
		Okusuri->GetTransform().SetLocalScale(float4(32, 32));
	}
	{
		Internet = CreateComponent<GameEngineTextureRenderer>();
		Internet->SetTexture("icon_desktop_internet.png");
		Internet->GetTransform().SetLocalPosition(float4(-305, -30, -30));
		Internet->GetTransform().SetLocalScale(float4(32, 32));
	}
	{
		Odekake = CreateComponent<GameEngineTextureRenderer>();
		Odekake->SetTexture("icon_desktop_odekake.png");
		Odekake->GetTransform().SetLocalPosition(float4(-305, -95, -30));
		Odekake->GetTransform().SetLocalScale(float4(32, 32));
	}
	{
		Tex = CreateComponent<GameEngineTextureRenderer>();
		Tex->SetTexture("icon_desktop_text.png");
		Tex->GetTransform().SetLocalPosition(float4(0, 135, -30));
		Tex->GetTransform().SetLocalScale(float4(32, 32));
	}
}

void WindowIcon::Update(float _DeltaTime)
{
}

void WindowIcon::End()
{
}
