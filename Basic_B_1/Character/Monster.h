#pragma once
#include "Character.h"

class AMonster : public ACharacter
{
public:
    AMonster(const string& Name, const FUnitStat& NewStat);
};