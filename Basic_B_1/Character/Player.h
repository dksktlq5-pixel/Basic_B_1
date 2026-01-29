#pragma once
#include "Character.h"

class APlayer : public ACharacter
{
public:
    APlayer(string name, const FUnitStat& Stat);

private:
    int Level;
    int Exp;
    
public:
    void GainExp(int amount);
    void LevelUp();
    void UseItem();
    void Attack(ACharacter* Target) override;

    int GetLevel() const { return Level; }
    int GetExp() const { return Exp; }
};