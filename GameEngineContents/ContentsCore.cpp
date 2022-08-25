#include "PreCompile.h"
#include "ContentsCore.h"
#include "TitleLevel.h"
#include "LoadingLevel.h"
#include "PlayLevel.h"
#include "TestLevel.h"
#include "Stream.h"
#include "WebCamWindow.h"
#include "LineMain.h"
#include "TaskManager.h"

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

		Dir.MoveParentToExitsChildDirectory("MyShader");
		Dir.Move("MyShader");

		std::vector<GameEngineFile> Shaders = Dir.GetAllFile("hlsl");

		for (size_t i = 0; i < Shaders.size(); i++)
		{
			GameEngineShader::AutoCompile(Shaders[i].GetFullPath());
		}
	}
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
		{
			GameEngineDirectory Dir;

			Dir.MoveParentToExitsChildDirectory("Resources");
			Dir.Move("Resources");
			Dir.Move("Twitter");

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
			Dir.Move("LineText");

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
			Dir.Move("icon");

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
			Dir.Move("CommentText");

			std::vector<GameEngineFile> Shaders = Dir.GetAllFile();

			for (size_t i = 0; i < Shaders.size(); i++)
			{
				GameEngineTexture::Load(Shaders[i].GetFullPath());
			}
		}
	}
	{
		GameEngineRenderingPipeLine* NewPipe = GameEngineRenderingPipeLine::Create("MyTexture");
		NewPipe->SetVertexShader("MyTexture.hlsl");
		NewPipe->SetPixelShader("MyTexture.hlsl");
	}
	{
		GameEngineRenderingPipeLine* NewPipe = GameEngineRenderingPipeLine::Create("CommentTexture");
		NewPipe->SetVertexShader("CommentTexture.hlsl");
		NewPipe->SetPixelShader("CommentTexture.hlsl");
	}
	GameEngineFont::Load("Galmuri11");
	GameEngineFont::Load("Galmuri9");
	GameEngineFont::Load("Galmuri7");
	GameEngineFont::Load("Zpix");
	GameEngineFont::Load("NanumBarunGothic");
	GameEngineFont::Load("NanumBarunGothicBold");
	GameEngineFont::Load("DinkieBitmap 7px");

	//cho
	GameEngineTexture::Cut("cho_kashikoma.png", 8, 2);
	GameEngineTexture::Cut("cho_idle.png", 3, 2);
	GameEngineTexture::Cut("cho_kawaiku.png", 3, 2);
	GameEngineTexture::Cut("cho_pointing.png", 5, 2);
	GameEngineTexture::Cut("cho_angel.png", 2, 2);
	GameEngineTexture::Cut("cho_teach.png", 2, 2);
	GameEngineTexture::Cut("stream_cho_end.png", 1, 2);
	GameEngineTexture::Cut("cho_dokuzetsu_superchat.png", 6, 2);
	GameEngineTexture::Cut("cho_nyo.png", 2, 2);

	GameEngineTexture::Cut("ame_handspinner.png", 11, 1);
	GameEngineTexture::Cut("boot.png", 10, 7);
	GameEngineTexture::Cut("Windose.png", 10, 3);
	GameEngineTexture::Cut("Bank.png", 10, 19);
	GameEngineTexture::Cut("ame_egosearching_ura.png", 5, 1);
	GameEngineTexture::Cut("ame_idle_normal1.png", 11, 1);
	GameEngineTexture::Cut("ame_talk1.png", 5, 2);
	GameEngineTexture::Cut("ame_out0.png", 5, 3);

	GameEngineTexture::Cut("badge.png",1, 1);
	GameEngineTexture::Cut("icon_desktop_internet.png", 1, 2);

	GameEngineTexture::Cut("icon_loading_poketter.png", 8, 1);
	// ���ҽ��� �ε��ϴµ�.

	// RTTI �� Ÿ�� Ÿ�� �������̼�
	CreateLevel<LoadingLevel>("Loading");
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	CreateLevel<TestLevel>("Test");
	ChangeLevel("Play");

	GameEngineGUI::CreateGUIWindow<GameEngineStatusWindow>("EngineStatus", nullptr);
}

void ContentsCore::Update(float _DeltaTime)
{
	// ������ ����Ǿ���.
	// ������ ��� �޼���â�� �������Ѵ�.
	GlobalContentsValue::LineNum = 1;

}

void ContentsCore::End()
{
	Stream::Destroy();
	TaskManager::Destroy();
	LineMain::Destroy();
	WebCamWindow::Destroy();
	TaskManager::Destroy();
	Mouse::Destroy();

}