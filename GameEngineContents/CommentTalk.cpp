#include "PreCompile.h"
#include "CommentTalk.h"
#include "Stream.h"
#include "SuperChat.h"

CommentTalk::CommentTalk()
{
}

CommentTalk::~CommentTalk()
{
}

void CommentTalk::Start()
{
	GameEngineTextureRenderer* TextRend = CreateComponent<GameEngineTextureRenderer>();
	TextRend->SetTexture("Rect.png");
	TextRend->ScaleToTexture();
	TextRend->GetTransform().SetLocalPosition(float4(88, -185,-1));

	GameEngineTextureRenderer* TextRend2 = CreateComponent<GameEngineTextureRenderer>();
	TextRend2->SetTexture("Rect.png");
	TextRend2->ScaleToTexture();
	TextRend2->GetTransform().SetLocalPosition(float4(-102, -185,-1));

	GameEngineTextureRenderer* TextRend3 = CreateComponent<GameEngineTextureRenderer>();
	TextRend3->SetTexture("Speed.png");
	TextRend3->GetTransform().SetLocalScale(float4(183, 14));
	TextRend3->GetTransform().SetLocalPosition(float4(138, 158,-1));

	Font = CreateComponent<Myfont>();
	Font->SetLeftAndRightSort(LeftAndRightSort::CENTER);
	Font->TextDraw("방송 속도(보통)", "galmuri11", float4(618, 103), float4(94 / 255, 60 / 255, 127 / 255, 1), 12);
	Font->SetRenderingOrder(500);

	CommentTalkCheck = CreateComponent<GameEngineCollision>();
	CommentTalkCheck->GetTransform().SetLocalScale(float4(192, 218));
	CommentTalkCheck->GetTransform().SetLocalPosition(float4(138, 35));
	CommentTalkCheck->ChangeOrder(OBJECTORDER::UI);

	Trash = CreateComponent<CommentTextureRenderer>();
	Trash->SetTexture("icon_trash_can.png");
	Trash->GetTransform().SetLocalScale(float4(11, 13));
	Trash->GetTransform().SetLocalPosition(float4(228, 137, 500));
	GlobalContentsValue::FirstComment = "";
	GlobalContentsValue::SecondComment = "";

}

void CommentTalk::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Stream == false)
	{
		ChangeZPos(500);
		Font->TextDraw(" ", "galmuri11", float4(618, 103), float4(94 / 255, 60 / 255, 127 / 255, 1), 12);
		if (DeathTime)
		{
			Death();
		}
		return;
	}
	else
	{
		ChangeZPos(static_cast<float>(std::stoi(Stream::Inst_->StreamMainCol->GetNameConstRef())));
	}
	if (GlobalContentsValue::Stream)
	{
		if (i < ((GlobalContentsValue::ChangeTime) / 2.0)
			&& i < 16)
		{
			DeathTime = true;
			CreateText("Comment2_" + std::to_string(i) + ".png");
			i = i + 1;
		}

		if (MouseCheck(CommentTalkCheck)
			&& i > 1)
		{
			GlobalContentsValue::BgmSpeed = 0.9f;
			Font->TextDraw("댓글 선택 중", "galmuri11", float4(618, 103), float4(94 / 255, 60 / 255, 127 / 255, 1), 12);
			GameEngineTime::GetInst()->SetGlobalScale(0.5f);
			GlobalContentsValue::Check = true;
			CommentTalkCheckStart();
		}
		else
		{
			GlobalContentsValue::BgmSpeed = 1.0f;
			Font->TextDraw("방송 속도(보통)", "galmuri11", float4(618, 103), float4(94 / 255, 60 / 255, 127 / 255, 1), 12);
			GlobalContentsValue::Check = false;
			Trash->GetTransform().SetLocalPosition(float4(0, 0, 500));
		}
	}


}

void CommentTalk::End()
{
}

