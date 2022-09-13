// #include "myshader.hlsli"

// SV_POSITION �ø�ƽ
// �׷���ī�忡�� �̳༮�� �̷� �η��ϱ� �ϰ� �ڵ����� ó���ϴ� �༮�� ������ �ϰ�.

#include "TransformHeader.fx"

// 0                                                                                                1 
// 0�������������������������������������������������������������������������������������������������1

struct Input
{
    float4 Pos : POSITION;
    float4 Tex : TEXCOORD;
};

struct Output
{
    float4 Pos : SV_POSITION;
    float4 PosLocal : POSITION;
    float4 Tex : TEXCOORD;
};

// 1000
// 0100
// 2010
// 0301

// 1020
// 0103
// 0010
// 0001

cbuffer AtlasData : register(b1)
{
    float2 TextureFramePos;
    float2 TextureFrameSize;
};


Output CommentTexture_VS(Input _Input)
{
    Output NewOutPut = (Output)0;
    NewOutPut.Pos = mul(_Input.Pos, WorldViewProjection);
    NewOutPut.PosLocal = _Input.Pos;
    
    // ���ؽ��� ���° ���ؽ� ���� �˼��� ����.
    // NewOutPut.Tex
    // 00    10
    
    // 10    11
    
    NewOutPut.Tex.x = (_Input.Tex.x * TextureFrameSize.x) + TextureFramePos.x;
    NewOutPut.Tex.y = (_Input.Tex.y * TextureFrameSize.y) + TextureFramePos.y;
    
    return NewOutPut;
}


Texture2D Tex : register(t0);
SamplerState Smp : register(s0);

cbuffer Clip : register(b0)
{
    float X;
    float Y;
    float XX;
    float YY;
}

cbuffer Color : register(b1)
{
    float RR;
    float GG;
    float BB;
    float AA;
}


float4 CommentTexture_PS(Output _Input) : SV_Target0
{
    float4 Color = Tex.Sample(Smp, _Input.Tex.xy);

     if (_Input.Pos.y < Y)
        {
        //126
            clip(-1);
        }
    
    if (_Input.Pos.x > X)
    {
        //1200
        clip(-1);
    }
    
    if (_Input.Pos.x < XX)
    {
        //1200
        clip(-1);
    }
    
    if (RR != 0)
    {
        Color.r = RR;
        Color.g = GG;
        Color.b = BB;
    }
    Color.rgb /= Color.a;

  // Apply contrast.
    Color.rgb = ((Color.rgb - 0.5f) * max(YY, 0)) + 0.5f;
    
  // Apply brightness.
    //float Brightness = (((1.0f - abs((_Input.Pos.x - 60.5f)) / 60.5f) + (1.0f - abs((_Input.Pos.y - 270.0f) / 270.0f)))) / 2;
    float Brightness =  (1.0f - abs((_Input.Pos.y - 270.0f) / 270.0f)) / 2;
    Color.rgb += Brightness * AA;

  // Return final pixel color.
    Color.rgb *= Color.a;

        return Color;

}
