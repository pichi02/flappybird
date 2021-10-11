#include"gameplay.h"
#include"raylib.h"

int playerSize = 30;
int playerPosX = 30;
int playerPosY = 300;

void drawGameplay()
{
	ClearBackground(BLACK);
	DrawRectangle(playerPosX, playerPosY, playerSize, playerSize, WHITE);
}

void updateGameplay()
{
	if (IsKeyDown(KEY_DOWN))
	{
		playerPosY += 5;
	}
	if (IsKeyDown(KEY_UP))
	{
		playerPosY -= 5;
	}
}