void CommentTalk::CommentTalkCheckStart()
{
	std::vector<std::pair<GameEngineCollision*, GameEngineCollision*>>::iterator StartIter = Col.begin();
	std::vector<std::pair<GameEngineCollision*, GameEngineCollision*>>::iterator EndIter = Col.end();

	std::vector<CommentTextureRenderer*>::iterator StartTextIter = Text.begin();
	std::vector<CommentTextureRenderer*>::iterator EndITexIter = Text.end();

	for (; StartTextIter != EndITexIter; ++StartIter, ++StartTextIter)
	{
		float4 Pos = (*StartIter).first->GetTransform().GetLocalPosition();
		float CommentTalkPos = Pos.y;

		if (MouseCheck((*StartIter).first))
		{
			float4 Pos = (*StartIter).second->GetTransform().GetLocalPosition();
			if ((*StartIter).first->GetNameConstRef() != "")
			{
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
					&& MouseCheck((*StartIter).first))
				{
					if (GlobalContentsValue::FirstComment == "")
					{
						if ((*StartIter).first->GetNameConstRef() == "1")
						{
							(*StartIter).first->SetName("End");
							Myfont* font = CreateComponent<Myfont>();
							font->TextDraw("완죤 내 스탈!", "NanumBarunGothicBold", float4(385, 447), float4(222 / 255, 215 / 255, 1, 1), 12);
							GlobalContentsValue::FirstComment = "완죤 내 스탈!";
						}
						else
						{
							(*StartIter).first->SetName("End");
							Myfont* font = CreateComponent<Myfont>();
							font->TextDraw("어째서 천사임?", "NanumBarunGothicBold", float4(385, 447), float4(222 / 255, 215 / 255, 1, 1), 12);
							GlobalContentsValue::FirstComment = "어째서 천사임?";
						}
					}
					else
					{
						if (GlobalContentsValue::SecondComment == "")
						{
							if ((*StartIter).first->GetNameConstRef() == "1")
							{
								(*StartIter).first->SetName("End");
								Myfont* font = CreateComponent<Myfont>();
								font->TextDraw("완죤 내 스탈!", "NanumBarunGothicBold", float4(575, 447), float4(222 / 255, 215 / 255, 1, 1), 12);
								GlobalContentsValue::SecondComment = "완죤 내 스탈!";
							}
							else
							{
								(*StartIter).first->SetName("End");
								Myfont* font = CreateComponent<Myfont>();
								font->TextDraw("어째서 천사임?", "NanumBarunGothicBold", float4(575, 447), float4(222 / 255, 215 / 255, 1, 1), 12);
								GlobalContentsValue::SecondComment = "어째서 천사임?";
							}
						}
					}
				}


				return;
			}
			else
				if (CommentTalkPos >= 136.9)
				{
					Trash->GetTransform().SetLocalPosition(float4(228, 137, -100));
					if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
						&& MouseCheck((*StartIter).second))
					{
						(*StartTextIter)->Clip.PosX = 540.0f;
					}
				}
				else
					if (CommentTalkPos >= 111.9)
					{
						Trash->GetTransform().SetLocalPosition(float4(228, 112, -100));
						if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
							&& MouseCheck((*StartIter).second))
						{
							(*StartTextIter)->Clip.PosX = 540.0f;
						}
					}
					else
						if (CommentTalkPos >= 86.9)
						{
							Trash->GetTransform().SetLocalPosition(float4(228, 87, -100));
							if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
								&& MouseCheck((*StartIter).second))
							{
								(*StartTextIter)->Clip.PosX = 540.0f;
							}
						}
						else
							if (CommentTalkPos >= 61.9)
							{
								Trash->GetTransform().SetLocalPosition(float4(228, 62, -100));
								if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
									&& MouseCheck((*StartIter).second))
								{
									(*StartTextIter)->Clip.PosX = 540.0f;
								}
							}
							else
								if (CommentTalkPos >= 36.9)
								{
									Trash->GetTransform().SetLocalPosition(float4(228, 37, -100));
									if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
										&& MouseCheck((*StartIter).second))
									{
										(*StartTextIter)->Clip.PosX = 540.0f;
									}
								}
								else
									if (CommentTalkPos >= 11.9)
									{
										Trash->GetTransform().SetLocalPosition(float4(228, 12, -100));
										if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
											&& MouseCheck((*StartIter).second))
										{
											(*StartTextIter)->Clip.PosX = 540.0f;
										}
									}
									else
										if (CommentTalkPos >= -13.1)
										{
											Trash->GetTransform().SetLocalPosition(float4(228, -13, -100));
											if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
												&& MouseCheck((*StartIter).second))
											{
												(*StartTextIter)->Clip.PosX = 540.0f;
											}
										}
										else
											if (CommentTalkPos >= -38.1)
											{
												Trash->GetTransform().SetLocalPosition(float4(228, -38, -100));
												if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
													&& MouseCheck((*StartIter).second))
												{
													(*StartTextIter)->Clip.PosX = 540.0f;
												}
											}
											else
												if (CommentTalkPos >= -63.1)
												{
													Trash->GetTransform().SetLocalPosition(float4(228, -63, -100));
													if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
														&& MouseCheck((*StartIter).second))
													{
														(*StartTextIter)->Clip.PosX = 540.0f;
													}
												}
												else
													if (CommentTalkPos >= -88.1)
													{
														Trash->GetTransform().SetLocalPosition(float4(228, -88, -100));
														if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
															&& MouseCheck((*StartIter).second))
														{
															(*StartTextIter)->Clip.PosX = 540.0f;
														}
													}
		}

	}
}



