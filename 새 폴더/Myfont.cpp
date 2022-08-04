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

void Myfont::TextDrawTime(const std::string& Text_, const std::string& Font_, float4 Pos_, float4 Color_, float Size_, float Time)
{
	CountTime = CountTime + GameEngineTime::GetDeltaTime();
	float AA = Time / Text_.length();
	if (Text_[Count]< 0)
	{
		Text = "" + Text + Text_[0] + Text_[1];
		if (CountTime >= AA)
		{
			Text = "" + Text + Text_[Count] + Text_[Count + 1];
			Count = Count + 2;
			CountTime = CountTime - AA;
		}
	}
	else
	{
		Text = "" + Text + Text_[0];
		if (CountTime >= AA)
		{
			Text = "" + Text + Text_[Count];
			Count = Count + 1;
			CountTime = CountTime - AA;
		}
	}
	Font = GameEngineFont::Find(Font_);
	ScreenPostion = Pos_;
	Color = Color_;
	FontSize = Size_;

}



