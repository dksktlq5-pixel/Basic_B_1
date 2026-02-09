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
	result.Attacker = this;
	result.Target = Target;
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

void FDamageResult::PrintMessage(const string& AttackMessage)
{
	cout << "-------------------------------------------------" << endl;
	Attacker->PrintName();
	cout << AttackMessage << endl;

	Target->PrintName();
	cout << "'받은 데미지': " << Damage << "-> '남은 HP': " << Target->GetHp() << endl;
	cout << "-------------------------------------------------" << endl;
}


void ACharacter::PrintName()
{
	cout << "[" << Name << "] ";
}

void ACharacter::Heal(int amount)
{
	int PrevHp = Stat.Hp;
	Stat.Hp += amount;
	Stat.Hp = min(Stat.MaxHp, Stat.Hp);

	int ActualHeal = Stat.Hp - PrevHp;

	PrintName();
	cout << ActualHeal << "Hp를 회복했습니다...!" << endl;
}

void ACharacter::PlayTurn(ACharacter* Target)
{
	const int AttackRate = 70;
	const int SkillMp = 10;

	int Dice = GetRandomInt();

	if (Dice < AttackRate)
	{
		Attack(Target);
		return;
	}

	if (Stat.Mp < SkillMp)
	{
		cout << "마나가 부족합니다! 기본 공격을 합니다." << endl;
		Attack(Target);
		return;
	}

	UseSkill(Target);
}