#include "PausedMenuController.h"
#include "../GameController/GameClass.h"

PausedMenuController::PausedMenuController() {
	curPauseState = PauseState_Continue;
}

	extern GameClass gameController;
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
	if (GameClass::keyPressed[Key_Space]) {
		gameController.SetGameState(State_InGame);
	}
	//if (GameClass::keyPressed[Key_Escape]) {
	//	gameController.SetGameState(State_InGame);
	//}
}
void PausedMenuController::QuitSelectLogic() {
	//When the current state is at Quit(logic)
	if (GameClass::keyPressed[Key_Down]) {
		curPauseState = PauseState_Continue;
	}
	if (GameClass::keyPressed[Key_Up]) {
		curPauseState = PauseState_Continue;
	}
	if (GameClass::keyPressed[Key_Space]) {
		if (gameController.curLevel <= 20){
			gameController.isLost = true;
			gameController.SetGameState(State_GameOver);
		}
		ResetGame();
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
