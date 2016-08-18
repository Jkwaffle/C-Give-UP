#include "MenuController.h"
#include "GameClass.h"

//GameClass GameClassObj;
MenuState curMenuState;

MenuController::MenuController(){
	curMenuState = MenuState_StartGame;

}
/*
void MenuLogic(){

	switch (curMenuState){
	case MenuState_StartGame:
	//	StartGameLogic();
		break;
	case MenuState_Credits:
	//	CreditsLogic();
		break;
	case MenuState_Quit:
	//	QuitLogic();
		break;

	}
}
void StartGameLogic(){
	//Navigation and change GameclassObj.curGameState to State_InGame
}
void CreditsLogic(){
	//Navigation and change GameclassObj.curGameState to State_Credits
}
void QuitLogic(){
	//Navigation and change main.cpp exit Game to true
}
*/