#include "Character.h"
#include <random>


ACharacter::ACharacter(const string& NewName, const FUnitStat& NewStat)
{
	Name = NewName;
	Stat = NewStat;

	cout << "Character 생성됨: " << Name << " (HP: " << Stat.Hp << ", ATK: " << Stat.Atk << ")" << endl;
}

ACharacter::~ACharacter()
{
	cout << "Character 소멸됨: " << Name << endl;
}

void ACharacter::Attack(ACharacter* Target)
{
	int Damage = Stat.Atk;
	int Random = GetRandomInt();
	if (Random <= Stat.Critical)
	{
		Damage = static_cast<int>(Damage * 1.5f);
		cout << Name << "의 크리티컬 히트!" << endl;
	}
	
	cout << Name << "이(가) " << Target->Name << "에게 " << Damage << "의 피해를 입혔습니다." << endl;
	Target->TakeDamage(Damage);
}

void ACharacter::TakeDamage(int DamageAmount)
{
	int ActualDamage = DamageAmount - Stat.Def;
	ActualDamage = max(ActualDamage, 0);
	
	Stat.Hp -= ActualDamage;
	cout << Name << " HP : " << Stat.Hp << endl;

	if (IsDead())
	{
		cout << Name << "이(가) 쓰러졌습니다!" << endl;
	}
}

int ACharacter::GetRandomInt()
{
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 100);
	return dis(gen);
}