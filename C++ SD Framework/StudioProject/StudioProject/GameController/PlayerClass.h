#ifndef _PLAYERCLASS_H
#define _PLAYERCLASS_H


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

private:
	
	//void CharacterMovement();

};


#endif