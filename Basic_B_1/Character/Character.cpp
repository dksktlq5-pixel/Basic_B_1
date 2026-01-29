#include "Character.h"
#include <random>


ACharacter::ACharacter(const string& NewName, const FUnitStat& UnitStat)
{
	Name = NewName;
	Stat = UnitStat;

	Stat.Hp = Stat.MaxHp;
	Stat.Mp = Stat.MaxMp;

	cout << "Character 생성됨: " << Name << " (HP: " << Stat.Hp << ", ATK: " << Stat.Atk << ")" << endl;
}

ACharacter::~ACharacter()
{
	cout << "Character 소멸됨: " << Name << endl;
}

FDamageResult ACharacter::Attack(ACharacter* Target)
{
	int Damage = Stat.Atk;
	bool bCritical = GetRandomInt() < Stat.Critical;
	if (bCritical)
	{
		Damage = static_cast<int>(Damage * 1.5f);
	}
	int FinalDamage = Target->TakeDamage(Damage);
	FDamageResult result;
	result.Damage = FinalDamage;
	result.bCritical = bCritical;
	return result;
}

int ACharacter::TakeDamage(int DamageAmount)
{
	int ActualDamage = DamageAmount - Stat.Def;
	ActualDamage = max(ActualDamage, 0);
	
	Stat.Hp -= ActualDamage;
	Stat.Hp = max(Stat.Hp, 0);
	return ActualDamage;
}



int ACharacter::GetRandomInt()
{
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 100);
	return dis(gen);
}