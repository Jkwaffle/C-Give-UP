#pragma once
enum MenuState {
	MenuState_Credits,
	MenuState_Quit,
	MenuState_StartGame
};
class MenuController
{
public:
	MenuController();
	MenuState curMenuState;
	void INMenuLogic();
	void INMenuRender();

private:
	void StartGameSelectLogic();
	void CreditsSelectLogic();
	void QuitSelectLogic();

	void StartGameSelectRender();
	void CreditsSelectRender();
	void QuitSelectRender();
	void GameOverRender();
};

