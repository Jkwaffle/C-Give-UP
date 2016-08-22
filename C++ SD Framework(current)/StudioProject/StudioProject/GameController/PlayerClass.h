#ifndef _PLAYERCLASS_H
#define _PLAYERCLASS_H
#include <fstream>
#include <iostream>


struct SGameChar
{
	COORD playerPos;
	bool  isPlayerActive;
};
class PlayerClass {
	
public:

	PlayerClass();
	void SetStartingPos();
	SGameChar gameChar;
	void GenerateCharacter();
	void CharacterMovement();
	void CharacterKilled();
	

private:
	
};


#endif