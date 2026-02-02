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

	result.PrintMessage(AttackMessage);
	return result;
}

void AMonster::UseSkill(ACharacter* Target)
{
	if (Stat.Mp < 0)
	{
		cout << "Mp가 부족합니다." << endl;
		return;
	}

	Stat.Mp -= 10; //mp 10 소모
	int Damage = Stat.Atk;
	int FinalDamage = Target->TakeDamage(Damage);

	FDamageResult result;
	result.Attacker = this;
	result.Target = Target;
	result.Damage = FinalDamage;
	result.bCritical = false;

	Heal(FinalDamage);

	string SkillMassage = "흡혈 공격을 사용했다!";
	result.PrintMessage(SkillMassage);
}