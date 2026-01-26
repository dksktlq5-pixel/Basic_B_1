#pragma once
#include "ACharacter.h"
#include <string>
using namespace std;

class Player : public ACharacter
{
private:
	int level;
	int exp;
	int maxLevel;

public:
	Player(string name);
	void GainExp(int amount);
	void LevelUp();
	int GetLevel();
	int GetExp();
};