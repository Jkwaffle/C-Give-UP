#include "GameClass.h"
#include "PlayerClass.h"
#include "Framework\console.h"

#include <iostream>
#include <iomanip>
#include <sstream>

//Time passed
double elapsedTime;
double deltaTime;
bool keyPressed[Key_None];

// Game Var Here
PlayerClass playerChar;		
GameState curGameState = State_Menu;
//Prevents Key bouncing
double KeyBounceTime;		

Console gameConsole(120, 60, "Give Up: Console ver");	//Creates the console(sizeX,sizeY,Title)


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
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
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
	if (keyPressed[Key_Space]){
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
	}
	renderElapsedTime();
	renderFrameRate();
	renderToScreen();
}
//Functions used in Render
#pragma region RenderRegion 
void RenderMenu(){
	COORD c;

	c.X = 20;
	c.Y = 0;
	std::ostringstream ss;
	ss << "Render Menu Selected";

	gameConsole.writeToBuffer(c, ss.str());
	
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
	COORD c;

	c.X = 20;
	c.Y = 0;
	std::ostringstream ss;
	ss << "Render GameOver Selected";

	gameConsole.writeToBuffer(c, ss.str());

}
void RenderPaused(){
	COORD c;

	c.X = 20;
	c.Y = 0;
	std::ostringstream ss;
	ss << "Render Paused Selected";

	gameConsole.writeToBuffer(c, ss.str());

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
	gameConsole.writeToBuffer(c, ss.str(), 0x0f);
}
void clearScreen(){
	//Clear screen with black
	gameConsole.clearBuffer(0x00);
}


#pragma endregion RenderRegion
//End of Render functions


