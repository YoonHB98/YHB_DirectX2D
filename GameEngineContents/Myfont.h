#pragma once
#include <GameEngineCore/GameEngineFontRenderer.h>

// Ό³Έν :
class Myfont : public GameEngineFontRenderer
{
public:
	// constrcuter destructer
	Myfont();
	~Myfont();

	// delete Function
	Myfont(const Myfont& _Other) = delete;
	Myfont(Myfont&& _Other) noexcept = delete;
	Myfont& operator=(const Myfont& _Other) = delete;
	Myfont& operator=(Myfont&& _Other) noexcept = delete;
	void TextDraw(const std::string& Text_, const std::string& Font_, float4 Pos_, float4 Color_, float Size_);
	void TextDrawTime(const std::string& Text_, const std::string& Font_, float4 Pos_, float4 Color_, float Size_, float Time);
	
	int Count = 0;
	float CountTime = 0;
protected:
	
private:

};

