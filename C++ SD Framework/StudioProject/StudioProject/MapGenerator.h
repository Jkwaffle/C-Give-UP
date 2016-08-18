#pragma once
#include "LevelController.h"
using std::vector;

class MapGenerator : LevelController
{
public:
	void BufferMap(COORD c, std::string Stage);
	vector<COORD> wallpos;


private:

	
};

