#include "GameClass.h"
#include "../Framework/console.h"
#include "PlayerClass.h"
#include "../LevelGenerator/MapGenerator.h"

extern MapGenerator MapGenRef;
extern GameClass gameController;

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
		gameChar.playerPos.Y--;
		for each(COORD i in  MapGenerator::wallpos(stage)){
			if (i.X == gameChar.playerPos.X && i.Y == gameChar.playerPos.Y){
				gameChar.playerPos.Y++;//checking for collision
			}
		}
	}
	if (GameClass::keyPressed[Key_Left])
	{
		gameChar.playerPos.X--;
		for each(COORD i in MapGenerator::wallpos(stage)){
			if (i.X == gameChar.playerPos.X && i.Y == gameChar.playerPos.Y){
				gameChar.playerPos.X++;//checking for collision
			}
		}
	}
	if (GameClass::keyPressed[Key_Down])
	{
		gameChar.playerPos.Y++;
		for each(COORD i in MapGenerator::wallpos(stage)){
			if (i.X == gameChar.playerPos.X && i.Y == gameChar.playerPos.Y){
				gameChar.playerPos.Y--;//checking for collision
			}
		}
	}
	if (GameClass::keyPressed[Key_Right])
	{
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

}
void PlayerClass::GenerateCharacter(){

	GameClass::gameConsole.writeToBuffer(gameChar.playerPos, (char)1, 11);

}
void PlayerClass:: CharacterKilled(){

	PlayerClass::SetStartingPos();
}
