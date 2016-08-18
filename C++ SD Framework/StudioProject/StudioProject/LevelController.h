#pragma once
#include "GameClass.h"
class LevelController : GameClass
{
public:
	int levelIndex = 0;
	std::string GenerateLevelIndex(int Index = 0);

private:
	 GameClass gameController;
	
};

