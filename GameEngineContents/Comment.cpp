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

		TextNum = TextNum +25;
	Text.push_back(TextRend);
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

	for (; StartIter != EndIter - 1; ++StartIter)
	{
		(*StartIter)->GetTransform().SetLocalMove(float4(0, Y_));
	}
	(StartIter) = EndIter - 1;
	(*StartIter)->GetTransform().SetLocalMove(float4(0, last));
}
