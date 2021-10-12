#include"gameplay.h"
#include"raylib.h"
#include <iostream>
#include<time.h>


int playerSize;
int playerPosX;
int playerPosY;
int initialObstaclePosX;
OBSTACLE obstacle;
int obstaclePosX;
int obstaclePosY;
int obstacleWidth;
int obstacleHeight;

void initValeus() 
{
	
	playerSize = 30;
	playerPosX = 30;
	playerPosY = 300;
	obstacle.r1.height = GetScreenHeight();
	obstacle.r2.height = GetScreenHeight();
	obstacle.r1.width = 50;
	obstacle.r2.width = 50;
	initialObstaclePosX = GetScreenWidth() / 2 - obstacleWidth / 2;
	obstacle.r1.x = initialObstaclePosX;
	obstacle.r2.x = initialObstaclePosX;
	obstacle.r1.y = GetRandomValue(playerSize, GetScreenHeight());
	obstacle.r2.y = obstacle.r1.y - obstacle.r1.height-playerSize*2;
	gameOver = false;
}
void drawGameplay()
{
	ClearBackground(BLACK);
	DrawRectangle(playerPosX, playerPosY, playerSize, playerSize, WHITE);
	DrawRectangle(obstacle.r1.x, obstacle.r1.y, obstacle.r1.width, obstacle.r1.height,WHITE);
	DrawRectangle(obstacle.r2.x, obstacle.r2.y, obstacle.r2.width, obstacle.r2.height, WHITE);
}

void updateGameplay()
{
	movePlayer();
	updateObstaclePos();
	if (Collision(playerPosX,playerPosY,playerSize,obstacle.r1.x,obstacle.r1.y,obstacle.r1.width,obstacle.r1.height)|| Collision(playerPosX, playerPosY, playerSize, obstacle.r2.x, obstacle.r2.y, obstacle.r2.width, obstacle.r2.height))
	{
		gameOver = true;
		currentScreen = GAMEOVER;
		
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
	obstacle.r1.x-=4;
	obstacle.r2.x-=4;
	if (obstacle.r1.x < playerPosX - playerSize * 2)
	{
		obstacle.r1.x =initialObstaclePosX;
		obstacle.r2.x = initialObstaclePosX;
		obstacle.r1.y = GetRandomValue(playerSize,GetScreenHeight());
		obstacle.r2.y = obstacle.r1.y - obstacle.r1.height - playerSize * 2;
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





