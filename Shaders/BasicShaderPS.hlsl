Texture2D GeneralTexture : register(t0);
SamplerState SamplerLinear : register(s0);

struct PS_INPUT
{
	float4 Position : SV_POSITION;
	float2 TextureCoord : TEXCOORD;
};

float4 PS(PS_INPUT input) : SV_Target
{
	float4 textureColor = GeneralTexture.Sample(SamplerLinear, input.TextureCoord);
	clip(textureColor.r - 0.05f);

	return textureColor;
}