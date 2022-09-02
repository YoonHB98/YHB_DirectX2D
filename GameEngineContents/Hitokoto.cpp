#include "PreCompile.h"
#include "TaskManager.h"

void TaskManager::StatusCheck()
{
	//301±îÁö °¡¾ßµÊ
	if (CurFollower != GlobalContentsValue::Followers)
	{
		int Diffrence = CurFollower - GlobalContentsValue::Followers;
		CurFollower = GlobalContentsValue::Followers;
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->GetTransform().SetLocalPosition(float4(250,220,0));
		Renderer->SetTexture("hitokoto.png");
		Renderer->Clip.PosX = 831.5f;
		Renderer->ScaleToTexture();

		DiffrenceCheck(Diffrence, 220);
		HitokotoCheck = true;
		Hitokoto.push_back(Renderer);
	}
	if (CurStress != GlobalContentsValue::Stress)
	{
		int Diffrence = CurStress - GlobalContentsValue::Stress;
		CurStress = GlobalContentsValue::Stress;
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->GetTransform().SetLocalPosition(float4(250, 183, 0));
		Renderer->SetTexture("hitokoto.png");
		Renderer->Clip.PosX = 831.5f;
		Renderer->ScaleToTexture();


		DiffrenceCheck(Diffrence, 183);
		HitokotoCheck = true;
		Hitokoto.push_back(Renderer);
	}
	if (CurAffection != GlobalContentsValue::Affection)
	{
		int Diffrence = CurAffection - GlobalContentsValue::Affection;
		CurAffection = GlobalContentsValue::Affection;
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->GetTransform().SetLocalPosition(float4(250, 146.5, 0));
		Renderer->SetTexture("hitokoto.png");
		Renderer->Clip.PosX = 831.5f;
		Renderer->ScaleToTexture();


		DiffrenceCheck(Diffrence, 146.5);
		HitokotoCheck = true;
		Hitokoto.push_back(Renderer);
	}
	if (CurMental != GlobalContentsValue::Mental)
	{
		int Diffrence = CurMental - GlobalContentsValue::Mental;
		CurMental = GlobalContentsValue::Mental;
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->GetTransform().SetLocalPosition(float4(250, 110.5, 0));
		Renderer->SetTexture("hitokoto.png");
		Renderer->Clip.PosX = 831.5f;
		Renderer->ScaleToTexture();


		DiffrenceCheck(Diffrence, 110.5);
		HitokotoCheck = true;
		Hitokoto.push_back(Renderer);
	}

	if (HitokotoCheck == true)
	{
		std::vector<CommentTextureRenderer*>::iterator StartIter = Hitokoto.begin();
		std::vector<CommentTextureRenderer*>::iterator EndIter = Hitokoto.end();

		for (; StartIter != EndIter; ++StartIter)
		{
			(*StartIter)->GetTransform().SetLocalMove(float4(500*GameEngineTime::GetDeltaTime(), 0, 0));
		}
		float End = (*(StartIter - 1))->GetTransform().GetLocalPosition().x;
		if (End > 301.0f)
		{
			End = 301.0f;
			HitokotoCheck = false;
		}
	}
}

void TaskManager::DiffrenceCheck(int Diffrence_, float YPos)
{
	if (Diffrence_ > 0)
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->GetTransform().SetLocalPosition(float4(200 , YPos, 0));
		Renderer->SetTexture("-.png");
		Renderer->ScaleToTexture();

		Hitokoto.push_back(Renderer);
	}
	else
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->GetTransform().SetLocalPosition(float4(200, YPos, 0));
		Renderer->SetTexture("+.png");
		Renderer->ScaleToTexture();

		Hitokoto.push_back(Renderer);
	}
	Diffrence_ = abs(Diffrence_);
	while (abs(Diffrence_ ) != 0)
	{
		int CurNum = Diffrence_ % 10;
		Number.push_back(CurNum);
		Diffrence_ = Diffrence_ / 10;
		DiffrenceCount = DiffrenceCount + 1;
	}
	for (int A = 0; A != DiffrenceCount; A++)
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->GetTransform().SetLocalPosition(float4(210 + A * 10, YPos, 0));
		std::string b  = std::to_string(Number.at(DiffrenceCount - A - 1) ) + ".png";
		Renderer->SetTexture(std::to_string(Number.at(DiffrenceCount - A - 1)) + ".png");
		Renderer->ScaleToTexture();

		Hitokoto.push_back(Renderer);
	}
	
	DiffrenceCount = 0;
	Number.clear();
}
