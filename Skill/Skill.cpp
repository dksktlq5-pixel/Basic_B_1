#include "Skill.h"

USkill::USkill(ACharacter* NewOwner, int NewMpCost)
{
    Owner = NewOwner;
    MpCost = NewMpCost;
}

int USkill::GetMpCost()
{
    return MpCost;
}