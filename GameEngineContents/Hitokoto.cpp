#include "PreCompile.h"
#include "TaskManager.h"

void TaskManager::StatusCheck()
{
	//301±îÁö °¡¾ßµÊ
	if (CurFollower != GlobalContentsValue::Followers)
	{
		FollowerDiffrenceNum = CurFollower - GlobalContentsValue::Followers;
		CurFollower = GlobalContentsValue::Followers;
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->GetTransform().SetLocalPosition(float4(250,220, -1));
		Renderer->SetTexture("hitokoto.png");
		Renderer->Clip.PosX = 831.5f;
		Renderer->ScaleToTexture();

		DiffrenceCheck(FollowerDiffrenceNum, 220, true);
		HitokotoCheck = true;
		Hitokoto.push_back(Renderer);
		Inst_->TaskManagerMainCol->SetName("-100F");
	}
	if (CurStress != GlobalContentsValue::Stress)
	{
		StressDiffrenceNum = CurStress - GlobalContentsValue::Stress;
		CurStress = GlobalContentsValue::Stress;
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->GetTransform().SetLocalPosition(float4(250, 183, -1));
		Renderer->SetTexture("hitokoto.png");
		Renderer->Clip.PosX = 831.5f;
		Renderer->ScaleToTexture();


		DiffrenceCheck(StressDiffrenceNum, 183, false);
		HitokotoCheck = true;
		Hitokoto.push_back(Renderer);
		Inst_->TaskManagerMainCol->SetName("-100F");
	}
	if (CurAffection != GlobalContentsValue::Affection)
	{
		AffectionDiffrenceNum = CurAffection - GlobalContentsValue::Affection;
		CurAffection = GlobalContentsValue::Affection;
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->GetTransform().SetLocalPosition(float4(250, 146.5, -1));
		Renderer->SetTexture("hitokoto.png");
		Renderer->Clip.PosX = 831.5f;
		Renderer->ScaleToTexture();


		DiffrenceCheck(AffectionDiffrenceNum, 146.5, false);
		HitokotoCheck = true;
		Hitokoto.push_back(Renderer);
		Inst_->TaskManagerMainCol->SetName("-100F");
	}
	if (CurMental != GlobalContentsValue::Mental)
	{
		MentalDiffrenceNum = CurMental - GlobalContentsValue::Mental;
		CurMental = GlobalContentsValue::Mental;
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->GetTransform().SetLocalPosition(float4(250, 110.5, -1));
		Renderer->SetTexture("hitokoto.png");
		Renderer->Clip.PosX = 831.5f;
		Renderer->ScaleToTexture();


		DiffrenceCheck(MentalDiffrenceNum, 110.5, false);
		HitokotoCheck = true;
		Hitokoto.push_back(Renderer);
		Inst_->TaskManagerMainCol->SetName("-100F");
	}

	if (GetNameConstRef() == "-100F")
	{
		Mouse::Inst_->ChangeNameAll();
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

		StartIter = Diffrence.begin();
		EndIter = Diffrence.end();
		for (; StartIter != EndIter; ++StartIter)
		{
			(*StartIter)->GetTransform().SetLocalMove(float4(500 * GameEngineTime::GetDeltaTime(), 0, 0));
		}

		StartIter = FollowerDiffrence.begin();
		EndIter = FollowerDiffrence.end();
		for (; StartIter != EndIter; ++StartIter)
		{
			(*StartIter)->GetTransform().SetLocalMove(float4(500 * GameEngineTime::GetDeltaTime(), 0, 0));
		}


		if (End > 301.0f)
		{
			End = 301.0f;
			StartIter = Hitokoto.begin();
			EndIter = Hitokoto.end();
			for (; StartIter != EndIter ; ++StartIter)
			{
				float YPos = (*StartIter)->GetTransform().GetLocalPosition().y;
				(*StartIter)->GetTransform().SetLocalPosition(float4(End, YPos, -1));
			}

			NumberCheck = true;
			HitokotoCheck = false;
			Check = true;
		}
	}
}

