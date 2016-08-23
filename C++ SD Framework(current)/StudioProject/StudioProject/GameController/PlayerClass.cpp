#include "GameClass.h"
#include "../Framework/console.h"
#include "PlayerClass.h"
#include "../LevelGenerator/MapGenerator.h"
#include "../BlockClasses/BlockFunctions.h"

extern MapGenerator MapGenRef;
extern GameClass gameController;

SGameChar gameChar;

PlayerClass::PlayerClass(){
	SetStartingPos();

}
void PlayerClass::SetStartingPos(){
	gameChar.playerPos.X = 14;
	gameChar.playerPos.Y = 57;
}
void PlayerClass::CharacterMovement(){
	std::string stage;

	if (GameClass::keyPressed[Key_Up])
	{
		gameChar.canTele = true;



		gameChar.playerPos.Y--;
		for each(COORD i in  MapGenerator::wallpos(stage)){
			if (i.X == gameChar.playerPos.X && i.Y == gameChar.playerPos.Y){
				gameChar.playerPos.Y++;//checking for collision
			}
		}
	}
	if (GameClass::keyPressed[Key_Left])
	{
		gameChar.canTele = true;

		gameChar.playerPos.X--;
		for each(COORD i in MapGenerator::wallpos(stage)){
			if (i.X == gameChar.playerPos.X && i.Y == gameChar.playerPos.Y){
				gameChar.playerPos.X++;//checking for collision
			}
		}
	}
	if (GameClass::keyPressed[Key_Down])
	{
		gameChar.canTele = true;

		gameChar.playerPos.Y++;
		for each(COORD i in MapGenerator::wallpos(stage)){
			if (i.X == gameChar.playerPos.X && i.Y == gameChar.playerPos.Y){
				gameChar.playerPos.Y--;//checking for collision
			}
		}
	}
	if (GameClass::keyPressed[Key_Right])
	{
		gameChar.canTele = true;

		gameChar.playerPos.X++;
		for each(COORD i in MapGenerator::wallpos(stage)){
			if (i.X == gameChar.playerPos.X && i.Y == gameChar.playerPos.Y){
				gameChar.playerPos.X--;//checking for collision
			}
		}
	}
	//determines if character is at goal and proceed to next level, reset player position
	if (gameChar.playerPos.X == MapGenRef.nextlevel().X && gameChar.playerPos.Y == MapGenRef.nextlevel().Y)
	{
		gameController.AddLevel();
		PlayerClass::SetStartingPos();
	}
	//checks where the danger walls are
	for each(COORD j in MapGenerator::dangerwallpos(stage)){
		if (j.X == gameChar.playerPos.X && j.Y == gameChar.playerPos.Y)
		{
			PlayerClass::CharacterKilled();//returns player to spawn location
		}
	}
	//Check BoostFloors
	for each(wallInfo j in MapGenerator::boostWalls(stage)){
		if (j.pos.X == gameChar.playerPos.X && j.pos.Y == gameChar.playerPos.Y)
		{
			BlockFunctions::boostMovePlayer(j.direction);
		}
	}
	for each(wallInfo j in MapGenerator::teleportBlocks(stage)){
		if (j.pos.X == gameChar.playerPos.X && j.pos.Y == gameChar.playerPos.Y)
		{
			BlockFunctions::teleportPlayer(j.teleTarget,gameChar.canTele);
			gameChar.canTele = false;
		}
		else if (j.teleTarget.X == gameChar.playerPos.X && j.teleTarget.Y == gameChar.playerPos.Y){
			BlockFunctions::teleportPlayer(j.pos, gameChar.canTele);
			gameChar.canTele = false;
		}
	}
}
void PlayerClass::GenerateCharacter(){

	GameClass::gameConsole.writeToBuffer(gameChar.playerPos, (char)1, 11);

}
void PlayerClass::CharacterKilled(){

	PlayerClass::SetStartingPos();
}
