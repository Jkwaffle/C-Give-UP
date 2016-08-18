#pragma once
#include <vector>
#include<windows.h>
using std::vector;
class MapGenerator 
{
public:
	void BufferMap(std::string Stage);
	vector<COORD> wallpos;

};

