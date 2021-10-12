#pragma once
#include"raylib.h"
#include"main.h"
extern bool gameOver;
void drawGameplay();
void updateGameplay();
void initValeus();
void movePlayer();
void updateObstaclePos();
bool Collision(int mouseX, int mouseY, int mouseCollider, int ballX, int ballY, int ballSizeX, int ballSizeY);
void resetValeus();