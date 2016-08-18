#include "LevelController.h"
#include <iostream>
#include <string>
using namespace std;

string LevelController::GenerateLevelIndex(int Index){

	switch (Index)
	{
	case 0:
		return "map/STAGE01.txt";
		break;
	case 1:
		return "map/STAGE02.txt";
		break;
	case 2:
		return"map/STAGE03.txt";
		break;
	default:
		return"error";
		break;
	}

}