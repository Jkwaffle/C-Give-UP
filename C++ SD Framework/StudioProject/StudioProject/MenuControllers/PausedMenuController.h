#pragma once
enum pauseStates {
	PauseState_Continue,
	PauseState_Quit,
};

class PausedMenuController {
	PausedMenuController();
public :
	
	pauseStates curPauseState;
	void PausedMenuLogic();
	void PausedMenuRender();

private:
	void ContinueSelectLogic();
	void QuitSelectLogic();

	void ContinueSelectRender();
	void QuitSelectRender();
};


//#pragma once
//#include "GameClass.h"
//
//
//
//enum PausedStates {
//	PauseState_Continue,
//	PausedState_Quit,
//};
//class PausedMenuController : GameClass
//{
//public:
//	PausedMenuController();
//	void PausedMenuLogic();
//	void PausedMenuRender();
//private:
//	
//	void ContinueLogic();
//	void QuitLogic();
//
//	void ContinueRender();
//	void QuitRender();
//	GameClass GameController;
//
//	
//};
//
