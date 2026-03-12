#include "Monster.h"
#include <iostream>
#include "../Skill/UMonsterAttackSkill.h"
#include "../Skill/UMonsterDrainSkill.h"

AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Skills.push_back(make_unique<UMonsterAttackSkill>(this));
	Skills.push_back(make_unique<UMonsterDrainSkill>(this));
}

AMonster::~AMonster()
{
	cout << "AMonster 소멸됨" << endl;
}
 
void AMonster::PlayTurn(ACharacter* Target)
{
	vector<USkill*> UsableSkills;
	for (auto& skill : Skills)
	{
		if (skill->CanUse())
		{
			UsableSkills.push_back(skill.get());
		}
	}
	if (UsableSkills.empty())
	{
		cout << "행동불가!" << endl;
		return;
	}
	int index = GetRandomInt(static_cast<int>(UsableSkills.size()));
	UsableSkills[index]->Play(Target);
}