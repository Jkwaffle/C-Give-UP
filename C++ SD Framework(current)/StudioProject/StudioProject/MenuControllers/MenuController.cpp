#include "../MenuControllers/MenuController.h"
#include "../GameController/GameClass.h"
#include "../LevelGenerator/MapGenerator.h"

//GameClass GameClassObj;

MenuController::MenuController() {
	curMenuState = MenuState_StartGame;
}
//added
MapGenerator mapGenRef;
extern GameClass gameController;
extern bool exitGame;
//Get Keypress
//	GameClass::gameConsole.writeToBuffer()

void MenuController::INMenuLogic() {

	switch (MenuController::curMenuState)
	{
	case MenuState_StartGame:
		MenuController::StartGameSelectLogic();
		break;
	case MenuState_Credits:
		MenuController::CreditsSelectLogic();
		break;
	case MenuState_Quit:
		MenuController::QuitSelectLogic();
		break;
	}
	//Check Current State/ Overall logic
}
void MenuController::INMenuRender() {

	switch (MenuController::curMenuState)
	{
	case MenuState_StartGame:
		MenuController::StartGameSelectRender();
		break;
	case MenuState_Credits:
		MenuController::CreditsSelectRender();
		break;
	case MenuState_Quit:
		MenuController::QuitSelectRender();
		break;
	}
}
//LOGIC
void MenuController::StartGameSelectLogic() {
	//When the current state is at Continue(logic)
	if (GameClass::keyPressed[Key_Up]) {
		curMenuState = MenuState_Quit;
	}
	if (GameClass::keyPressed[Key_Down]) {
		curMenuState = MenuState_Credits;
	}
	if (GameClass::keyPressed[Key_Space]) {
		gameController.SetGameState(State_InGame);
	}
}
void MenuController::CreditsSelectLogic() {
	//When the current state is at Quit(logic)
	if (GameClass::keyPressed[Key_Up]) {
		curMenuState = MenuState_StartGame;
	}
	if (GameClass::keyPressed[Key_Down]) {
		curMenuState = MenuState_Quit;
	}
	if (GameClass::keyPressed[Key_Space]) {
		//	gameController.SetGameState(State_Credits);
	}
}
void MenuController::QuitSelectLogic() {
	//When the current state is at Quit(logic)
	if (GameClass::keyPressed[Key_Up]) {
		curMenuState = MenuState_Credits;
	}
	if (GameClass::keyPressed[Key_Down]) {
		curMenuState = MenuState_StartGame;
	}
	if (GameClass::keyPressed[Key_Space]) {
		exitGame = true;
	}
}
//RENDER
void MenuController::StartGameSelectRender() {
	mapGenRef.GenerateMenu('s');
}
void MenuController::CreditsSelectRender() {
	mapGenRef.GenerateMenu('c');
}
void MenuController::QuitSelectRender() {
	mapGenRef.GenerateMenu('q');
}
void MenuController::GameOverRender() {
	mapGenRef.GenerateMenu('o');
}