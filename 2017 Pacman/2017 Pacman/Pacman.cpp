#include<Windows.h>
#include<d3d9.h>
#include<dinput.h>
#include"main.h"
#include"Dinput.h"
#include"Collision.h"
#include"Enemy.h"

CHARCTER_STATE g_pacman = { 150, 530, 16.f };

float x = 0;
float y = 0;

bool g_EX = false;
static int	g_timeup = 0;

void pacdraw()
{
	CUSTOMVERTEX pacman[]
	{
		{ g_pacman.x - g_pacman.scale + x, g_pacman.y - g_pacman.scale + y, 1.f, 1.f, 0xFFFFFFFF, 0.f, 0.f },
		{ g_pacman.x + g_pacman.scale + x, g_pacman.y - g_pacman.scale + y, 1.f, 1.f, 0xFFFFFFFF, 1.f, 0.f },
		{ g_pacman.x + g_pacman.scale + x, g_pacman.y + g_pacman.scale + y, 1.f, 1.f, 0xFFFFFFFF, 1.f, 1.f },
		{ g_pacman.x - g_pacman.scale + x, g_pacman.y + g_pacman.scale + y, 1.f, 1.f, 0xFFFFFFFF, 0.f, 1.f }
	};

	g_pD3Device->SetTexture(0, g_pTexture[PACMAN_TEX]);
	g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, pacman, sizeof(CUSTOMVERTEX));

	if (g_EX)
	{
		g_pD3Device->SetTexture(0, g_pTexture[PACMAN_EX_TEX]);
		g_pD3Device->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, pacman, sizeof(CUSTOMVERTEX));

		g_EX = false;
	}
}

void Paccontrol()
{
	KEYSTATE key[256];
	KeyCheckDinput(&key[DIK_LEFT], DIK_LEFT);
	KeyCheckDinput(&key[DIK_RIGHT], DIK_RIGHT);
	KeyCheckDinput(&key[DIK_UP], DIK_UP);
	KeyCheckDinput(&key[DIK_DOWN], DIK_DOWN);
	KeyCheckDinput(&key[DIK_Z], DIK_Z);
	KeyCheckDinput(&key[DIK_A], DIK_A);
	KeyCheckDinput(&key[DIK_W], DIK_W);
	KeyCheckDinput(&key[DIK_SPACE], DIK_SPACE);

	if (key[DIK_UP] == ON)
	{
		y -= 1.5;
		g_EX = true;
		g_timeup += 1;
	}

	if (key[DIK_DOWN] == ON)
	{
		y += 1.5;
		g_EX = true;
		g_timeup += 1;
	}

	if (key[DIK_LEFT] == ON)
	{
		x -= 1.5;
		g_EX = true;
		g_timeup += 1;
	}

	if (key[DIK_RIGHT] == ON)
	{
		x += 1.5;
		g_EX = true;
		g_timeup += 1;	
	}

	if (g_timeup > 7)
	{
		g_EX = false;
		g_timeup = 0;
	}

}