#include "GameClass.h"
#include "PlayerClass.h"
#include "Framework\console.h"

#include <iostream>
#include <iomanip>
#include <sstream>

double elapsedTime;
double deltaTime;
bool keyPressed[Key_None];

// Game Var Here
PlayerClass playerChar;
GameState curGameState = State_Menu;
double KeyBounceTime;		//Prevents Key bouncing

Console gameConsole(120, 30, "Give Up: Console ver");	//Creates the console(sizeX,sizeY,Title)(SIZE MAY CAUSE ISSUES)


//Init(): Function that initialize all necessary variables
void Init(){
	elapsedTime = 0.0;		//Time passed
	KeyBounceTime = 0.0;
	curGameState = State_Menu;

	//Set player pos at bottom right
	playerChar.playerPos.X = 3;
	playerChar.playerPos.Y = gameConsole.getMaxConsoleSize().Y - 3;
	playerChar.isActive = false;

}

//Shutdown(): Clear memory before exiting
void ShutDown(){
	//not sure if necessary
	//colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	gameConsole.clearBuffer();
}

//void getInput(): Gets player input. Use keyPressed[Key_Up] to check key status
void getInput(){
	keyPressed[Key_Up] = isKeyPressed(VK_UP);
	keyPressed[Key_Down] = isKeyPressed(VK_DOWN);
	keyPressed[Key_Left] = isKeyPressed(VK_LEFT);
	keyPressed[Key_Right] = isKeyPressed(VK_RIGHT);
	keyPressed[Key_Escape] = isKeyPressed(VK_ESCAPE);
	keyPressed[Key_Space] = isKeyPressed(VK_SPACE);
}

//Main Update Loop
void Update(double dTime){
	elapsedTime += dTime;	//Time passed
	deltaTime = dTime;		//Used to Render later

	switch (curGameState)
	{
	case State_Menu:
		MenuLogic();
		break;
	case State_InGame:
		InGameLogic();
		break;
	case State_Paused:
		PausedLogic();
		break;
	case State_GameOver:
		GameOverLogic();
		break;
	case S_CREDITS: creditsLogic();
		break;
	case S_VICTORY: victoryLogic();
		break;
	}
}
#pragma region LogicRegion
void MenuLogic(){
	if (KeyBounceTime > elapsedTime){
		return;
	}

 	if (keyPressed[Key_Space]){
		SetBounceTime(0.5);
		curGameState = State_InGame;
	}
}
void InGameLogic(){
	if (KeyBounceTime > elapsedTime){
		return;
	}
	if (keyPressed[Key_Escape]){
		curGameState = State_Paused;
		SetBounceTime(0.5);
	}
}
void PausedLogic(){
	if (KeyBounceTime > elapsedTime){
		return;
	}
	if (keyPressed[Key_Space]){
		curGameState = State_GameOver;
		SetBounceTime(0.5);
	}
}
void GameOverLogic(){
	if (KeyBounceTime > elapsedTime){
		return;
	}
	if (keyPressed[Key_Space]){
		curGameState = S_CREDITS;
		SetBounceTime(0.5);
	}
}
void creditsLogic() {
	if (KeyBounceTime > elapsedTime) {
		return;
	}
	if (keyPressed[Key_Space]) {
		curGameState = S_VICTORY;
		SetBounceTime(0.5);
	}
}
void victoryLogic() {
	if (KeyBounceTime > elapsedTime) {
		return;
	}
	if (keyPressed[Key_Space]) {
		curGameState = State_Menu;
		SetBounceTime(0.5);
	}
}
void SetBounceTime(float delay){
	KeyBounceTime = elapsedTime + delay;
}
#pragma endregion 
void Render(){
	clearScreen();

	switch (curGameState)
	{
	case State_Menu:
		RenderMenu();
		break;
	case State_InGame:
		RenderMap();
		RenderCharacter();
		break;
	case State_Paused:
		RenderPaused();
		break;
	case State_GameOver:
		RenderGameOver();
		break;
	case S_CREDITS: rendercredits();
		break;
	case S_VICTORY: rendervictory();
		break;
	}
	renderElapsedTime();
	renderFrameRate();
	renderToScreen();
}
//Functions used in Render
#pragma region RenderRegion 
void RenderMenu(){
	COORD c = gameConsole.getConsoleSize();
	c.Y /= 3;
	c.X = c.X / 2 - 9;
	gameConsole.writeToBuffer(c, "GIVE UP", 0x03);
	c.Y += 1;
	c.X = gameConsole.getConsoleSize().X / 2 - 20;
	gameConsole.writeToBuffer(c, "Press <Space> to interact", 0x03);
	c.Y += 1;
	c.X = gameConsole.getConsoleSize().X / 2 - 9;
	gameConsole.writeToBuffer(c, "Press 'Esc' to go menu", 0x03);
}
void RenderCharacter(){
	COORD c;

	c.X = 20;
	c.Y = 0;
	std::ostringstream ss;
	ss << "Render Character/Map Selected";

	gameConsole.writeToBuffer(c, ss.str());

}
void RenderMap(){
	COORD c;

	c.X = 20;
	c.Y = 0;
	std::ostringstream ss;
	ss << "Render Map Selected";

	gameConsole.writeToBuffer(c, ss.str());

}
void RenderGameOver(){
	COORD c = gameConsole.getConsoleSize();
	c.Y /= 3;
	c.X = c.X / 2 - 9;
	gameConsole.writeToBuffer(c, "Game Over", 0x03);
	c.Y += 5;
	c.X = gameConsole.getConsoleSize().X / 2 - 9;
	gameConsole.writeToBuffer(c, "You Finally Gave UP", 0x03);
	c.Y += 1;
	c.X = gameConsole.getConsoleSize().X / 2 - 9;
	gameConsole.writeToBuffer(c, "your death count?", 0x03);

}
void RenderPaused(){
	COORD c = gameConsole.getConsoleSize();
	c.Y /= 3;
	c.X = c.X / 2 - 9;
	gameConsole.writeToBuffer(c, "Pause", 0x03);
	c.Y += 5;
	c.X = gameConsole.getConsoleSize().X / 2 - 9;
	gameConsole.writeToBuffer(c, "Continue", 0x03);
	c.Y += 1;
	c.X = gameConsole.getConsoleSize().X / 2 - 9;
	gameConsole.writeToBuffer(c, "Quit", 0x03);

}

