#pragma once
#include "MapGenerator.h"

class LevelController : MapGenerator
{
public:
	int curLevel;
	void GenerateLevel(int Index = 0);
	
};

