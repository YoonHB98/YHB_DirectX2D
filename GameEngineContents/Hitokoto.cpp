#include "PreCompile.h"
#include "TaskManager.h"

void TaskManager::StatusCheck()
{
	//301±îÁö °¡¾ßµÊ
	if (CurFollower != GlobalContentsValue::Followers )
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
		Mouse::Inst_->ChangeNameAll();
		Inst_->TaskManagerMainCol->SetName("-100");
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
		Mouse::Inst_->ChangeNameAll();
		Inst_->TaskManagerMainCol->SetName("-100");
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
		Mouse::Inst_->ChangeNameAll();
		Inst_->TaskManagerMainCol->SetName("-100");
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
		Mouse::Inst_->ChangeNameAll();
		Inst_->TaskManagerMainCol->SetName("-100");
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
			if (GlobalContentsValue::Contents != "Tutorial")
			{
				if (GlobalContentsValue::Stress > 80)
				{
					GameEngineSound::SoundPlayOneShot("stress_up_lv3.wav");
				}else
					if (GlobalContentsValue::Stress >60 )
					{
						GameEngineSound::SoundPlayOneShot("stress_up_lv2.wav");
					}else
							if (GlobalContentsValue::Stress > 40)
							{
								GameEngineSound::SoundPlayOneShot("stress_up_lv1.wav");
							}
							else
							{
								GameEngineSound::SoundPlayOneShot("status_up.wav");
							}
			}

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
		Renderer->GetTransform().SetLocalPosition(float4(210.0f + static_cast<float>(A) * 10.0f, YPos, -1));
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
				if (GlobalContentsValue::Stress > 80)
				{
					Renderer->SetTexture("Stress5.png");
				}
				else if (GlobalContentsValue::Stress > 60)
				{
					Renderer->SetTexture("Stress4.png");
				}
				else if (GlobalContentsValue::Stress > 40)
				{
					Renderer->SetTexture("Stress3.png");
				}
				else if (GlobalContentsValue::Stress > 20)
				{
					Renderer->SetTexture("Stress2.png");
				}
				else
				{
					Renderer->SetTexture("Stress1.png");
				}
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
				if (GlobalContentsValue::Mental > 80)
				{
					Renderer->SetTexture("Mental5.png");
				}
				else if (GlobalContentsValue::Mental > 60)
				{
					Renderer->SetTexture("Mental4.png");
				}
				else if (GlobalContentsValue::Mental > 40)
				{
					Renderer->SetTexture("Mental3.png");
				}
				else if (GlobalContentsValue::Mental > 20)
				{
					Renderer->SetTexture("Mental2.png");
				}
				else
				{
					Renderer->SetTexture("Mental1.png");
				}
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
			Renderer->GetTransform().SetLocalPosition(float4(215.0f+ static_cast<float>(A) * 8.0f, 141.5f, 0.0f));
			std::string b = std::to_string(CurNumber.at(CunrNumCount - A - 1)) + ".png";
			Renderer->SetTexture(std::to_string(CurNumber.at(CunrNumCount - A - 1)) + ".png");
			Renderer->GetTransform().SetLocalScale(float4(12,12));
			if (CurStatus > 80)
			{
				Renderer->Color.PosX = 210.0f / 255.0f;
				Renderer->Color.PosY = 90.0f / 255.0f;
				Renderer->Color.SizeX = 88.0f / 255.0f;
			}


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
			Renderer->GetTransform().SetLocalPosition(float4(205.0f+ static_cast<float>(A) * 14.0f, 208.0f, 0.0f));
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
			Renderer->GetTransform().SetLocalPosition(float4(215.0f + static_cast<float>(A) * 8.0f, 178.0f, 0.0f));
			std::string b = std::to_string(CurNumber.at(CunrNumCount - A - 1)) + ".png";
			Renderer->SetTexture(std::to_string(CurNumber.at(CunrNumCount - A - 1)) + ".png");
			Renderer->GetTransform().SetLocalScale(float4(12, 12));
			if (CurStatus > 80)
			{
				Renderer->Color.PosX = 210.0f / 255.0f;
				Renderer->Color.PosY = 90.0f / 255.0f;
				Renderer->Color.SizeX = 88.0f / 255.0f;
			}

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
			Renderer->GetTransform().SetLocalPosition(float4(215.0f + static_cast<float>(A) * 8.0f, 105.5f, 0.0f));
			std::string b = std::to_string(CurNumber.at(CunrNumCount - A - 1)) + ".png";
			Renderer->SetTexture(std::to_string(CurNumber.at(CunrNumCount - A - 1)) + ".png");
			Renderer->GetTransform().SetLocalScale(float4(12, 12));
			if (CurStatus > 80)
			{
				Renderer->Color.PosX = 210.0f / 255.0f;
				Renderer->Color.PosY = 90.0f / 255.0f;
				Renderer->Color.SizeX = 88.0f / 255.0f;
			}

			CurNumberRenderer.push_back(Renderer);
		}
		CunrNumCount = 0;
		CurNumber.clear();
		

		
		NumberCheck = false;
	}
}