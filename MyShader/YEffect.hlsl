// #include "myshader.hlsli"
#include "..\GameEngineResources\GameEngineShader\RenderOption.fx"

// SV_POSITION �ø�ƽ
// �׷���ī�忡�� �̳༮�� �̷� �η��ϱ� �ϰ� �ڵ����� ó���ϴ� �༮�� ������ �ϰ�.



struct Input
{
    float4 Pos : POSITION;
    float4 Tex : TEXCOORD;
};


struct Output
{
    float4 Pos : SV_POSITION;
    float4 Tex : TEXCOORD;
};


// �׷���ī�忡�� �̷����°�.
Output YEffect_VS(Input _Input)
{
    Output NewOutPut = (Output) 0;
    NewOutPut.Pos = _Input.Pos;
    NewOutPut.Tex = _Input.Tex;
    return NewOutPut;
}

// 1000
// 0100
// 2010
// 0301

// 1020
// 0103
// 0010
// 0001
Texture2D Tex : register(t0);
SamplerState Smp : register(s0);
float4 YEffect_PS(Output _Input) : SV_Target0
{
    // ���� �� ������?
    
    
    float4 Color = Tex.Sample(Smp, _Input.Tex.xy);
    
        float TempDeltaTime = SumDeltaTime + 1.0f;
    
    TempDeltaTime = clamp(TempDeltaTime, 0.0f, 20.5f);
    
    Color.rgb /= Color.a;
    Color.rgb = ((Color.rgb - 0.5f) * max(TempDeltaTime * 0.25, 0)) + 0.5f;
    Color.rgb *= Color.a;
    
    if (TempDeltaTime <= 1.8f)
    {
        Color.r = 1 - Color.r;
        Color.g = 1 - Color.g;
        Color.b = 1 - Color.b;
    }
    else
    {
        Color.r = 1 - Color.r + (-1 * TempDeltaTime * 0.075+ Color.r * (TempDeltaTime - 1.8) * 0.08);
        Color.g = 1 - Color.g + (-1 * TempDeltaTime * 0.075 + Color.g * (TempDeltaTime - 1.8) * 0.08);
        Color.b = 1 - Color.b + (-1 * TempDeltaTime * 0.075 + Color.b * (TempDeltaTime - 1.8) * 0.08);
    }


    return Color;
   
}
