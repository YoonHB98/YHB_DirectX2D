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
}

void Comment::Update(float _DeltaTime)
{
	GlobalContentsValue::Stream = true;
	if (GlobalContentsValue::Stream)
	{
		if (i <((GlobalContentsValue::ChangeTime - 9)/3.115))
		{
			if	(i < 27)
			{
				CreateText("Comment1_" + std::to_string(i) + ".png");
				i = i + 1;
			}
		}

	}
}

void Comment::End()
{
}

void Comment::CreateText(std::string _Text)
{
	CommentTextureRenderer* TextRend = CreateComponent<CommentTextureRenderer>();
	TextRend->SetTexture(_Text);
	TextRend->ScaleToTexture();
	TextRend->GetTransform().SetLocalPosition(float4(138, 137 - TextNum));
	float4 Scale = TextRend->GetTransform().GetLocalScale();

	
	GameEngineCollision* Collision = CreateComponent<GameEngineCollision>();
	Collision->GetTransform().SetLocalScale(float4(Scale.x,Scale.y,0));
	Collision->GetTransform().SetLocalPosition(float4(138, 137 - TextNum));
	Collision->ChangeOrder(OBJECTORDER::UI);

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
