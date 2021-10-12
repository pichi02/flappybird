#include"raylib.h"
#include"Menu.h"
#include"main.h"


int titleX;
int titleY;
int playButtonSizeX;
int optionsButto;
int rectangleMouseSize;
int mouseX;
int mouseY;
int optionsButtonSizeX;
int buttonSizeY;
int playButtonX;
int playButtonY;
int optionsButtonX;
int optionsButtonY;
int quitButtonX;
int quitButtonY;
int quitButtonWidth;
int playAgainButtonX;
int victoryBackButtonX;
int backMenuButtonWidth;
bool quit;
static Music menuMusic;
Texture2D menuBackgroundTexture;
Image menuImage;




void initMenu()
{
	quit = false;
	titleX = (GetScreenWidth() / 100) * 25;
	titleY = (GetScreenHeight() / 10) * 3;
	playButtonSizeX = 135;
	optionsButtonSizeX = 180;
	buttonSizeY = 45;
	rectangleMouseSize = 1;
	playButtonX = (GetScreenWidth() / 100) * 42;
	playButtonY = GetScreenHeight() * 4 / 10;
	optionsButtonX = playButtonX - 20;
	optionsButtonY = GetScreenHeight() * 6 / 10;
	quitButtonX = (GetScreenWidth() / 100) * 45;
	quitButtonY = GetScreenHeight() * 8 / 10;
	quitButtonWidth = 90;
	backMenuButtonWidth = 115;
	playAgainButtonX = (GetScreenWidth() / 100) * 70;
	victoryBackButtonX = (GetScreenWidth() / 100) * 30 - quitButtonWidth;
	
	

}

void updateMenu()
{
	mouseX = GetMouseX();
	mouseY = GetMouseY();

	if (collision(mouseX, mouseY, rectangleMouseSize, playButtonX, playButtonY, playButtonSizeX, buttonSizeY) && IsMouseButtonPressed(0))
	{
		StopMusicStream(menuMusic);
		currentScreen = GAMEPLAY;
	}
	else if (collision(mouseX, mouseY, rectangleMouseSize, optionsButtonX, optionsButtonY, optionsButtonSizeX, buttonSizeY) && IsMouseButtonPressed(0))
	{
		currentScreen = CREDITS;
	}
	else if (collision(mouseX, mouseY, rectangleMouseSize, quitButtonX, quitButtonY, quitButtonWidth, buttonSizeY) && IsMouseButtonPressed(0))
	{
		quit = true;
	}

}
void drawMenu()
{

	ClearBackground(BLACK);
	DrawTextureEx(menuBackgroundTexture, { 0,0 }, 0, (GetScreenWidth() * 1.0f) / GetScreenWidth(), WHITE);
	DrawRectangle(mouseX, mouseY, rectangleMouseSize, rectangleMouseSize, BLACK);
	
	DrawText(TextFormat("FLAPPY BIRD"), (GetScreenWidth() / 100) * 24, (GetScreenHeight() / 100) * 20, 60, BLUE);
	if (collision(mouseX, mouseY, rectangleMouseSize, playButtonX, playButtonY, playButtonSizeX, buttonSizeY))
	{
		DrawText(TextFormat("start"), playButtonX, playButtonY, 50, GRAY);
	}
	else
	{
		DrawText(TextFormat("start"), playButtonX, playButtonY, 50, WHITE);
	}
	if (collision(mouseX, mouseY, rectangleMouseSize, optionsButtonX, optionsButtonY, optionsButtonSizeX, buttonSizeY))
	{
		DrawText(TextFormat("credits"), optionsButtonX, optionsButtonY, 50, GRAY);
	}
	else
	{
		DrawText(TextFormat("credits"), optionsButtonX, optionsButtonY, 50, WHITE);
	}
	if (collision(mouseX, mouseY, rectangleMouseSize, quitButtonX, quitButtonY, quitButtonWidth, buttonSizeY))
	{
		DrawText(TextFormat("quit"), quitButtonX, quitButtonY, 50, GRAY);
	}
	else
	{
		DrawText(TextFormat("quit"), quitButtonX, quitButtonY, 50, WHITE);
	}

	DrawText(TextFormat("VERSION 0.1"), (GetScreenWidth()/100)*80, (GetScreenHeight()/100)*95, 20, WHITE);

}

