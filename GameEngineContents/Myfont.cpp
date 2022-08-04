#include "Myfont.h"
#include "PreCompile.h"

Myfont::Myfont() 
{
}

Myfont::~Myfont() 
{
}

void Myfont::TextDraw(const std::string& Text_, const std::string& Font_, float4 Pos_, float4 Color_, float Size_)
{
	Text = Text_;
	Font = GameEngineFont::Find(Font_);
	ScreenPostion = Pos_;
	Color = Color_;
	FontSize = Size_;
}

