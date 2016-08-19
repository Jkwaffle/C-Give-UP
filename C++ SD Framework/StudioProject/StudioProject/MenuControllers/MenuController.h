#pragma once
enum MenuState {
	MenuState_Credits,
	MenuState_Quit,
	MenuState_StartGame
};
//void MenuLogic();
//void StartGameLogic();
//void CreditsLogic();
//void QuitLogic();
class MenuController
{
public:
	MenuController();
	MenuState curMenuState;
	void INMenuLogic();
	void INMenuRender();

private:

	//added
	void StartGameSelectLogic();
	void CreditsSelectLogic();
	void QuitSelectLogic();

	void StartGameSelectRender();
	void CreditsSelectRender();
	void QuitSelectRender();
};

