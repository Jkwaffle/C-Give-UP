#include "GameClass.h"
#include "PlayerClass.h"
#include "Framework\console.h"
#include "PausedMenuController.h"
#include "MapGenerator.h"
#include "LevelController.h"

#include <iostream>
#include <iomanip>
#include <sstream>


#pragma region InitVar
//----------------------------------
MapGenerator MapGenObj;
LevelController levelselect;
//----------------------------------
double GameClass::elapsedTime;
double GameClass::deltaTime;
bool GameClass::keyPressed[Key_None];

GameState GameClass::curGameState;
double GameClass::KeyBounceTime;		//Prevents Key bouncing

Console GameClass::gameConsole(120, 60, "Give Up: Console ver!!");	//Creates the console(sizeX,sizeY,Title)(SIZE MAY CAUSE ISSUES)


#pragma endregion 
//Init(): Function that initialize all necessary variables
PausedMenuController PausedMenuObj;
void Init(){
	GameClass::elapsedTime = 0.0;		//Time passed
	GameClass::KeyBounceTime = 0.0;
	GameClass::curGameState = State_Menu;
}

//Shutdown(): Clear memory before exiting
void ShutDown(){
	GameClass::gameConsole.clearBuffer();
}

//void getInput(): Gets player input. Use keyPressed[Key_Up] to check key status
void getInput(){
	GameClass::keyPressed[Key_Up] = isKeyPressed(VK_UP);
	GameClass::keyPressed[Key_Down] = isKeyPressed(VK_DOWN);
	GameClass::keyPressed[Key_Left] = isKeyPressed(VK_LEFT);
	GameClass::keyPressed[Key_Right] = isKeyPressed(VK_RIGHT);
	GameClass::keyPressed[Key_Escape] = isKeyPressed(VK_ESCAPE);
	GameClass::keyPressed[Key_Space] = isKeyPressed(VK_SPACE);
}

//Main Update Loop
void Update(double dTime){
	GameClass::elapsedTime += dTime;	//Time passed
	GameClass::deltaTime = dTime;		//Used to Render later
	switch (GameClass::curGameState)
	{
	case State_Menu:
		MenuLogic();
		break;
	case State_InGame:
		InGameLogic();
		break;
	case State_Paused:
		PausedMenuObj.PausedMenuLogic();
		//PausedLogic();
		break;
	case State_GameOver:
		GameOverLogic();
		break;
	case S_CREDITS: 
		creditsLogic();
		break;
	case S_VICTORY: 
		victoryLogic();
		break;
	}
}
#pragma region LogicRegion
void MenuLogic(){
	if (GameClass::KeyBounceTime > GameClass::elapsedTime){
		return;
	}
	if (GameClass::keyPressed[Key_Space]){
		SetBounceTime(0.5);
		GameClass::curGameState = State_InGame;
	}
}
void InGameLogic(){
	if (GameClass::KeyBounceTime >GameClass::elapsedTime){
		return;
	}
	if (GameClass::keyPressed[Key_Escape]){
		GameClass::curGameState = State_Paused;
		SetBounceTime(0.5);
	}
}

