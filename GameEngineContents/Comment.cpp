#include "PreCompile.h"
#include "Comment.h"
#include "Stream.h"

Comment::Comment() 
{
}

Comment::~Comment() 
{
}

void Comment::Start()
{
	GameEngineTextureRenderer* TextRend = CreateComponent<GameEngineTextureRenderer>();
	TextRend->SetTexture("Rect.png");
	TextRend->ScaleToTexture();
	TextRend->GetTransform().SetLocalPosition(float4(88, -185));

	GameEngineTextureRenderer* TextRend2 = CreateComponent<GameEngineTextureRenderer>();
	TextRend2->SetTexture("Rect.png");
	TextRend2->ScaleToTexture();
	TextRend2->GetTransform().SetLocalPosition(float4(-102, -185));

	GameEngineTextureRenderer* TextRend3 = CreateComponent<GameEngineTextureRenderer>();
	TextRend3->SetTexture("Speed.png");
	TextRend3->GetTransform().SetLocalScale(float4(183,14));
	TextRend3->GetTransform().SetLocalPosition(float4(138, 158));

	Font = CreateComponent<Myfont>();
	Font->SetLeftAndRightSort(LeftAndRightSort::CENTER);
	Font->TextDraw("방송 속도(보통)", "galmuri11", float4(618, 103), float4(94 / 255,60 / 255, 127/255, 1), 12);
	Font->SetRenderingOrder(500);

	CommentCheck = CreateComponent<GameEngineCollision>();
	CommentCheck->GetTransform().SetLocalScale(float4(192,218));
	CommentCheck->GetTransform().SetLocalPosition(float4(138, 35 ));
	CommentCheck->ChangeOrder(OBJECTORDER::UI);

	Trash = CreateComponent<CommentTextureRenderer>();
	Trash->SetTexture("icon_trash_can.png");
	Trash->GetTransform().SetLocalScale(float4(11, 13));
	Trash->GetTransform().SetLocalPosition(float4(228, 137, 500 ));

}

void Comment::Update(float _DeltaTime)
{
	if (GlobalContentsValue::Stream == false)
	{
			ChangeZPos(500);
			Font->TextDraw(" ", "galmuri11", float4(618, 103), float4(94 / 255, 60 / 255, 127 / 255, 1), 12);
			return;
	}
	else
	{
			ChangeZPos(static_cast<float>(std::stoi(Stream::Inst_->StreamMainCol->GetNameConstRef())));
	}
	if (GlobalContentsValue::Stream)
	{
		if (i < ((GlobalContentsValue::ChangeTime - 9) / 3.115)
			&& i < 27)
		{
			CreateText("Comment1_" + std::to_string(i) + ".png");
			i = i + 1;
		}

		if (MouseCheck(CommentCheck)
			&& i > 1)
		{
			GlobalContentsValue::BgmSpeed = 0.9f;
			Font->TextDraw("댓글 선택 중", "galmuri11", float4(618, 103), float4(94 / 255, 60 / 255, 127 / 255, 1), 12);
			GameEngineTime::GetInst()->SetGlobalScale(0.5f);
			GlobalContentsValue::Check = true;
			CommentCheckStart();
		}
		else if (i > 1)
		{
			GlobalContentsValue::BgmSpeed = 1.0f;
			Font->TextDraw("방송 속도(보통)", "galmuri11", float4(618, 103), float4(94 / 255, 60 / 255, 127 / 255, 1), 12);
			GlobalContentsValue::Check = false;
			Trash->GetTransform().SetLocalPosition(float4(0, 0, 500));
		}
	}
	
	
}

void Comment::End()
{
}

