#include "LevelController.h"
#include "MapGenerator.h"
#include <iostream>
#include <string>
using namespace std;

void LevelController::GenerateLevel(int Index){

	switch (Index){
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