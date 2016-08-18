#pragma once
#include "GameClass.h"
class LevelController : GameClass
{
public:
	int levelIndex = 0;
private:
	 void GenerateLevelIndex(int levelIndex = 0);
	 GameClass gameController;
	
};