void drawGameOverScreen()
{
	ClearBackground(BLACK);
	DrawTextureEx(menuBackgroundTexture, { 0,0 }, 0, (GetScreenWidth() * 1.0f) / GetScreenWidth(), WHITE);
	DrawRectangle(mouseX, mouseY, rectangleMouseSize, rectangleMouseSize, BLACK);
	DrawText(TextFormat("YOU LOSE"), (GetScreenWidth() / 100) * 33, titleY, 50, WHITE);


	if (collision(mouseX, mouseY, rectangleMouseSize, playAgainButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY))
	{
		DrawText(TextFormat("play"), playAgainButtonX + 5, quitButtonY - 5, 50, GRAY);
	}
	else
	{
		DrawText(TextFormat("play"), playAgainButtonX + 5, quitButtonY - 5, 50, WHITE);
	}
	if (collision(mouseX, mouseY, rectangleMouseSize, victoryBackButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY))
	{
		DrawText(TextFormat("menu"), victoryBackButtonX, quitButtonY, 50, GRAY);
	}
	else
	{
		DrawText(TextFormat("menu"), victoryBackButtonX, quitButtonY, 50, WHITE);
	}
}
void updateGameOverScreen()

{
	mouseX = GetMouseX();
	mouseY = GetMouseY();
	if (collision(mouseX, mouseY, rectangleMouseSize, playAgainButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY) && IsMouseButtonPressed(0))
	{
		currentScreen = GAMEPLAY;
	}
	else if (collision(mouseX, mouseY, rectangleMouseSize, victoryBackButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY) && IsMouseButtonPressed(0))
	{
		currentScreen = MENU;
	}

}

void drawVictoryScreen()
{
	ClearBackground(BLACK);
	DrawTextureEx(menuBackgroundTexture, { 0,0 }, 0, (GetScreenWidth() * 1.0f) / GetScreenWidth(), WHITE);
	DrawRectangle(mouseX, mouseY, rectangleMouseSize, rectangleMouseSize, BLACK);
	DrawText(TextFormat("YOU WIN :D"), (GetScreenWidth() / 100) * 33, titleY, 50, WHITE);
	
	if (collision(mouseX, mouseY, rectangleMouseSize, playAgainButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY))
	{
		DrawText(TextFormat("play"), playAgainButtonX + 5, quitButtonY - 5, 50, GRAY);
	}
	else
	{
		DrawText(TextFormat("play"), playAgainButtonX + 5, quitButtonY - 5, 50, WHITE);
	}
	if (collision(mouseX, mouseY, rectangleMouseSize, victoryBackButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY))
	{
		DrawText(TextFormat("menu"), victoryBackButtonX, quitButtonY, 50, GRAY);
	}
	else
	{
		DrawText(TextFormat("menu"), victoryBackButtonX, quitButtonY, 50, WHITE);
	}
}
void updateVictoryScreen()

{
	mouseX = GetMouseX();
	mouseY = GetMouseY();
	if (collision(mouseX, mouseY, rectangleMouseSize, playAgainButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY) && IsMouseButtonPressed(0))
	{
		currentScreen = GAMEPLAY;
	}
	else if (collision(mouseX, mouseY, rectangleMouseSize, victoryBackButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY) && IsMouseButtonPressed(0))
	{
		currentScreen = MENU;
	}

}
void drawCreditsScreen()
{
	ClearBackground(BLACK);
	DrawTextureEx(menuBackgroundTexture, { 0,0 }, 0, (GetScreenWidth() * 1.0f) / GetScreenWidth(), WHITE);
	DrawRectangle(mouseX, mouseY, rectangleMouseSize, rectangleMouseSize, BLACK);
	DrawText(TextFormat("CREDITS"), (GetScreenWidth() / 100) * 35, (GetScreenHeight() / 100) * 15, 50, WHITE);
	DrawText(TextFormat("VERSION 0.1"), (GetScreenWidth() / 100) * 80, (GetScreenHeight() / 100) * 95, 20, WHITE);
	
	if (collision(mouseX, mouseY, rectangleMouseSize, victoryBackButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY))
	{
		DrawText(TextFormat("menu"), victoryBackButtonX, quitButtonY, 50, GRAY);
	}
	else
	{
		DrawText(TextFormat("menu"), victoryBackButtonX, quitButtonY, 50, WHITE);
	}

}
void updateCreditsScreen()

{
	mouseX = GetMouseX();
	mouseY = GetMouseY();

	if (collision(mouseX, mouseY, rectangleMouseSize, victoryBackButtonX, quitButtonY, backMenuButtonWidth, buttonSizeY) && IsMouseButtonPressed(0))
	{
		currentScreen = MENU;
	}

}

bool collision(int mouseX, int mouseY, int mouseCollider, int ballX, int ballY, int ballSizeX, int ballSizeY)
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
void updateMenuMusic()
{

}
bool getQuit()
{
	return quit;
}