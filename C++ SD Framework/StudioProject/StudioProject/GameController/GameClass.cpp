#include "GameClass.h"
#include "../Framework/console.h"
#include "../LevelGenerator/MapGenerator.h"
#include "../MenuControllers/MenuController.h"
#include "../MenuControllers/PausedMenuController.h"
#include "PlayerClass.h"
#include <iostream>
#include <iomanip>
#include <sstream>

MapGenerator MapObj;
MenuController MenuObj;
PausedMenuController PauseMenuObj;
//Console Directly linked to GameClass.H
Console GameClass::gameConsole(120, 60, "Give Up: Console ver!!");
//gameController to copy and use variables
GameClass gameController;


bool GameClass::keyPressed[Key_None];
PlayerClass playerChar;
int curLevel = 0;

void Init(){
	gameController.SetGameState(State_Menu);
<<<<<<< HEAD
=======
	//GameClass::curGameState = State_Menu;
>>>>>>> origin/master
	gameController.elapsedTime = 0.0;
	gameController.deltaTime = 0.0;
}
void getInput(){
	GameClass::keyPressed[Key_Up] = isKeyPressed(VK_UP);
	GameClass::keyPressed[Key_Down] = isKeyPressed(VK_DOWN);
	GameClass::keyPressed[Key_Left] = isKeyPressed(VK_LEFT);
	GameClass::keyPressed[Key_Right] = isKeyPressed(VK_RIGHT);
	GameClass::keyPressed[Key_Escape] = isKeyPressed(VK_ESCAPE);
	GameClass::keyPressed[Key_Space] = isKeyPressed(VK_SPACE);
}

//Logic Controller
void Update(double dTime){
	gameController.elapsedTime += dTime;
	gameController.deltaTime = dTime;
	switch (gameController.curGameState()){
	case State_Menu:
		gameController.MenuLogic();
		break;
	case State_InGame:
		gameController.InGameLogic();
		gameController.InGameTime += dTime;
		break;
	case State_Paused:
		gameController.PausedLogic();
		break;
	case State_GameOver:
		gameController.GameOverLogic();
		break;
	}
}
void Render(){
	gameController.clearScreen();
	switch (gameController.curGameState()){
	case State_Menu:
		gameController.RenderMenu();
		break;
	case State_InGame:
		gameController.RenderInGame();
		gameController.renderInGameTime();
		break;
	case State_Paused:
		gameController.RenderPaused();
		break;
	case State_GameOver:
		gameController.RenderGameOver();
		break;
	}
	gameController.renderFrameRate();
	gameController.renderToScreen();
}
void Shutdown(){
	GameClass::gameConsole.clearBuffer();
}
void ResetGame(){
	curLevel = 0;
	gameController.SetGameState(State_Menu);

	gameController.InGameTime = 0.0;
	gameController.elapsedTime = 0.0;
	gameController.deltaTime = 0.0;
	//Dafault Position
	playerChar.gameChar.playerPos.X = 14;
	playerChar.gameChar.playerPos.Y = 57;
	
}
#pragma region GameLogic Functions
void GameClass::MenuLogic(){
	if (KeyBounceTime>elapsedTime){
		return;
	}
	MenuObj.INMenuLogic();
	SetBounceTime(0.11);
}
void GameClass::InGameLogic(){
	if (KeyBounceTime>elapsedTime){
		return;
	}
	//Check If player Paused
	if (keyPressed[Key_Escape]) {
		gameController.SetGameState(State_Paused);
	}
	//DEBUG: Change Level
	if (keyPressed[Key_Space]){
		curLevel++;
	}
	SetBounceTime(0.085);
	playerChar.CharacterMovement();
}
void GameClass::GameOverLogic(){

}
void GameClass::PausedLogic(){
	if (KeyBounceTime>elapsedTime)
	{
		return;
	}
	PauseMenuObj.PausedMenuLogic();
	SetBounceTime(0.11);
}
#pragma endregion

#pragma region RenderFunctions(External)
void GameClass::RenderMenu(){
	MenuObj.INMenuRender();
}
void GameClass::RenderInGame(){
	MapObj.GenerateMap(curLevel);
//	levelGenObj.GenerateLevel(curLevel);//this gets the stage to be generated
	playerChar.GenerateCharacter();
}
void GameClass::RenderPaused(){
	PauseMenuObj.PausedMenuRender();
}
void GameClass::RenderGameOver(){


}
#pragma endregion
#pragma region RenderFunctions(internal)
void GameClass::clearScreen(){
	GameClass::gameConsole.clearBuffer(0x00);
}
void GameClass::renderFrameRate(){
	COORD c;
	// displays the framerate
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(3);
	ss << 1.0 / GameClass::deltaTime << "fps";
	c.X = GameClass::gameConsole.getConsoleSize().X - 9;
	c.Y = 0;
	GameClass::gameConsole.writeToBuffer(c, ss.str());
}
void GameClass::renderToScreen(){
	GameClass::gameConsole.flushBufferToConsole();
}
void GameClass::renderInGameTime(){
	COORD c;
	std::ostringstream ss;
	ss.str("");
	ss << std::fixed << std::setprecision(1);
	ss << GameClass::InGameTime << "secs";
	c.X = 0;
	c.Y = 0;
	GameClass::gameConsole.writeToBuffer(c, ss.str(), 0x80);
}

void SetBounceTime(double delay){
	gameController.KeyBounceTime = gameController.elapsedTime + delay;
}
#pragma endregion