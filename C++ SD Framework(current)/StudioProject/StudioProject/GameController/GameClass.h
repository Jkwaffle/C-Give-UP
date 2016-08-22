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



void SetBounceTime(double delay);
void ResetGame();


class GameClass{
public:
	static bool keyPressed[Key_None];
	
	static Console gameConsole;

	
	double elapsedTime;
	double deltaTime;
	double KeyBounceTime;

	void clearScreen();
	void renderFrameRate();
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
	int curLevel;
	void AddLevel(){
		curLevel++;
	}
	GameState curGameState(){
		return gamestate;
	}
	void SetGameState(GameState state){
		gamestate = state;
	}
#pragma endregion
#pragma region Misc
	double InGameTime;
	void renderInGameTime();
private:
	//int curLevel;
	GameState gamestate;
	
#pragma endregion
};
#endif