#pragma once
#include "Character.h"


class APlayer : public ACharacter
{
public:
	APlayer(const string& NewName, const FUnitStat& NewStat);
	~APlayer() override;
	
protected:
	int Level;
	int Exp;
	
public:
	void LevelUp();
	void UseItem();
};
