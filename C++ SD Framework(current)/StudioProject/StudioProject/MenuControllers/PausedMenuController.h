#pragma once
enum pauseStates {
	PauseState_Continue,
	PauseState_Quit,
};

class PausedMenuController
{

public:
	PausedMenuController();
	pauseStates curPauseState;
	void PausedMenuLogic();
	void PausedMenuRender();
	//	GameState curGamestate();
private:
	void ContinueSelectLogic();
	void QuitSelectLogic();

	void ContinueSelectRender();
	void QuitSelectRender();
};