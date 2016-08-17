#ifndef _PLAYERCLASS_H
#define _PLAYERCLASS_H
#include <windows.h>


class PlayerClass
{
public:
	COORD playerPos;
	bool isActive;
	PlayerClass();
};

#endif