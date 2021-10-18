#pragma once
#include"raylib.h"
#include"main.h"

struct OBSTACLE
{
	Rectangle r1;
	Rectangle r2;
};
extern bool gameOver;
void drawGameplay();
void updateGameplay();
void initValeus();
void movePlayer();
void updateObstaclePos();
bool Collision(int birdX, int birdY, int birdSize, int rectangleX, int rectangleY, int rectangleWidth, int rectangleHeight);
void resetValeus();