#include"raylib.h"
#include"main.h"
#include"menu.h"
#include"gameplay.h"

Screens currentScreen = MENU;
int main()
{

	
	InitWindow(800, 450, "FLAPPY BIRD");
	SetTargetFPS(60);
	initMenu();
		
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

