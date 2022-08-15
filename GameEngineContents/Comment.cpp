#include "PreCompile.h"
#include "Comment.h"

Comment::Comment() 
{
}

Comment::~Comment() 
{
}

void Comment::Start()
{
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
	GlobalContentsValue::Stream = true;
	if (GlobalContentsValue::Stream
		&& i < ((GlobalContentsValue::ChangeTime - 9) / 3.115)
		&&i < 27)
	{
		CreateText("Comment1_" + std::to_string(i) + ".png");
		i = i + 1;

	
	}
	if (MouseCheck(CommentCheck)
		&&i > 1)
	{
		GlobalContentsValue::Check = true;
		CommentCheckStart();
	}
	else
	{
		GlobalContentsValue::Check =false;
	}
}

void Comment::End()
{
}

void Comment::CommentCheckStart()
{
	std::vector<GameEngineCollision*>::iterator StartIter = Col.begin();
	std::vector<GameEngineCollision*>::iterator EndIter = Col.end();

	std::vector<CommentTextureRenderer*>::iterator StartTextIter = Text.begin();
	std::vector<CommentTextureRenderer*>::iterator EndITexIter = Text.end();

	for (; StartIter != EndIter; ++StartIter, ++StartTextIter)
	{
		float4 Pos = (*StartIter)->GetTransform().GetLocalPosition();
		int CommentPos = Pos.y;
		if (MouseCheck((*StartIter)))
		{
			float4 Pos = (*StartIter)->GetTransform().GetLocalPosition();
			int CommentPos = Pos.y;
			if (CommentPos >= 136.9)
			{
				Trash->GetTransform().SetLocalPosition(float4(228, 137, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}else
				if (CommentPos >= 111.9)
				{
					Trash->GetTransform().SetLocalPosition(float4(228, 112, 0));
					if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
					{
						(*StartTextIter)->Clip.PosX = 540.0f;
					}
				}
				else
			if (CommentPos >= 86.9)
			{
				Trash->GetTransform().SetLocalPosition(float4(228, 87, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}else
			if (CommentPos >= 61.9)
			{
				Trash->GetTransform().SetLocalPosition(float4(228, 62, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}else
			if (CommentPos >= 36.9)
			{
				Trash->GetTransform().SetLocalPosition(float4(228, 37, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}else
			if (CommentPos >= 11.9)
			{
				Trash->GetTransform().SetLocalPosition(float4(228, 12, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}else
			if (CommentPos >= -13.1)
			{
				Trash->GetTransform().SetLocalPosition(float4(228, -13, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}else
			if (CommentPos >= -38.1)
			{
				Trash->GetTransform().SetLocalPosition(float4(228, -38, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}else
			if (CommentPos >= -63.1)
			{
				Trash->GetTransform().SetLocalPosition(float4(228,-63, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}else
			if (CommentPos >= -88.1)
			{
				Trash->GetTransform().SetLocalPosition(float4(228,-88, 0));
				if (true == GameEngineInput::GetInst()->IsDown("MouseClick"))
				{
					(*StartTextIter)->Clip.PosX = 540.0f;
				}
			}
		}
	
	}
}

void Comment::CommentTrash(int YPos)
{
	
}

void Comment::CreateText(const std::string& _Text)
{
	CommentTextureRenderer* TextRend = CreateComponent<CommentTextureRenderer>();
	TextRend->SetTexture(_Text);
	TextRend->ScaleToTexture();
	TextRend->GetTransform().SetLocalPosition(float4(138, 137 - TextNum));

	float4 Scale = TextRend->GetTransform().GetLocalScale();

	
	GameEngineCollision* Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalScale(float4(11,13,0));
	Collision->GetTransform().SetLocalPosition(float4(228, 137 - TextNum));
	if (_Text == "Comment1_12.png"
		||_Text == "Comment1_15.png")
	{
		Collision->ChangeOrder(OBJECTORDER::SuperChat);
		Collision->SetName(std::to_string(ColName));
		ColName = ColName + 1;
	}
	else 
	{
		Collision->ChangeOrder(OBJECTORDER::UI);
	}


	TextNum = TextNum + 25;
	Text.push_back(TextRend);
	Col.push_back(Collision);

	MoveStart++;
	if (MoveStart >= 10)
	{
			Move = Move + 25;
			TextMove(25, Move);
	}

}

void Comment::TextMove(float Y_, float last)
{
	std::vector<CommentTextureRenderer*>::iterator StartIter = Text.begin();
	std::vector<CommentTextureRenderer*>::iterator EndIter = Text.end();
    std::string A =  (*StartIter)->GetNameCopy();

	std::vector<GameEngineCollision*>::iterator StartColIter = Col.begin();
	std::vector<GameEngineCollision*>::iterator EndColIter = Col.end();

	for (; StartIter != EndIter - 1; ++StartIter,++StartColIter )
	{
		(*StartIter)->GetTransform().SetLocalMove(float4(0, Y_));
		(*StartColIter)->GetTransform().SetLocalMove(float4(0, Y_));
	}

	(StartIter) = EndIter - 1;
	(*StartIter)->GetTransform().SetLocalMove(float4(0, last));

	(StartColIter) = EndColIter - 1;
	(*StartColIter)->GetTransform().SetLocalMove(float4(0, last));
}
