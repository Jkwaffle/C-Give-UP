#pragma once
#include <vector>
#include <windows.h>

using std::vector;
using std::string;

class MapGenerator 
{
public:
	void GenerateMap(int lvlIndex);
//----------------------------------
	void GenerateMenu(char index);
//----------------------------------
	void BufferMap(std::string Stage,bool inGame = true);
	static vector<COORD> wallpos(std::string Stage);
	static vector<COORD> dangerwallpos(std::string Stage);
	static COORD nextlevel();
};

