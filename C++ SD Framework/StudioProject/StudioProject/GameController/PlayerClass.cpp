#include "GameClass.h"
#include "../Framework/console.h"
#include "PlayerClass.h"
#include "../LevelGenerator/MapGenerator.h"

MapGenerator collisionObj;

void PlayerClass::CharacterMovement(){

	bool bSomethingHappened = false;
	//if (g_dBounceTime > g_dElapsedTime)
	//return;
	if (GameClass::keyPressed[Key_Up])
	{
		gameChar.playerPos.Y--;
		for each(COORD i in collisionObj.wallpos){//-----To FIX -----
			//optimise for later[this is collision]
			if (i.X == gameChar.playerPos.X && i.Y == gameChar.playerPos.Y){
				gameChar.playerPos.Y++;
			}
			bSomethingHappened = true;
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
			bSomethingHappened = true;
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
			bSomethingHappened = true;
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
			bSomethingHappened = true;
		}
	}

}

	void PlayerClass::GenerateCharacter(){

		GameClass::gameConsole.writeToBuffer(gameChar.playerPos, (char)1, 11);

	}