void TaskManager::DiffrenceCheck(int Diffrence_, float YPos, bool follower)
{
	if (Diffrence_ > 0)
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->GetTransform().SetLocalPosition(float4(200 , YPos, -1));
		Renderer->SetTexture("-.png");
		Renderer->GetTransform().SetLocalScale(float4(14, 14));
		if (follower)
		{
			FollowerDiffrence.push_back(Renderer);
		}
		else
		{
			Diffrence.push_back(Renderer);
		}
	}
	else
	{
		CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
		Renderer->GetTransform().SetLocalPosition(float4(200, YPos, -1));
		Renderer->SetTexture("+.png");
		Renderer->GetTransform().SetLocalScale(float4(14, 14));

		if (follower)
		{
			FollowerDiffrence.push_back(Renderer);
		}
		else
		{
			Diffrence.push_back(Renderer);
		}
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
		Renderer->GetTransform().SetLocalPosition(float4(210 + A * 10, YPos, -1));
		std::string b  = std::to_string(Number.at(DiffrenceCount - A - 1) ) + ".png";
		Renderer->SetTexture(std::to_string(Number.at(DiffrenceCount - A - 1)) + ".png");
		Renderer->GetTransform().SetLocalScale(float4(14, 14));

		if (follower)
		{
			FollowerDiffrence.push_back(Renderer);
		}
		else
		{
			Diffrence.push_back(Renderer);
		}
	}
	
	DiffrenceCount = 0;
	Number.clear();
}


void TaskManager::StatusName()
{
	if (Check)
	{
		CheckTime = CheckTime + GameEngineTime::GetDeltaTime();
		if (CheckTime > 0.5f)
		{
			std::vector<CommentTextureRenderer*>::iterator StartIter = Diffrence.begin();
			std::vector<CommentTextureRenderer*>::iterator EndIter = Diffrence.end();
			for (; StartIter != EndIter; ++StartIter)
			{
				(*StartIter)->Off();
			}
			Diffrence.clear();
			Diffrence.shrink_to_fit();
			if (StressDiffrenceNum != 0)
			{
				CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
				Renderer->GetTransform().SetLocalPosition(float4(287, 183, -1));
				Renderer->SetTexture("Stress1.png");
				Renderer->ScaleToTexture();
				Hitokoto.push_back(Renderer);
				StressDiffrenceNum = 0;
			}
			if (AffectionDiffrenceNum != 0)
			{
				CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
				Renderer->GetTransform().SetLocalPosition(float4(287, 146.5, -1));
				Renderer->SetTexture("Affection1.png");
				Renderer->ScaleToTexture();
				Hitokoto.push_back(Renderer);
				AffectionDiffrenceNum = 0;
			}
			if (MentalDiffrenceNum != 0)
			{
				CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
				Renderer->GetTransform().SetLocalPosition(float4(287, 110.5, -1));
				Renderer->SetTexture("Mental1.png");
				Renderer->ScaleToTexture();
				Hitokoto.push_back(Renderer);
				MentalDiffrenceNum = 0;
			}
		}
		if (CheckTime > 3.5f)
		{
			std::vector<CommentTextureRenderer*>::iterator StartIter = Hitokoto.begin();
			std::vector<CommentTextureRenderer*>::iterator EndIter = Hitokoto.end();
			for (; StartIter != EndIter; ++StartIter)
			{
				(*StartIter)->Off();
			}

			StartIter = FollowerDiffrence.begin();
			EndIter = FollowerDiffrence.end();
			for (; StartIter != EndIter; ++StartIter)
			{
				(*StartIter)->Off();
			}
			Hitokoto.clear();
			Hitokoto.shrink_to_fit();
			FollowerDiffrence.clear();
			FollowerDiffrence.shrink_to_fit();

			CheckTime = 0.0f;
			Check = false;
		}

	}
}

