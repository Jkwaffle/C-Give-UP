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
				gameChar.playerPos.Y++;
			}
		}
	}
	if (GameClass::keyPressed[Key_Left])
	{
		gameChar.playerPos.X--;
		for each(COORD i in MapGenerator::wallpos(stage)){
			if (i.X == gameChar.playerPos.X && i.Y == gameChar.playerPos.Y){
				gameChar.playerPos.X++;
			}
		}
	}
	if (GameClass::keyPressed[Key_Down])
	{
		gameChar.playerPos.Y++;
		for each(COORD i in MapGenerator::wallpos(stage)){
			if (i.X == gameChar.playerPos.X && i.Y == gameChar.playerPos.Y){
				gameChar.playerPos.Y--;
			}
		}
	}
	if (GameClass::keyPressed[Key_Right])
	{
		gameChar.playerPos.X++;
		for each(COORD i in MapGenerator::wallpos(stage)){
		if (i.X == gameChar.playerPos.X && i.Y == gameChar.playerPos.Y){
				gameChar.playerPos.X--;
			}
		}
	}
	if (gameChar.playerPos.X == MapGenRef.nextlevel().X && gameChar.playerPos.Y == MapGenRef.nextlevel().Y)
	{
		gameController.AddLevel();
		PlayerClass::SetStartingPos();
	}

}

void PlayerClass::GenerateCharacter(){

	GameClass::gameConsole.writeToBuffer(gameChar.playerPos, (char)1, 11);

}
void PlayerClass:: CharacterKilled(){

	PlayerClass::SetStartingPos();
}
//void PlayerClass::GenerateCharacter(){
	//PlayerClass::SetStartingPos();
//}