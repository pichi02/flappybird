#include"gameplay.h"
#include"raylib.h"
#include <iostream>
#include<time.h>
#include"Parallax.h"

using namespace parallax;

Image birdImage1;
Image birdImage2;
Texture2D birdTexture;
Rectangle sourceRecBird;
Rectangle destRecBird;
Vector2 playerOrigin;
int playerSize;
float playerPosX;
float playerPosY;
float accel;
float initialObstaclePosX;
bool isParallaxInited = false;
bool areTexturesInited = false;
bool isTexture1Updated = true;
bool isTexture2Updated = false;

float gravity;
float flappingForce;
OBSTACLE obstacle;


void initValeus() 
{
	
	
	sourceRecBird = { 0.0f, 0.0f, (float)birdTexture.width , (float)birdTexture.height };
	destRecBird= { playerPosX, playerPosY, (float)birdTexture.width/3, (float)birdTexture.height };
	playerOrigin= { ((float)birdTexture.width/14 ) / 2, (float)birdTexture.height / 2.7f };
	playerSize = 40;
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
	if (!areTexturesInited)
	{
		birdImage1 = LoadImage("res/bird2.png");
		birdImage2 = LoadImage("res/bird1.png");
		birdTexture = LoadTextureFromImage(birdImage1);
		areTexturesInited = true;
	}
	
	
}
void drawGameplay()
{
	ClearBackground(BLACK);
	DrawRectangle(playerPosX, playerPosY, playerSize, playerSize, RAYWHITE);
	DrawParallax();
	
	DrawRectangle(obstacle.r1.x, obstacle.r1.y, obstacle.r1.width, obstacle.r1.height,WHITE);
	DrawRectangle(obstacle.r2.x, obstacle.r2.y, obstacle.r2.width, obstacle.r2.height, WHITE);
	DrawTexturePro(birdTexture, sourceRecBird, destRecBird, playerOrigin, 0, RAYWHITE);

	
}

void updateGameplay()
{

	UpdateParallax();
	movePlayer();
	updateObstaclePos();
	if (IsKeyDown(KEY_SPACE))
	{
		accel = -flappingForce;
		if (!isTexture1Updated)
		{ 
			birdTexture = LoadTextureFromImage(birdImage1);
			isTexture1Updated = true;
			isTexture2Updated = false;
		}
		
	}
	else
	{
		
		accel =  gravity;
		if (!isTexture2Updated)
		{
			birdTexture = LoadTextureFromImage(birdImage2);
			isTexture2Updated = true;
			isTexture1Updated = false;
		}
		
	}
	if (Collision(playerPosX,playerPosY,playerSize,obstacle.r1.x,obstacle.r1.y,obstacle.r1.width,obstacle.r1.height)|| Collision(playerPosX, playerPosY, playerSize, obstacle.r2.x, obstacle.r2.y, obstacle.r2.width, obstacle.r2.height))
	{
		gameOver = true;
		DeInitParallax();
		isParallaxInited = false;
		areTexturesInited = false;
		currentScreen = GAMEOVER;
		
	}
	if (IsKeyPressed(KEY_M))
	{
		currentScreen = MENU;
	}
	
	destRecBird = { playerPosX,playerPosY, (float)birdTexture.width / 3, (float)birdTexture.height };
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
bool Collision(int birdX, int birdY, int birdSize, int rectangleX, int rectangleY, int rectangleWidth, int rectangleHeight)
{
	return (birdX <= rectangleX + rectangleWidth && rectangleX <= birdX + birdSize && birdY <= rectangleY + rectangleHeight && rectangleY <= birdY + birdSize);
}
void resetValeus()
{
	initValeus();
}





