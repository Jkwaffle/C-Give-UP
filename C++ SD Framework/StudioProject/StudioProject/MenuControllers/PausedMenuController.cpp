#include "PausedMenuController.h"
#include "../GameController/GameClass.h"

PausedMenuController::PausedMenuController() {
	curPauseState = PauseState_Continue;
}

//Get Keypress
//	GameClass::gameConsole.writeToBuffer()

void PausedMenuController::PausedMenuLogic() {

	switch (PausedMenuController::curPauseState)
	{
	case PauseState_Continue:
		PausedMenuController::ContinueSelectLogic();
		break;
	case PauseState_Quit:
		PausedMenuController::QuitSelectLogic();
		break;
	}
	//Check Current State/ Overall logic
}
void PausedMenuController::PausedMenuRender() {

	switch (PausedMenuController::curPauseState)
	{
	case PauseState_Continue:
		PausedMenuController::ContinueSelectRender();
		break;
	case PauseState_Quit:
		PausedMenuController::QuitSelectRender();
		break;
	}
}
//LOGIC
void PausedMenuController::ContinueSelectLogic() {
	//When the current state is at Continue(logic)
	if (GameClass::keyPressed[Key_Down]) {
		curPauseState = PauseState_Quit;
	}
	if (GameClass::keyPressed[Key_Up]) {
		curPauseState = PauseState_Quit;
	}
}
void PausedMenuController::QuitSelectLogic() {
	//When the current state is at Quit(logic)
	if (GameClass::keyPressed[Key_Down]) {
		curPauseState = PauseState_Continue;
	}
	if (GameClass::keyPressed[Key_Up]) {
		curPauseState = PauseState_Continue;
	}
}
//RENDER
void PausedMenuController::ContinueSelectRender() {
	// When the current state is at Continue(Render)
	COORD c = GameClass::gameConsole.getConsoleSize();
	c.Y /= 3;
	c.X = c.X / 2 - 9;
	GameClass::gameConsole.writeToBuffer(c, "Pause", 0x03);
	c.Y += 5;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 9;
	GameClass::gameConsole.writeToBuffer(c, ">Continue<", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 9;
	GameClass::gameConsole.writeToBuffer(c, "Quit", 0x03);

}
void PausedMenuController::QuitSelectRender() {
	// When the current state is at Quit(Render)
	COORD c = GameClass::gameConsole.getConsoleSize();
	c.Y /= 3;
	c.X = c.X / 2 - 9;
	GameClass::gameConsole.writeToBuffer(c, "Pause", 0x03);
	c.Y += 5;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 9;
	GameClass::gameConsole.writeToBuffer(c, "Continue", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 9;
	GameClass::gameConsole.writeToBuffer(c, ">Quit<", 0x03);

}

//#include "PausedMenuController.h"
//#include "GameClass.h"
//#include "Framework\console.h"
//PausedStates curPausedState;
//
//
//PausedMenuController::PausedMenuController()
//{
//	curPausedState = PauseState_Continue;
//}
//void PausedMenuController::PausedMenuLogic(){
//	switch (curPausedState)
//	{
//	case PauseState_Continue:
//		ContinueLogic();
//		break;
//	case PausedState_Quit:
//		QuitLogic();
//		break;
//	}
//}
//void PausedMenuController::PausedMenuRender(){
//	switch (curPausedState)
//	{
//	case PauseState_Continue:
//		ContinueRender();
//		break;
//	case PausedState_Quit:
//		QuitRender();
//		break;
//	}
//}
////Fill In Logics next
//void PausedMenuController::ContinueLogic(){
//	if (GameController.KeyBounceTime > GameController.elapsedTime) {
//		return;
//	}
//
//	if (GameController.keyPressed[Key_Space]){
//		GameController.curGameState = State_InGame;
//		SetBounceTime(0.2f);
//	}
//	if (GameController.keyPressed[Key_Up]){
//		curPausedState = PausedState_Quit;
//		SetBounceTime(0.2f);
//	}
//	if (GameController.keyPressed[Key_Down]){
//		curPausedState = PausedState_Quit;
//		SetBounceTime(0.2f);
//	}
//}
//void PausedMenuController::QuitLogic(){
//	if (GameController.KeyBounceTime > GameController.elapsedTime) {
//		return;
//	}
//	if (GameController.keyPressed[Key_Space]){
//		GameController.curGameState = State_GameOver;
//		SetBounceTime(0.2f);
//	}
//	if (GameController.keyPressed[Key_Up]){
//		curPausedState = PauseState_Continue;
//		SetBounceTime(0.2f);
//	}
//	if (GameController.keyPressed[Key_Down]){
//		curPausedState = PauseState_Continue;
//		SetBounceTime(0.2f);
//	}
//}
//
//void PausedMenuController::ContinueRender(){
////	Console curgameConsole;//New Console
//	//curgameConsole = GameController.gameConsole();
//	COORD c = gameConsole.getConsoleSize();
//	c.Y /= 3;
//	c.X = c.X / 2 - 9;
//	GameController.gameConsole.writeToBuffer(c, "Pause", 0x03);
//	c.Y += 5;
//	c.X = GameController.gameConsole.getConsoleSize().X / 2 - 9;
//	GameController.gameConsole.writeToBuffer(c, ">Continue<", 0x03);
//	c.Y += 1;
//	c.X = GameController.gameConsole.getConsoleSize().X / 2 - 9;
//	GameController.gameConsole.writeToBuffer(c, "Quit", 0x03);
//
//}
//void PausedMenuController::QuitRender(){
//	COORD c = GameController.gameConsole.getConsoleSize();
//	c.Y /= 3;
//	c.X = c.X / 2 - 9;
//	GameController.gameConsole.writeToBuffer(c, "Pause", 0x03);
//	c.Y += 5;
//	c.X = GameController.gameConsole.getConsoleSize().X / 2 - 9;
//	GameController.gameConsole.writeToBuffer(c, "Continue", 0x03);
//	c.Y += 1;
//	c.X = GameController.gameConsole.getConsoleSize().X / 2 - 9;
//	GameController.gameConsole.writeToBuffer(c, ">Quit<", 0x03);
//}
//
