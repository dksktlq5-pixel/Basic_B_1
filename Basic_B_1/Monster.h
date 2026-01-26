#pragma once
#include "Character.h"

class Monster : public ACharacter
{
public:
    Monster(string Name, const FUnitStat& NewStat)
        : ACharacter(Name, NewStat)
    {
    }

};