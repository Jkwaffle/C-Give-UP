#include "BlockFunctions.h"
#include "../GameController/PlayerClass.h"
#include <windows.h>

extern SGameChar gameChar;


void BlockFunctions::boostMovePlayer(dir curDir){
	switch (curDir){
	case dir_Up:
		gameChar.playerPos.Y -= 2;
		break;
	case dir_Down:
		gameChar.playerPos.Y += 2;
		break;
	case dir_Left:
		gameChar.playerPos.X -= 2;
		break;
	case dir_Right:
		gameChar.playerPos.X += 2;
		break;

	}
}


void BlockFunctions::teleportPlayer(COORD loc, bool canTele)
{
	if (canTele){
		gameChar.playerPos.X = loc.X;
		gameChar.playerPos.Y = loc.Y;
	}
	
}