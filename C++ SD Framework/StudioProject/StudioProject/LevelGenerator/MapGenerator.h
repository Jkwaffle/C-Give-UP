#pragma once
#include <vector>
#include <windows.h>

using std::vector;

class MapGenerator 
{
public:
	void GenerateMap(int lvlIndex);


	void BufferMap(std::string Stage);
	static vector<COORD> wallpos(std::string Stage);
	static COORD nextlevel();
};

