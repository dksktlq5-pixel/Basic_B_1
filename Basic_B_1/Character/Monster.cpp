#include "Monster.h"
#include "Character.h"

AMonster::AMonster(const string& Name, const FUnitStat& NewStat)
	: ACharacter(Name, NewStat)
{

}

FDamageResult AMonster::Attack(ACharacter* Target)
{
	FDamageResult result = ACharacter::Attack(Target);
	string AttackMessage = "이(가) 이빨로 물어뜯습니다!";
	if (result.bCritical)
	{
		AttackMessage = "이(가) 약점 부위를 공격합니다!";
	}

	cout << "삭삭! " << Name << AttackMessage <<  "데미지: " << result.Damage << endl;
	cout << Target->GetName() << "Hp: " << Target->GetHp() << endl;
	return result;
}
