#include "GameClass.h"
#include "../Framework/console.h"
#include "PlayerClass.h"
#include "../LevelGenerator/MapGenerator.h"

MapGenerator collisionObj;

PlayerClass::PlayerClass(){
	SetStartingPos();

}
void PlayerClass::SetStartingPos(){
	gameChar.playerPos.X = 14;
	gameChar.playerPos.Y = 57;
}
void PlayerClass::CharacterMovement(){


	//if (g_dBounceTime > g_dElapsedTime)
	//return;
	if (GameClass::keyPressed[Key_Up])
	{
		gameChar.playerPos.Y--;
		for each(COORD i in collisionObj.wallpos){
			//optimise for later[this is collision]
			if (i.X == gameChar.playerPos.X && i.Y == gameChar.playerPos.Y){
				gameChar.playerPos.Y++;
			}

		}
	}
	if (GameClass::keyPressed[Key_Left])
	{
		gameChar.playerPos.X--;
		for each(COORD i in collisionObj.wallpos){
			//optimise for later[this is collision]
			if (i.X == gameChar.playerPos.X && i.Y == gameChar.playerPos.Y){
				gameChar.playerPos.X++;
			}
		}
	}
	if (GameClass::keyPressed[Key_Down])
	{
		gameChar.playerPos.Y++;
		for each(COORD i in collisionObj.wallpos){
			//optimise for later[this is collision]
			if (i.X == gameChar.playerPos.X && i.Y == gameChar.playerPos.Y){
				gameChar.playerPos.Y++;
			}
		}
	}
	if (GameClass::keyPressed[Key_Right])
	{
		gameChar.playerPos.X++;
		for each(COORD i in collisionObj.wallpos){
			//optimise for later[this is collision]
			if (i.X == gameChar.playerPos.X && i.Y == gameChar.playerPos.Y){
				gameChar.playerPos.X++;
			}
		}
	}
}

void PlayerClass::GenerateCharacter(){

	GameClass::gameConsole.writeToBuffer(gameChar.playerPos, (char)1, 11);

}