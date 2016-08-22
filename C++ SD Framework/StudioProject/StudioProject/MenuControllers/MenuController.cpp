#include "../MenuControllers/MenuController.h"
#include "../GameController/GameClass.h"

//GameClass GameClassObj;

MenuController::MenuController() {
	curMenuState = MenuState_StartGame;

}
//added
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
	// When the current state is at Continue(Render)
	COORD c = GameClass::gameConsole.getConsoleSize();
	c.Y /= 4;
	c.X = c.X / 2 - 20;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, " XX  XXX X   X XXX     X  X XXX ", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, "X     X  X   X X       X  X X  X", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, "X XX  X   X X  XXX     X  X XXX ", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, "X  X  X   X X  X       X  X X   ", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, " XX  XXX   X   XXX      XX  X", 0x03);
	c.Y += 5;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, ">Start Game<", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, "Credit", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, "Quit", 0x03);
}
void MenuController::CreditsSelectRender() {
	// When the current state is at Quit(Render)
	COORD c = GameClass::gameConsole.getConsoleSize();
	c.Y /= 4;
	c.X = c.X / 2 - 9;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, " XX  XXX X   X XXX     X  X XXX ", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, "X     X  X   X X       X  X X  X", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, "X XX  X   X X  XXX     X  X XXX ", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, "X  X  X   X X  X       X  X X   ", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, " XX  XXX   X   XXX      XX  X", 0x03);
	c.Y += 5;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, "Start Game", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, ">Credit<", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, "Quit", 0x03);

}
void MenuController::QuitSelectRender() {
	COORD c = GameClass::gameConsole.getConsoleSize();
	c.Y /= 4;
	c.X = c.X / 2 - 9;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, " XX  XXX X   X XXX     X  X XXX ", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, "X     X  X   X X       X  X X  X", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, "X XX  X   X X  XXX     X  X XXX ", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, "X  X  X   X X  X       X  X X   ", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, " XX  XXX   X   XXX      XX  X", 0x03);
	c.Y += 5;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, "Start Game", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, "Credit", 0x03);
	c.Y += 1;
	c.X = GameClass::gameConsole.getConsoleSize().X / 2 - 20;
	GameClass::gameConsole.writeToBuffer(c, ">Quit<", 0x03);
}