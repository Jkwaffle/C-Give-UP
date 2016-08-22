#pragma once
#include <vector>
#include <windows.h>

using std::vector;
using std::string;

class MapGenerator 
{
public:
	void GenerateMap(int lvlIndex);
	void GenerateMenu(string index);
	void BufferMap(std::string Stage);
	static vector<COORD> wallpos(std::string Stage);
	static COORD nextlevel();
};

