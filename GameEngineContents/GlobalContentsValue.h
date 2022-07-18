#pragma once
#include "Player.h"
#include "Monster.h"

enum class OBJECTORDER
{
	Player,
	Monster,
};


// Ό³Έν :
class GlobalContentsValue
{
public:
	class Enums 
	{
	};



	static int Mental;
	static int Stress;
	static int Affection;
	static int Followers;
	static bool boot;

private:
	GlobalContentsValue()	{	}

	~GlobalContentsValue()	{	}
};

