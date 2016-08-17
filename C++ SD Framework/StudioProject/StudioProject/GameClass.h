#ifndef _GAMECLASS_H
#define _GAMECLASS_H

#include "Framework\timer.h"
//poop
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
	State_GameOver,

	S_CREDITS,
	S_VICTORY
};



void Init();
void getInput();
void Update(double dTime);
void Render();
void Shutdown();
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
void rendercredits();
void rendervictory();


void MenuLogic();
void InGameLogic();
void PausedLogic();
void GameOverLogic();
void creditsLogic();
void victoryLogic();


#endif