void TaskManager::NumberSetting()
{
	if (NumberCheck == true)
	{

		std::vector<CommentTextureRenderer*>::iterator StartIter = CurNumberRenderer.begin();
		std::vector<CommentTextureRenderer*>::iterator EndIter = CurNumberRenderer.end();
		for (; StartIter != EndIter; ++StartIter)
		{
			(*StartIter)->Off();
		}
		CurNumberRenderer.clear();
		CurNumberRenderer.shrink_to_fit();

		int CurStatus = GlobalContentsValue::Affection;
		while ((CurStatus) != 0)
		{
			int CurNum = CurStatus % 10;
			CurNumber.push_back(CurNum);
			CurStatus = CurStatus / 10;
			CunrNumCount = CunrNumCount + 1;
		}

		for (int A = 0; A != CunrNumCount; A++)
		{
			CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
			Renderer->GetTransform().SetLocalPosition(float4(215 + A * 8, 141.5, 0));
			std::string b = std::to_string(CurNumber.at(CunrNumCount - A - 1)) + ".png";
			Renderer->SetTexture(std::to_string(CurNumber.at(CunrNumCount - A - 1)) + ".png");
			Renderer->GetTransform().SetLocalScale(float4(12,12));

			CurNumberRenderer.push_back(Renderer);
		}
		CunrNumCount = 0;
		CurNumber.clear();
		
		CurStatus = GlobalContentsValue::Followers;
		while ((CurStatus) != 0)
		{
			int CurNum = CurStatus % 10;
			CurNumber.push_back(CurNum);
			CurStatus = CurStatus / 10;
			CunrNumCount = CunrNumCount + 1;
		}

		for (int A = 0; A != CunrNumCount; A++)
		{
			CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
			Renderer->GetTransform().SetLocalPosition(float4(205+ A * 14, 208, 0));
			std::string b = std::to_string(CurNumber.at(CunrNumCount - A - 1)) + ".png";
			Renderer->SetTexture(std::to_string(CurNumber.at(CunrNumCount - A - 1)) + ".png");
			Renderer->GetTransform().SetLocalScale(float4(20, 20));

			CurNumberRenderer.push_back(Renderer);
		}
		CunrNumCount = 0;
		CurNumber.clear();

		CurStatus = GlobalContentsValue::Stress;
		while ((CurStatus) != 0)
		{
			int CurNum = CurStatus % 10;
			CurNumber.push_back(CurNum);
			CurStatus = CurStatus / 10;
			CunrNumCount = CunrNumCount + 1;
		}

		for (int A = 0; A != CunrNumCount; A++)
		{
			CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
			Renderer->GetTransform().SetLocalPosition(float4(215 + A * 8, 178, 0));
			std::string b = std::to_string(CurNumber.at(CunrNumCount - A - 1)) + ".png";
			Renderer->SetTexture(std::to_string(CurNumber.at(CunrNumCount - A - 1)) + ".png");
			Renderer->GetTransform().SetLocalScale(float4(12, 12));

			CurNumberRenderer.push_back(Renderer);
		}
		CunrNumCount = 0;
		CurNumber.clear();

		CurStatus = GlobalContentsValue::Mental;
		while ((CurStatus) != 0)
		{
			int CurNum = CurStatus % 10;
			CurNumber.push_back(CurNum);
			CurStatus = CurStatus / 10;
			CunrNumCount = CunrNumCount + 1;
		}

		for (int A = 0; A != CunrNumCount; A++)
		{
			CommentTextureRenderer* Renderer = CreateComponent<CommentTextureRenderer>();
			Renderer->GetTransform().SetLocalPosition(float4(215 + A * 8, 105.5, 0));
			std::string b = std::to_string(CurNumber.at(CunrNumCount - A - 1)) + ".png";
			Renderer->SetTexture(std::to_string(CurNumber.at(CunrNumCount - A - 1)) + ".png");
			Renderer->GetTransform().SetLocalScale(float4(12, 12));

			CurNumberRenderer.push_back(Renderer);
		}
		CunrNumCount = 0;
		CurNumber.clear();
		

		
		NumberCheck = false;
	}
}