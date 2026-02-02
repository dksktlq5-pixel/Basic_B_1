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
    FDamageResult Attack(ACharacter* Target) override;

    virtual void UseSkill(ACharacter* Target) override;

    int GetLevel() const { return Level; }
    int GetExp() const { return Exp; }
};