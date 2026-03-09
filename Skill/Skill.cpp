#include "Skill.h"

USkill::USkill(ACharacter* NewOwner, int NewMpCost, const string& NewName)
{
    Owner = NewOwner;
    MpCost = NewMpCost;
    Name = NewName;
}

int USkill::GetMpCost()
{
    return MpCost;
}

const string& USkill::GetName() const
{
    return Name;
}