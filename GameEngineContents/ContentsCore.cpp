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
#include "TutorialLogin.h"
#include "Asobu_Window.h"
#include "Neru_Window.h"
#include "Stream_Window.h"
#include "GameContentsGUI.h"

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

	{
		GameEngineRenderingPipeLine* NewPipe = GameEngineRenderingPipeLine::Create("YEffect");
		NewPipe->SetInputAssembler1VertexBuffer("FullRect");
		NewPipe->SetInputAssembler2IndexBuffer("FullRect");
		NewPipe->SetVertexShader("YEffect.hlsl");
		NewPipe->SetPixelShader("YEffect.hlsl");
	}

	//font
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
	GameEngineTexture::Cut("cho_kawaiku_superchat.png", 4, 2);
	GameEngineTexture::Cut("cho_nyo.png", 2, 2);
	GameEngineTexture::Cut("cho_akaruku_superchat.png", 4, 2);
	GameEngineTexture::Cut("stream_cho_sayonara1.png", 3, 2);
	GameEngineTexture::Cut("stream_cho_sayonara2.png", 3, 2);
	GameEngineTexture::Cut("stream_cho_sayonara3.png", 4, 2);
	GameEngineTexture::Cut("stream_cho_kobiru.png", 4, 2);
	GameEngineTexture::Cut("stream_cho_peace.png", 3, 2);
	GameEngineTexture::Cut("stream_cho_h_superchat.png", 4, 2);

	//ame
	GameEngineTexture::Cut("ame_handspinner.png", 11, 1);
	GameEngineTexture::Cut("boot.png", 10, 7);
	GameEngineTexture::Cut("Windose.png", 10, 3);
	GameEngineTexture::Cut("Bank.png", 10, 19);
	GameEngineTexture::Cut("ame_egosearching_ura.png", 5, 1);
	GameEngineTexture::Cut("ame_idle_normal1.png", 11, 1);
	GameEngineTexture::Cut("ame_talk1.png", 5, 2);
	GameEngineTexture::Cut("ame_out0.png", 5, 3);
	GameEngineTexture::Cut("ame_idle_happy3.png", 9, 2);
	GameEngineTexture::Cut("ame_idle_happy6.png", 6, 2);
	GameEngineTexture::Cut("ame_game.png", 4, 2);

	GameEngineTexture::Cut("badge.png", 1, 1);
	GameEngineTexture::Cut("icon_desktop_internet.png", 1, 2);

	GameEngineTexture::Cut("icon_loading_poketter.png", 8, 1);
	GameEngineTexture::Cut("tuutidaytime.png", 6, 1);
	GameEngineTexture::Cut("bg_side_bar_night.png", 10, 8);
	GameEngineTexture::Cut("bg_side_bar_evening.png", 10, 8);
	GameEngineTexture::Cut("bg_side_bar_noon.png", 1, 1);
	// 리소스를 로드하는데.

	// RTTI 런 타임 타입 인포메이션
	CreateLevel<LoadingLevel>("Loading");
	CreateLevel<TitleLevel>("Title");
	CreateLevel<PlayLevel>("Play");
	//CreateLevel<TestLevel>("Test");
	ChangeLevel("Loading");

	//GameEngineGUI::CreateGUIWindow<GameEngineStatusWindow>("EngineStatus", nullptr);
	GameEngineGUI::CreateGUIWindow<GameContentsGUI>("Status", nullptr);
}

void ContentsCore::Update(float _DeltaTime)
{
	// 서버가 종료되었어.
	// 무조건 경고 메세지창을 띄워줘야한다.
	GlobalContentsValue::LineNum = 1;

}

void ContentsCore::End()
{
	TutorialLogin::Destroy();
	Stream::Destroy();
	TaskManager::Destroy();
	LineMain::Destroy();
	WebCamWindow::Destroy();
	TaskManager::Destroy();
	Mouse::Destroy();
	Asobu_Window::Destroy();
	Neru_Window::Destroy();
	Stream_Window::Destroy();

}