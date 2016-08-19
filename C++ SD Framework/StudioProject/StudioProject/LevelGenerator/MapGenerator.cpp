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
 //getting position of walls

MapGenerator MapGenRef;

 vector<COORD> MapGenerator::wallpos(std::string Stage){

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

	vector<COORD> temp;
	COORD disp;//positions the map
	disp.X = 13;
	disp.Y = 23;
	temp.clear();

	for (int j = 0; j < HEIGHT; j++)
	{
		for (int i = 0; i < WIDTH; i++)
		{
			 if (level[j][i] == 'x')
				{
					
					COORD temp_wall;
					temp_wall.X = i + 13;
					temp_wall.Y = j + 23;

					temp.push_back(temp_wall);

					//wallpos.push_back(temp_wall);
					//CollisionManager::collisionHolder.push_back(temp_wall);
			}
		}
	}
	return temp;
}

void MapGenerator::BufferMap(std::string Stage){
	GameClass gameController;
	COORD disp;//positions the map
	COORD c;
	
	disp.X = 13;
	disp.Y = 23;

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
		c.Y = j + disp.Y;
		for (int i = 0; i < WIDTH; i++)
		{
			c.X = i + disp.X;
			if (level[j][i] == '.')
			{
				GameClass::gameConsole.writeToBuffer(c, ' ');
			}
			else if (level[j][i] == '>')
			{
				gameController.AddLevel();
				GameClass::gameConsole.writeToBuffer(c, '>');
			}
			else if (level[j][i] == 'w')
			{
				GameClass::gameConsole.writeToBuffer(c, ' ', 0x4D);
			}
			else if (level[j][i] == 'x')
			{
				GameClass::gameConsole.writeToBuffer(c, ' ', 0x2B);
			}
		}
	}
}

