#include"gameplay.h"
#include"raylib.h"
#include <iostream>
#include<time.h>
#include"Parallax.h"

using namespace parallax;

int playerSize;
float playerPosX;
float playerPosY;
float accel;
float initialObstaclePosX;
bool isParallaxInited = false;
float gravity;
float flappingForce;
OBSTACLE obstacle;


void initValeus() 
{
	
	playerSize = 30;
	playerPosX = 30.0f;
	playerPosY = 300.0f;
	gravity = 3.0f;
	accel = 0;
	flappingForce = 6.0f;
	obstacle.r1.height = GetScreenHeight();
	obstacle.r2.height = GetScreenHeight();
	obstacle.r1.width = 50;
	obstacle.r2.width = 50;
	initialObstaclePosX = GetScreenWidth()  - obstacle.r1.width ;
	obstacle.r1.x = initialObstaclePosX;
	obstacle.r2.x = initialObstaclePosX;
	obstacle.r1.y = GetRandomValue(playerSize, GetScreenHeight());
	obstacle.r2.y = obstacle.r1.y - obstacle.r1.height-playerSize*4;
	gameOver = false;
	if (!isParallaxInited)
	{
		InitParallax();
		isParallaxInited = true;
	}
	
	
}
void drawGameplay()
{
	ClearBackground(BLACK);
	DrawParallax();
	DrawRectangle(playerPosX, playerPosY, playerSize, playerSize, WHITE);
	DrawRectangle(obstacle.r1.x, obstacle.r1.y, obstacle.r1.width, obstacle.r1.height,WHITE);
	DrawRectangle(obstacle.r2.x, obstacle.r2.y, obstacle.r2.width, obstacle.r2.height, WHITE);
	
}

void updateGameplay()
{
	UpdateParallax();
	movePlayer();
	updateObstaclePos();
	if (IsKeyDown(KEY_SPACE))
	{
		accel = -flappingForce;
	}
	else
	{
		accel =  gravity;
	}
	if (Collision(playerPosX,playerPosY,playerSize,obstacle.r1.x,obstacle.r1.y,obstacle.r1.width,obstacle.r1.height)|| Collision(playerPosX, playerPosY, playerSize, obstacle.r2.x, obstacle.r2.y, obstacle.r2.width, obstacle.r2.height))
	{
		gameOver = true;
		DeInitParallax();
		isParallaxInited = false;
		currentScreen = GAMEOVER;
		
	}
	if (IsKeyPressed(KEY_M))
	{
		currentScreen = MENU;
	}
	
	
}

void movePlayer()
{
	playerPosY += accel;
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
		obstacle.r2.y = obstacle.r1.y - obstacle.r1.height - playerSize * 4;
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





