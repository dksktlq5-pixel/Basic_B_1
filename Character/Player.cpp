#include "Player.h"
#include <iostream>
#include "../Skill/UPlayerAttackSkill.h"
#include "../Skill/UPlayerStrikeSkill.h"

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;
	Skills.push_back(make_unique<UPlayerAttackSkill>(this));
	Skills.push_back(make_unique<UPlayerStrikeSkill>(this));
}

APlayer::~APlayer()
{
	cout << "APlayer 소멸됨" << endl;
}

void APlayer::LevelUp()
{
	
}

void APlayer::UseItem()
{
	
}
