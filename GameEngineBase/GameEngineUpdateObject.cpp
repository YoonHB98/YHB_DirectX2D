#include "PreCompile.h"
#include "GameEngineUpdateObject.h"

GameEngineUpdateObject::GameEngineUpdateObject()
	: IsUpdate_(true)
	, IsDeath_(false)
	, IsReleaseUpdate_(false)
	, AccTime_(0.0f)
	, DeathTime_(0.0f)
	, Order_(0)
	, Parent(nullptr)
{
}

GameEngineUpdateObject::~GameEngineUpdateObject()
{
}


void GameEngineUpdateObject::SetParent(GameEngineUpdateObject* _Parent)
{
	Parent = _Parent;
	Parent->Childs.push_back(this);
}