void renderToScreen(){
	gameConsole.flushBufferToConsole();
}
void renderFrameRate(){
	COORD c;
	// displays the framerate
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(3);
	ss << 1.0 / deltaTime << "fps";
	c.X = gameConsole.getConsoleSize().X - 9;
	c.Y = 0;
	gameConsole.writeToBuffer(c, ss.str());
}
void renderElapsedTime(){
	COORD c;
	std::ostringstream ss;
	// displays the elapsed time
	ss.str("");
	ss << elapsedTime << "secs";
	c.X = 0;
	c.Y = 0;
	gameConsole.writeToBuffer(c, ss.str(), 0x59);
}
void clearScreen(){
	//Clear screen with black
	gameConsole.clearBuffer(0x1F);
}

void rendercredits() 
{
	COORD c = gameConsole.getConsoleSize();
	c.Y /= 3;
	c.X = c.X / 2 - 9;
	gameConsole.writeToBuffer(c, "Credits", 0x03);
	c.Y += 5;
	c.X = gameConsole.getConsoleSize().X / 2 - 9;
	gameConsole.writeToBuffer(c, "blah", 0x03);
	c.Y += 1;
	c.X = gameConsole.getConsoleSize().X / 2 - 9;
	gameConsole.writeToBuffer(c, "blah", 0x03);
}


void rendervictory()  
{
	COORD c = gameConsole.getConsoleSize();
	c.Y /= 3;
	c.X = c.X / 2 - 9;
	gameConsole.writeToBuffer(c, "YOU WON?!?!", 0x03);
	c.Y += 5;
	c.X = gameConsole.getConsoleSize().X / 2 - 9;
	gameConsole.writeToBuffer(c, "CONGRATS", 0x03);
	c.Y += 1;
	c.X = gameConsole.getConsoleSize().X / 2 - 9;
	gameConsole.writeToBuffer(c, "your death count?", 0x03);
}

#pragma endregion RenderRegion
//End of Render functions


