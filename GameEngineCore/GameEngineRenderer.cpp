#include "GameEngineRenderer.h"
#include "GameEngineActor.h"
#include "GameEngineLevel.h"
#include <Windows.h>
#include <GameEngineBase/GameEngineWindow.h>

#include "GameEngineVertexBuffer.h"
#include "GameEngineIndexBuffer.h"

GameEngineRenderer::GameEngineRenderer()
{
}

GameEngineRenderer::~GameEngineRenderer()
{
}


void GameEngineRenderer::Start()
{
	GetActor()->GetLevel()->PushRenderer(this);
}


void GameEngineRenderer::Render(float _DeltaTime)
{


	// ������
	GameEngineVertexBuffer* Vertex = GameEngineVertexBuffer::Find("Box");
	GameEngineIndexBuffer* Index = GameEngineIndexBuffer::Find("Box");

	std::vector<POINT> DrawVertex;
	DrawVertex.resize(Index->Indexs.size());

	std::vector<float4> CopyBuffer;
	CopyBuffer.resize(Index->Indexs.size());

	float4x4 Scale;
	float4x4 Position;
	float4x4 Rotate;
	float4x4 World;

	Scale.Scale(GetActor()->GetTransform().GetScale());
	Position.Postion(GetActor()->GetTransform().GetPosition());

	World = Scale * Rotate * Position;



	for (size_t i = 0; i < Index->Indexs.size(); i++)
	{
		int TriIndex = Index->Indexs[i];

		// 0 ��° ������ ���� �˴ϴ�.
		// ���ʿ� ���� �Ž��� ���� �����մϴ�.
		CopyBuffer[i] = Vertex->Vertexs[TriIndex];

		CopyBuffer[i] = CopyBuffer[i] * World;

		// ����
		//CopyBuffer[i] = float4::VectorRotationToDegreeXAxis(CopyBuffer[i], Angle);
		//CopyBuffer[i] = float4::VectorRotationToDegreeYAxis(CopyBuffer[i], Angle);
		//CopyBuffer[i] = float4::VectorRotationToDegreeZAxis(CopyBuffer[i], Angle);




		DrawVertex[i] = CopyBuffer[i].GetConvertWindowPOINT();
	}


	for (size_t i = 0; i < DrawVertex.size(); i += 3)
	{
		Polygon(GameEngineWindow::GetHDC(), &DrawVertex[i], 3);
	}


	// Rectangle(GameEngineWindow::GetHDC(), LeftTop.ix(), LeftTop.iy(), RightBot.ix(), RightBot.iy());
}