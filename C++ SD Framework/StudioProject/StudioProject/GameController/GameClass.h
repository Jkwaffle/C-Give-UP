#ifndef _GAMECLASS_H
#define _GAMECLASS_H

#include "../Framework\timer.h"
#include "../Framework\console.h"

enum keyIndex {
	Key_Up,
	Key_Down,
	Key_Left,
	Key_Right,
	Key_Escape,
	Key_Space,
	Key_None
};
enum GameState{
	State_InGame,
	State_Paused,
	State_Menu,
	State_GameOver
};
void Init();
void getInput();
void Update(double dTime);
void Render();
void Shutdown();
//void SetBounceTime(float delay);


class GameClass{
public:
	
	static bool keyPressed[Key_None];
	
	static Console gameConsole;

	
	double elapsedTime;
	double deltaTime;
	//double KeyBounceTime;

	void clearScreen();
	void renderFrameRate();
	void renderElapsedTime();
	void renderToScreen();

	void RenderMenu();
	void RenderInGame();
	void RenderGameOver();
	void RenderPaused();

	void MenuLogic();
	void InGameLogic();
	void GameOverLogic();
	void PausedLogic();
	
#pragma region Getters & Setters
	int getCurLevel(){
		return curLevel;
	}
	void SetLevel(int lvl){
		curLevel = lvl;
	}
	void AddLevel(){
		if (curLevel < 3)
			curLevel++;
		else
			curLevel = 0;
	}

	GameState curGameState(){
		return gamestate;
	}
	void SetGameState(GameState state){
		gamestate = state;
	}
#pragma endregion
private:
#pragma region Misc
	int curLevel;
	GameState gamestate;
	

#pragma endregion
};

#endif