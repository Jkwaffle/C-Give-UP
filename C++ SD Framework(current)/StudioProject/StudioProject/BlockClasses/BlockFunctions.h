#pragma once
#include <windows.h>

enum dir {
	dir_Up,
	dir_Down,
	dir_Left,
	dir_Right,
	dir_None
};

class BlockFunctions
{
public:

	static void boostMovePlayer(dir direction);
	static void teleportPlayer(COORD loc, bool canTele);
	

};

