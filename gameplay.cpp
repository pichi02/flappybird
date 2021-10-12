#include"gameplay.h"
#include"raylib.h"
#include <iostream>
#include<time.h>

int playerSize;
int playerPosX;
int playerPosY;
int initialObstaclePosX;
int obstaclePosX;
int obstaclePosY;
int obstacleWidth;
int obstacleHeight;

void initValeus() 
{
	playerSize = 30;
	playerPosX = 30;
	playerPosY = 300;
	obstacleHeight = GetScreenHeight();
	obstacleWidth = 50;
	initialObstaclePosX = GetScreenWidth() / 2 - obstacleWidth / 2;
	obstaclePosX = initialObstaclePosX;
	obstaclePosY = GetRandomValue(playerSize, GetScreenHeight());
	gameOver = false;
}
void drawGameplay()
{
	ClearBackground(BLACK);
	DrawRectangle(playerPosX, playerPosY, playerSize, playerSize, WHITE);
	DrawRectangle(obstaclePosX, obstaclePosY, obstacleWidth, obstacleHeight,WHITE);
}

void updateGameplay()
{
	movePlayer();
	updateObstaclePos();
	if (Collision(playerPosX,playerPosY,playerSize,obstaclePosX,obstaclePosY,obstacleWidth,obstacleHeight))
	{
		gameOver = true;
		currentScreen = GAMEOVER;
		resetValeus();
	}
}

void movePlayer()
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

void updateObstaclePos()
{
	
	srand(time(NULL));
	obstaclePosX--;
	if (obstaclePosX < playerPosX - playerSize * 2)
	{
		obstaclePosX=initialObstaclePosX;
		obstaclePosY = GetRandomValue(playerSize,GetScreenHeight());
	}
	
}
bool Collision(int mouseX, int mouseY, int mouseCollider, int ballX, int ballY, int ballSizeX, int ballSizeY)
{
	if (mouseX <= ballX + ballSizeX && ballX <= mouseX + mouseCollider && mouseY <= ballY + ballSizeY && ballY <= mouseY + mouseCollider)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
void resetValeus()
{
	initValeus();
}





