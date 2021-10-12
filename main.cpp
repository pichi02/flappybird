#include"raylib.h"
#include"main.h"
#include"menu.h"
#include"gameplay.h"

int weigth = 800;
int height = 450;
Screens currentScreen = MENU;
bool gameOver = false;

int main()
{

	
	InitWindow(weigth, height, "FLAPPY BIRD");
	SetTargetFPS(60);
	initMenu();
	initValeus();
		
	while (!WindowShouldClose()&& !getQuit())
	{

		BeginDrawing();
		switch (currentScreen)
		{
		case MENU:
			updateMenu();
			drawMenu();
			break;
		case GAMEPLAY:
			updateGameplay();
			drawGameplay();
			break;
		case GAMEOVER:
			updateGameOverScreen();
			drawGameOverScreen();
			resetValeus();
			break;
		case OPTIONS:
			break;
		case VICTORY:
			updateVictoryScreen();
			drawVictoryScreen();
			break;
		case CREDITS:
			updateCreditsScreen();
			updateMenuMusic();
			drawCreditsScreen();
			break;
		default:
			break;
		}
		
		EndDrawing();
	}



	CloseWindow();


	
}

