#pragma once
enum AfterGameState{
	afterState_GiveUp,
	afterState_Complete,
	afterState_None
};

class GameOverController
{
public:
	GameOverController();

	AfterGameState gameOverState;
	void GameOverLogic();
	void GameOverRender();

private:
	void GiveUpLogic();
	void CompleteLogic();

	void CompleteRender();
	void GiveUpRender();

};