void CommentTalk::CreateText(const std::string& _Text)
 {
	CommentTextureRenderer* TextRend = CreateComponent<CommentTextureRenderer>();
	TextRend->SetTexture(_Text);
	TextRend->ScaleToTexture();
	TextRend->GetTransform().SetLocalPosition(float4(138.0f, 137.0f - static_cast<float>(TextNum), -2.0f));
	TextRend->Clip.PosY = 126.0f;

	float4 Scale = TextRend->GetTransform().GetLocalScale();


	GameEngineCollision* TrashCollision = CreateComponent<GameEngineCollision>();
	TrashCollision->GetTransform().SetLocalScale(float4(11, 13, 0));
	TrashCollision->GetTransform().SetLocalPosition(float4(228.0f, 137.0f - static_cast<float>(TextNum)));

	GameEngineCollision* Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalScale(float4(Scale.x, Scale.y, 0));
	Collision->GetTransform().SetLocalPosition(float4(138.0f, 137.0f - static_cast<float>(TextNum)));
	if (_Text == "Comment2_3.png"
		|| _Text == "Comment2_5.png"
		|| _Text == "Comment2_13.png"
		|| _Text == "Comment2_14.png")
	{
		GetLevel()->CreateActor<SuperChat>();
		Collision->ChangeOrder(OBJECTORDER::SuperChat);
		Collision->SetName(std::to_string(ColName));

		TrashCollision->ChangeOrder(OBJECTORDER::SuperChat);
		TrashCollision->SetName(std::to_string(ColName));

		ColName = ColName + 1;
	}
	else
	{
		Collision->ChangeOrder(OBJECTORDER::UI);
		TrashCollision->ChangeOrder(OBJECTORDER::UI);
	}



	TextNum = TextNum + 25;
	Text.push_back(TextRend);
	Col.push_back(std::make_pair(Collision, TrashCollision));

	MoveStart++;
	if (MoveStart >= 10)
	{
		Move = Move + 25;
		TextMove(25.0f, static_cast<float>(Move));
	}

}

void CommentTalk::TextMove(float Y_, float last)
{
	std::vector<CommentTextureRenderer*>::iterator StartIter = Text.begin();
	std::vector<CommentTextureRenderer*>::iterator EndIter = Text.end();
	std::string A = (*StartIter)->GetNameCopy();

	std::vector<std::pair<GameEngineCollision*, GameEngineCollision*>>::iterator StartColIter = Col.begin();
	std::vector<std::pair<GameEngineCollision*, GameEngineCollision*>>::iterator EndColIter = Col.end();

	for (; StartIter != EndIter - 1; ++StartIter, ++StartColIter)
	{
		(*StartIter)->GetTransform().SetLocalMove(float4(0, Y_, 0));
		(*StartColIter).first->GetTransform().SetLocalMove(float4(0, Y_, 0));
		(*StartColIter).second->GetTransform().SetLocalMove(float4(0, Y_, 0));
	}

	(StartIter) = EndIter - 1;
	(*StartIter)->GetTransform().SetLocalMove(float4(0, last, 0));

	(StartColIter) = EndColIter - 1;
	(*StartColIter).first->GetTransform().SetLocalMove(float4(0, last, 0));
	(*StartColIter).second->GetTransform().SetLocalMove(float4(0, last, 0));
}
