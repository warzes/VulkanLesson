// Copyright 2020 Google LLC

struct VSInput
{
[[vk::location(0)]] float3 Pos : POSITION0;
[[vk::location(1)]] float3 Normal : NORMAL0;
[[vk::location(2)]] float3 Color : COLOR0;
};

struct UBO
{
	float4x4 projection;
	float4x4 modelview;
	float4 lightPos;
};

cbuffer ubo : register(b0) { UBO ubo; }

struct VSOutput
{
	float4 Pos : SV_POSITION;
[[vk::location(0)]] float3 Normal : NORMAL0;
[[vk::location(1)]] float3 Color : COLOR0;
[[vk::location(2)]] float3 ViewVec : TEXCOORD1;
[[vk::location(3)]] float3 LightVec : TEXCOORD2;
};

struct PushConsts {
	float3 objPos;
};
[[vk::push_constant]] PushConsts pushConsts;

VSOutput main(VSInput input)
{
	VSOutput output = (VSOutput)0;
	output.Normal = input.Normal;
	output.Color = input.Color;

	float3 locPos = mul(ubo.modelview, float4(input.Pos, 1.0)).xyz;
	float3 worldPos = mul(ubo.modelview, float4(input.Pos + pushConsts.objPos, 1.0)).xyz;
	output.Pos = mul(ubo.projection, float4(worldPos, 1.0));

	float4 pos = mul(ubo.modelview, float4(worldPos, 1.0));
	output.Normal = mul((float3x3)ubo.modelview, input.Normal);
	output.LightVec = ubo.lightPos.xyz - pos.xyz;
	output.ViewVec = -pos.xyz;
	return output;
}