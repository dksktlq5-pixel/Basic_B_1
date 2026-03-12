#include "Skill.h"
#include "../Character/Character.h"

USkill::USkill(ACharacter* NewOwner, int NewMpCost, const string& NewName)
{
    Owner = NewOwner;
    MpCost = NewMpCost;
    Name = NewName;
}

void USkill::Play(ACharacter* Target)
{
    Owner->ConsumeMp(MpCost);
    OnPlay(Target);
}

int USkill::GetMpCost()
{
    return MpCost;
}

const string& USkill::GetName() const
{
    return Name;
}

bool USkill::CanUse()
{
    return Owner->HasEnoughMp(MpCost);
}
