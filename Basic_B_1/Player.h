#pragma once
#include "Character.h"

class Player : public ACharacter
{
private:
    int level;
    int exp;
    int maxLevel;

public:
    Player(string name, const FUnitStat& Stat);

    void GainExp(int amount);
    void LevelUp();

    int GetLevel() const;
    int GetExp() const;
};