#ifndef _PLAYERCLASS_H
#define _PLAYERCLASS_H
#include <fstream>
#include <iostream>
#include <windows.h>

struct SGameChar
{
	COORD playerPos;
	bool  isPlayerActive;
	bool canTele = true;
};
class PlayerClass {
	
public:

	PlayerClass();
	void SetStartingPos();
	
	void GenerateCharacter();
	void CharacterMovement();
	void CharacterKilled();
	

private:
	
};


#endif