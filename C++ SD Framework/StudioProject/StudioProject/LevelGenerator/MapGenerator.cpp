#include "MapGenerator.h"
#include "../GameController/GameClass.h"
#include <windows.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
static const int WIDTH = 90;
static const int HEIGHT = 36;//map size
char level[HEIGHT][WIDTH];
//vector<COORD> wallpos;//getting position of walls


void MapGenerator::BufferMap(std::string Stage){
	GameClass gameController;
	COORD c;

	ifstream file;
	file.open(Stage);

	if (file.is_open())
	{
		while (file.good())
		{
			for (int y = 0; y < HEIGHT; y++)
			{
				for (int x = 0; x < WIDTH; x++)
				{
					file >> level[y][x];
				}
			}
		}

	}

	file.close();

	for (int j = 0; j < HEIGHT; j++)
	{
		c.Y = j + 1;
		for (int i = 0; i < WIDTH; i++)
		{
			c.X = i;
			if (level[j][i] == '.')
			{
				GameClass::gameConsole.writeToBuffer(c, ' ');
			}
			else if (level[j][i] == '>')
			{
				//gameController.AddLevel();
				GameClass::gameConsole.writeToBuffer(c, '>');
			}
			else if (level[j][i] == 'x')
			{
				COORD temp_wall;
				temp_wall.X = i;
				temp_wall.Y = j + 1;
				MapGenerator::wallpos.push_back(temp_wall);
				GameClass::gameConsole.writeToBuffer(c, ' ', 0x2B);
			}
		}
	}
}


