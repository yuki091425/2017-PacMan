#include<Windows.h>
#include<d3dx9.h>

#include"BackGround.h"
#include"main.h"

#define WIDTH	640
#define	HEIGHT	780

void BGdraw()
{
	/*”wŒi*/
	CUSTOMVERTEX BackGround[]
	{
		{ 0.f, 0.f, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ WIDTH, 0.f, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ WIDTH, HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ 0.f, HEIGHT, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[BACKGROUND_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, BackGround, sizeof(CUSTOMVERTEX));
}