void Comment::CommentCheckStart()
{
	std::vector<std::pair<GameEngineCollision*, GameEngineCollision*>>::iterator StartIter = Col.begin();
	std::vector<std::pair<GameEngineCollision*, GameEngineCollision*>>::iterator EndIter = Col.end();

	std::vector<CommentTextureRenderer*>::iterator StartTextIter = Text.begin();
	std::vector<CommentTextureRenderer*>::iterator EndITexIter = Text.end();

	for (; StartTextIter != EndITexIter; ++StartIter, ++StartTextIter)
	{
		float4 Pos = (*StartIter).first->GetTransform().GetLocalPosition();
		float CommentPos = Pos.y;

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
							font->TextDraw("와 줘서 고마워", "NanumBarunGothicBold", float4(385, 447), float4(222 / 255, 215 / 255, 1, 1), 12);
							GlobalContentsValue::FirstComment = "와 줘서 고마워";
						}
						else
						{
							(*StartIter).first->SetName("End");
							Myfont* font = CreateComponent<Myfont>();
							font->TextDraw("꺼져", "NanumBarunGothicBold", float4(385, 447), float4(222 / 255, 215 / 255, 1, 1), 12);
							GlobalContentsValue::FirstComment = "꺼져";
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
								font->TextDraw("와 줘서 고마워", "NanumBarunGothicBold", float4(575, 447), float4(222 / 255, 215 / 255, 1, 1), 12);
								GlobalContentsValue::SecondComment = "와 줘서 고마워";
							}
							else
							{
								(*StartIter).first->SetName("End");
								Myfont* font = CreateComponent<Myfont>();
								font->TextDraw("꺼져", "NanumBarunGothicBold", float4(575, 447), float4(222 / 255, 215 / 255, 1, 1), 12);
								GlobalContentsValue::SecondComment = "꺼져";
							}
						}
					}
				}

			
				return;
			}
			else
			if (CommentPos >= 136.9)
			{
				Trash->GetTransform().SetLocalPosition(float4(228, 137, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
					&& MouseCheck((*StartIter).second))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}else
				if (CommentPos >= 111.9)
				{
					Trash->GetTransform().SetLocalPosition(float4(228, 112, 0));
					if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
						&& MouseCheck((*StartIter).second))
					{
						(*StartTextIter)->Clip.PosX = 540.0f;
					}
				}
				else
			if (CommentPos >= 86.9)
			{
				Trash->GetTransform().SetLocalPosition(float4(228, 87, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
					&& MouseCheck((*StartIter).second))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}else
			if (CommentPos >= 61.9)
			{
				Trash->GetTransform().SetLocalPosition(float4(228, 62, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
					&& MouseCheck((*StartIter).second))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}else
			if (CommentPos >= 36.9)
			{
				Trash->GetTransform().SetLocalPosition(float4(228, 37, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
					&& MouseCheck((*StartIter).second))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}else
			if (CommentPos >= 11.9)
			{
				Trash->GetTransform().SetLocalPosition(float4(228, 12, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
					&& MouseCheck((*StartIter).second))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}else
			if (CommentPos >= -13.1)
			{
				Trash->GetTransform().SetLocalPosition(float4(228, -13, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
					&& MouseCheck((*StartIter).second))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}else
			if (CommentPos >= -38.1)
			{
				Trash->GetTransform().SetLocalPosition(float4(228, -38, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
					&& MouseCheck((*StartIter).second))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}else
			if (CommentPos >= -63.1)
			{
				Trash->GetTransform().SetLocalPosition(float4(228,-63, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
					&& MouseCheck((*StartIter).second))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}else
			if (CommentPos >= -88.1)
			{
				Trash->GetTransform().SetLocalPosition(float4(228,-88, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick")
					&& MouseCheck((*StartIter).second))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}
		}
	
	}
}



void Comment::CreateText(const std::string& _Text)
{
	CommentTextureRenderer* TextRend = CreateComponent<CommentTextureRenderer>();
	TextRend->SetTexture(_Text);
	TextRend->ScaleToTexture();
	TextRend->GetTransform().SetLocalPosition(float4(138.0f, 137.0f - static_cast<float>(TextNum), -2.0f));
	TextRend->Clip.PosY = 126.0f;

	float4 Scale = TextRend->GetTransform().GetLocalScale();

	
	GameEngineCollision* TrashCollision = CreateComponent<GameEngineCollision>();
	TrashCollision->GetTransform().SetLocalScale(float4(11,13,0));
	TrashCollision->GetTransform().SetLocalPosition(float4(228.0f, 137.0f - static_cast<float>(TextNum)));

	GameEngineCollision* Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalScale(float4(Scale.x, Scale.y, 0));
	Collision->GetTransform().SetLocalPosition(float4(138.0f, 137.0f - static_cast<float>(TextNum)));
	if (_Text == "Comment1_12.png"
		||_Text == "Comment1_15.png")
	{
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
	Col.push_back(std::make_pair(Collision,TrashCollision));

	MoveStart++;
	if (MoveStart >= 10)
	{
			Move = Move + 25;
			TextMove(25.0f, static_cast<float>(Move));
	}

}

void Comment::TextMove(float Y_, float last)
{
	std::vector<CommentTextureRenderer*>::iterator StartIter = Text.begin();
	std::vector<CommentTextureRenderer*>::iterator EndIter = Text.end();
    std::string A =  (*StartIter)->GetNameCopy();

	std::vector<std::pair<GameEngineCollision*, GameEngineCollision*>>::iterator StartColIter = Col.begin();
	std::vector<std::pair<GameEngineCollision*, GameEngineCollision*>>::iterator EndColIter = Col.end();

	for (; StartIter != EndIter - 1; ++StartIter,++StartColIter )
	{
		(*StartIter)->GetTransform().SetLocalMove(float4(0, Y_,0));
		(*StartColIter).first->GetTransform().SetLocalMove(float4(0, Y_,0));
		(*StartColIter).second->GetTransform().SetLocalMove(float4(0, Y_,0));
	}

	(StartIter) = EndIter - 1;
	(*StartIter)->GetTransform().SetLocalMove(float4(0, last,0));

	(StartColIter) = EndColIter - 1;
	(*StartColIter).first->GetTransform().SetLocalMove(float4(0, last,0));
	(*StartColIter).second->GetTransform().SetLocalMove(float4(0, last,0));
}
