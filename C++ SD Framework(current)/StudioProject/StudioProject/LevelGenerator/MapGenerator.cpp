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
//this is the location of the goal to reach next level


//Gets Level to make map
COORD MapGenerator::nextlevel() {

	COORD temp;
	temp.X = 102;
	temp.Y = 57;

	return temp;
}

//Gets Level to make map
void MapGenerator::GenerateMap(int lvlIndex) {
	switch (lvlIndex) {

	case 0:
		MapGenerator::BufferMap("map/STAGE01.txt");
		MapGenerator::wallpos("map/STAGE01.txt");
		//return "map/STAGE01.txt";
		break;
	case 1:
		MapGenerator::BufferMap("map/STAGE02.txt");
		MapGenerator::wallpos("map/STAGE02.txt");
		//return "map/STAGE02.txt";
		break;
	case 2:
		MapGenerator::BufferMap("map/STAGE03.txt");
		MapGenerator::wallpos("map/STAGE03.txt");
		//return"map/STAGE03.txt";
		break;
	default:
		MapGenerator::BufferMap("error");
		//return"error";
		break;
	}
}

void MapGenerator::GenerateMenu(char index) {
	switch (index) {

	case 's':				//Start
		MapGenerator::BufferMap("Text/Menu-start.txt", false);
		break;
	case 'c':				//Credits
		MapGenerator::BufferMap("Text/Menu-credits.txt", false);
		break;
	case 'q':				//quit
		MapGenerator::BufferMap("Text/Menu-quit.txt", false);
		break;
	case 'o':				//Over
		MapGenerator::BufferMap("Text/You Gaveup.txt", false);
		break;
	default:
		MapGenerator::BufferMap("error");
		//return"error";
		break;
	}
}

// Saves wall positions
vector<COORD> MapGenerator::wallpos(std::string Stage) {
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
			if (level[j][i] == 'x')//stores position of wall
			{
				COORD temp_wall;
				temp_wall.X = i + 13;
				temp_wall.Y = j + 23;
				temp.push_back(temp_wall);
			}
		}
	}
	return temp;
}
//saves danger wall position

vector<wallInfo> MapGenerator::boostWalls(string Stage){
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
	vector<wallInfo> temp;
	COORD disp;//positions the map
	disp.X = 13;
	disp.Y = 23;
	temp.clear();

	for (int j = 0; j < HEIGHT; j++)
	{
		for (int i = 0; i < WIDTH; i++)
		{//OPTIMIZE: Do switch case instead
			if (level[j][i] == '>')//store Info for boost
			{
				wallInfo temp_boost;
				temp_boost.pos.X = i + 13;
				temp_boost.pos.Y = j + 23;
				temp_boost.direction = dir_Right;
				temp.push_back(temp_boost);
			}
			else if (level[j][i] == '<')//store Info for boost
			{
				wallInfo temp_boost;


				temp_boost.pos.X = i + 13;
				temp_boost.pos.Y = j + 23;
				temp_boost.direction = dir_Left;

				temp.push_back(temp_boost);
			}
			else if (level[j][i] == '^')//store Info for boost
			{
				wallInfo temp_boost;


				temp_boost.pos.X = i + 13;
				temp_boost.pos.Y = j + 23;
				temp_boost.direction = dir_Up;

				temp.push_back(temp_boost);
			}
			else if (level[j][i] == 'v')//store Info for boost
			{
				wallInfo temp_boost;


				temp_boost.pos.X = i + 13;
				temp_boost.pos.Y = j + 23;
				temp_boost.direction = dir_Down;

				temp.push_back(temp_boost);
			}
		}
	}
	return temp;


}
vector<COORD> MapGenerator::dangerwallpos(std::string Stage){
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
			if (level[j][i] == 'w')//store position of danger wall
			{
				COORD temp_dangerwall;
				temp_dangerwall.X = i + 13;
				temp_dangerwall.Y = j + 23;
				temp.push_back(temp_dangerwall);
			}
		}
	}
	return temp;
}


vector<wallInfo> MapGenerator::teleportBlocks(std::string Stage) {
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
	vector<wallInfo> temp;
	COORD disp;//positions the map
	disp.X = 13;
	disp.Y = 23;
	temp.clear();
	wallInfo temp_teleBlocks;
	for (int j = 0; j < HEIGHT; j++)
	{
		for (int i = 0; i < WIDTH; i++)
		{
			if (level[j][i] == 't')//stores position of wall
			{
				temp_teleBlocks.pos.X = i + 13;
				temp_teleBlocks.pos.Y = j + 23;
			}
			if (level[j][i] == 'T')
			{
				temp_teleBlocks.teleTarget.X = i + 13;
				temp_teleBlocks.teleTarget.Y = j + 23;
			}
		}
	}
	temp.push_back(temp_teleBlocks);
	return temp;
}

//Creates Map

void MapGenerator::BufferMap(std::string Stage, bool inGame) {
	COORD disp;//positions the map
	COORD c;
	if (inGame){
		disp.X = 13;
		disp.Y = 23;
	}
	else {
		disp.X = 14;
		disp.Y = 10;
	}
	ifstream file;
	file.open(Stage);

	if (file.is_open())//this gets the individual char in map and stores them in a 2d array
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
			if (inGame){
				if (level[j][i] == '.')//the floor
				{
					GameClass::gameConsole.writeToBuffer(c, ' ');
				}
				else if (level[j][i] == 'p')//to next level
				{
					GameClass::gameConsole.writeToBuffer(c, 'p');
				}
				else if (level[j][i] == 'w')//danger wall(have collision)
				{
					GameClass::gameConsole.writeToBuffer(c, ' ', 0x4D);
				}
				else if (level[j][i] == 's')//safe wall
				{
					GameClass::gameConsole.writeToBuffer(c, ' ', 0x3C);
				}
				else if (level[j][i] == 'x')//normal wall(have collision)
				{
					GameClass::gameConsole.writeToBuffer(c, ' ', 0x2B);
				}

				else if (level[j][i] == '>')//store Info for boost
				{
					GameClass::gameConsole.writeToBuffer(c, '>', 0x3C);
				}
				else if (level[j][i] == '<')//store Info for boost
				{
					GameClass::gameConsole.writeToBuffer(c, '<', 0x3C);
				}
				else if (level[j][i] == '^')//store Info for boost
				{
					GameClass::gameConsole.writeToBuffer(c, '^', 0x3C);
				}
				else if (level[j][i] == 'v')//store Info for boost
				{
					GameClass::gameConsole.writeToBuffer(c, 'V', 0x3C);
				}
				else if (level[j][i] == 't')//store Info for boost
				{
					GameClass::gameConsole.writeToBuffer(c, ' ', 0x6F);
				}
				else if (level[j][i] == 'T')//store Info for boost
				{
					GameClass::gameConsole.writeToBuffer(c, ' ', 0x5E);
				}





			}
			else{	//For Menu
				if (level[j][i] == '.')//the floor
				{
					GameClass::gameConsole.writeToBuffer(c, ' ');
				}
				else if (level[j][i] == 'x')//normal wall(have collision)
				{
					GameClass::gameConsole.writeToBuffer(c, ' ', 0x2B);
				}
				else {
					GameClass::gameConsole.writeToBuffer(c, level[j][i]);
				}
			}
		}
	}
}


