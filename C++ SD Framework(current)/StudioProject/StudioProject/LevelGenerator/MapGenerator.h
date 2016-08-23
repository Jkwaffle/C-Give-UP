#pragma once
#include <vector>
#include <windows.h>
#include "../BlockClasses/BlockFunctions.h"

using std::vector;
using std::string;
struct wallInfo{
	COORD pos;
	dir direction = dir_None;
	COORD teleTarget;

};

class MapGenerator 
{
public:
	void GenerateMap(int lvlIndex);

	void GenerateMenu(char index);

	void BufferMap(std::string Stage,bool inGame = true);
	static vector<COORD> wallpos(string Stage);
	static vector<COORD> dangerwallpos(string Stage);
	static vector<wallInfo> boostWalls(string Stage);
	static vector<wallInfo> teleportBlocks(string stgae);










	static COORD nextlevel();
};

