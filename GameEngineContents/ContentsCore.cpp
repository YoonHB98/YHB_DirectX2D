#include "PreCompile.h"
#include "ContentsCore.h"
#include "GameEngineContents/TitleLevel.h"
#include "GameEngineContents/LoadingLevel.h"
#include "GameEngineContents/PlayLevel.h"

#pragma comment(lib, "GameEngineBase.lib")

ContentsCore::ContentsCore()
	: GameEngineCore()
{
}

ContentsCore::~ContentsCore()
{
}

void ContentsCore::Start()
{
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("Resources");
		Dir.Move("Resources");
		Dir.Move("Texture");

		std::vector<GameEngineFile> Shaders = Dir.GetAllFile();

		for (size_t i = 0; i < Shaders.size(); i++)
		{
			GameEngineTexture::Load(Shaders[i].GetFullPath());
		}
	}
	{
		GameEngineDirectory Dir;

		Dir.MoveParentToExitsChildDirectory("Resources");
		Dir.Move("Resources");
		Dir.Move("Sound");

		std::vector<GameEngineFile> Shaders = Dir.GetAllFile();

		for (size_t i = 0; i < Shaders.size(); i++)
		{
			GameEngineSound::LoadRessource(Shaders[i].GetFullPath());
		}
		{
			GameEngineDirectory Dir;

			Dir.MoveParentToExitsChildDirectory("Resources");
			Dir.Move("Resources");
			Dir.Move("Ame");

			std::vector<GameEngineFile> Shaders = Dir.GetAllFile();

			for (size_t i = 0; i < Shaders.size(); i++)
			{
				GameEngineTexture::Load(Shaders[i].GetFullPath());
			}
		}
		{
			GameEngineDirectory Dir;

			Dir.MoveParentToExitsChildDirectory("Resources");
			Dir.Move("Resources");
			Dir.Move("Cho");

			std::vector<GameEngineFile> Shaders = Dir.GetAllFile();

			for (size_t i = 0; i < Shaders.size(); i++)
			{
				GameEngineTexture::Load(Shaders[i].GetFullPath());
			}
		}
	}



	GameEngineTexture::Cut("ame_handspinner.png", 11, 1);
	GameEngineTexture::Cut("boot.png", 10, 7);
	GameEngineTexture::Cut("Windose.png", 10, 3);
	GameEngineTexture::Cut("Bank.png", 10, 19);
	GameEngineTexture::Cut("ame_egosearching_ura.png", 5, 1);
	GameEngineTexture::Cut("ame_idle_normal1.png", 11, 1);
	GameEngineTexture::Cut("ame_talk1.png", 5, 2);
	GameEngineTexture::Cut("ame_out0.png", 5, 3);
	GameEngineTexture::Cut("cho_kashikoma.png", 8, 1);
	// ���ҽ��� �ε��ϴµ�.

	// RTTI �� Ÿ�� Ÿ�� �������̼�
	CreateLevel<LoadingLevel>("Loading");
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	ChangeLevel("Play");

	// ���������� ����
	// �� ���ӿ��� Ÿ��Ʋȭ��
	//            ��������1
	//            ��������2
}

void ContentsCore::Update(float _DeltaTime)
{
	// ������ ����Ǿ���.
	// ������ ��� �޼���â�� �������Ѵ�.
	GlobalContentsValue::LineNum = 1;

}

void ContentsCore::End()
{
	int a = 0;
}