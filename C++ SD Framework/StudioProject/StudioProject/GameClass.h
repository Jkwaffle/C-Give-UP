#ifndef _GAMECLASS_H
#define _GAMECLASS_H

#include "Framework\timer.h"

//Not sure if necessary...
//extern CStopWatch g_swTimer;
//extern bool g_bQuitGame;

enum keyIndex {
	Key_Up,
	Key_Down,
	Key_Left,
	Key_Right,
	Key_Escape,
	Key_Space,
	Key_None
};

enum GameState {
	State_InGame,
	State_Paused,
	State_Menu,
	State_GameOver
};



void Init();
void getInput();
void Update(double dTime);
void Render();
void ShutDown();
void SetBounceTime(float delay);

//Used in render
void clearScreen();
void renderFrameRate();
void renderElapsedTime();
void renderToScreen();

void RenderMenu();
void RenderCharacter();
void RenderMap();
void RenderGameOver();
void RenderPaused();

void MenuLogic();
void InGameLogic();
void PausedLogic();
void GameOverLogic();


#endif