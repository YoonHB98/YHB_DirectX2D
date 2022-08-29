#include "PreCompile.h"
#include "DayChangeWindow.h"

DayChangeWindow::DayChangeWindow() 
{
}

DayChangeWindow::~DayChangeWindow() 
{
}

void DayChangeWindow::Start()
{
	Renderer = CreateComponent<GameEngineTextureRenderer>();
	Renderer->SetTexture("DayChange.png");
	Renderer->SetPivot(PIVOTMODE::LEFT);
	Renderer->GetTransform().SetLocalPosition(float4(-480, 0, -150));
	Renderer->ScaleToTexture();

	Tri = CreateComponent<GameEngineTextureRenderer>();
	Tri->SetTexture("Triangle.png");
	Tri->GetTransform().SetLocalPosition(float4(0,-160,-150));
	Tri->ScaleToTexture();

	Font = CreateComponent<GameEngineTextureRenderer>();
	Font->SetTexture("Day0.png");
	Font->GetTransform().SetLocalPosition(float4(0, 0, -150));
	Font->ScaleToTexture();


}

void DayChangeWindow::Update(float _DeltaTime)
{
	if (GlobalContentsValue::DayChangeWindow)
	{
		Time = Time + _DeltaTime;
		if (First)
		{
			if (Time > 0.8f)
			{
				First = false;	
				Time = 0.0f;
				DayChangeTime = 0.0f;
				Tri->GetColorData().MulColor.a = 1.0f;
				Renderer->GetColorData().MulColor.a = 1.0f;
				Count = 0;
			}
			return;
		}
		DayChangeTime = DayChangeTime + _DeltaTime;
		if (DayChangeTime < 0.08f)
		{
			Tri->GetTransform().SetLocalMove(float4(0, -250 * _DeltaTime, 0));
			return;
		}
		else
		{

		}
		if (Count <= 16)
		{
			if (Time > 0.004)
			{
				Count++;
				Time = Time - 0.004;
				Renderer->GetTransform().SetLocalMove(float4(-6.42, 0, 0));
			}
		}
		if (Time > 2.0f
			&& Tri->GetColorData().MulColor.a > 0.0f)
		{
			if (Time < 2.08f)
			{
				Tri->GetTransform().SetLocalMove(float4(0, 250 * _DeltaTime, 0));
			}
			Font->SetTexture("Day"+ std::to_string(GlobalContentsValue::Day) + ".png");
			Tri->GetColorData().MulColor.a = Tri->GetColorData().MulColor.a - 1.0f * _DeltaTime;
			Renderer->GetColorData().MulColor.a = Renderer->GetColorData().MulColor.a - 1.0f * _DeltaTime;
			Font->GetColorData().MulColor.a = Font->GetColorData().MulColor.a - 1.0f * _DeltaTime;
		}
		if (Tri->GetColorData().MulColor.a < 0.0f)
		{
			Tri->GetColorData().MulColor.a = 0.0f;
			Renderer->GetColorData().MulColor.a = 0.0f;
			Font->GetColorData().MulColor.a = 0.0f;
			GlobalContentsValue::DayChangeWindow = false;
		}
	}
	else
	{
		First = true;
		return;
	}

}

void DayChangeWindow::End()
{
}