void GameOverLogic(){
	if (GameClass::KeyBounceTime > GameClass::elapsedTime){
		return;
	}
	if (GameClass::keyPressed[Key_Space]){
		GameClass::curGameState = S_CREDITS;
		SetBounceTime(0.5);
	}
}
void creditsLogic() {
	if (GameClass::KeyBounceTime > GameClass::elapsedTime) {
		return;
	}
	if (GameClass::keyPressed[Key_Space]) {
		GameClass::curGameState = S_VICTORY;
		SetBounceTime(0.5);
	}
}
void victoryLogic() {
	if (GameClass::KeyBounceTime > GameClass::elapsedTime) {
		return;
	}
	if (GameClass::keyPressed[Key_Space]) {
		GameClass::curGameState = State_Menu;
		SetBounceTime(0.5);
	}
}
void SetBounceTime(float delay){
	GameClass::KeyBounceTime = GameClass::elapsedTime + delay;
}
#pragma endregion 
void Render(){
	clearScreen();
	
	switch (GameClass::curGameState)
	{
	case State_Menu:
		RenderMenu();
		break;
	case State_InGame:
		RenderMap();
		RenderCharacter();
		break;
	case State_Paused:
		PausedMenuObj.PausedMenuRender();
		//RenderPaused();
		break;
	case State_GameOver:
		RenderGameOver();
		break;
	case S_CREDITS: 
		rendercredits();
		break;
	case S_VICTORY: 
		rendervictory();
		break;
	}
	renderElapsedTime();
	renderFrameRate();
	renderToScreen();
}
//Functions used in Render
#pragma region RenderRegion 
void RenderMenu(){
	COORD c = GameClass::gameConsole.getConsoleSize();
	c.Y /= 3;
	c.X = c.X / 2 - 9;
	GameClass::gameConsole.writeToBuffer(c, "GIVE UP", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, "Press <Space> to interact", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 9;
	GameClass::gameConsole.writeToBuffer(c, "Press 'Esc' to go menu", 0x03);
}
void RenderCharacter(){
	COORD c;

	c.X = 20;
	c.Y = 0;
	std::ostringstream ss;
	ss << "Render Character/Map Selected";

	GameClass::gameConsole.writeToBuffer(c, ss.str());
}
void RenderMap(){
	COORD c;

	c.X = 20;
	c.Y = 0;
	std::ostringstream ss;
	ss << "Render Map Selected";

	GameClass::gameConsole.writeToBuffer(c, ss.str());	
	MapGenObj.BufferMap(levelselect.GenerateLevelIndex(0));
}
void RenderGameOver(){
	COORD c = GameClass::gameConsole.getConsoleSize();
	c.Y /= 3;
	c.X = c.X / 2 - 9;
	GameClass::gameConsole.writeToBuffer(c, "Game Over", 0x03);
	c.Y += 5;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 9;
	GameClass::gameConsole.writeToBuffer(c, "You Finally Gave UP", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 9;
	GameClass::gameConsole.writeToBuffer(c, "your death count?", 0x03);

}
void renderToScreen(){
	GameClass::gameConsole.flushBufferToConsole();
}
void renderFrameRate(){
	COORD c;
	// displays the framerate
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(3);
	ss << 1.0 / GameClass::deltaTime << "fps";
	c.X = GameClass::gameConsole.getConsoleSize().X - 9;
	c.Y = 0;
	GameClass::gameConsole.writeToBuffer(c, ss.str());
}
void renderElapsedTime(){
	COORD c;
	std::ostringstream ss;
	// displays the elapsed time
	ss.str("");
	ss << GameClass::elapsedTime << "secs";
	c.X = 0;
	c.Y = 0;
	GameClass::gameConsole.writeToBuffer(c, ss.str(), 0x59);
}
void clearScreen(){
	//Clear screen with black
	GameClass::gameConsole.clearBuffer(0x1F);
}

void rendercredits() 
{
	COORD c = GameClass::gameConsole.getConsoleSize();
	c.Y /= 3;
	c.X = c.X / 2 - 9;
	GameClass::gameConsole.writeToBuffer(c, "Credits", 0x03);
	c.Y += 5;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 9;
	GameClass::gameConsole.writeToBuffer(c, "blah", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 9;
	GameClass::gameConsole.writeToBuffer(c, "blah", 0x03);
}


void rendervictory()  
{
	COORD c = GameClass::gameConsole.getConsoleSize();
	c.Y /= 3;
	c.X = c.X / 2 - 9;
	GameClass::gameConsole.writeToBuffer(c, "YOU WON?!?!", 0x03);
	c.Y += 5;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 9;
	GameClass::gameConsole.writeToBuffer(c, "CONGRATS", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 9;
	GameClass::gameConsole.writeToBuffer(c, "your death count?", 0x03);
}

#pragma endregion RenderRegion
//End of Render functions


