#include "Character.h"
#include <iostream>
#include <random>

using namespace std;

void FDamageResult::PrintMessage(const string& AttackMessage)
{
	cout << "-------------------------------------------------" << endl;
	Attacker->PrintName();
	cout << AttackMessage << '\n';
	
	Target->PrintName();
	cout << "'받은 데미지': " << Damage << "-> '남은 HP': " << Target->GetHp() << "/" << Target->GetMaxHp() << endl;
	cout << "-------------------------------------------------" << endl;
}

ACharacter::ACharacter(const string& NewName, const FUnitStat& UnitStat)
{
	Name = NewName;
	Stat = UnitStat;

	Stat.Hp = Stat.MaxHp;
	Stat.Mp = Stat.MaxMp;

	cout << "[생성] " << Name << "가 전장에 나타났습니다! (HP: " << Stat.Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
	cout << "ACharacter 소멸됨" << endl;
}

bool ACharacter::HasEnoughMp(int Cost)
{
	return Stat.Mp >= Cost;
}

void ACharacter::ConsumeMp(int Cost)
{
	Stat.Mp -= Cost;
	if (Stat.Mp < 0)
		Stat.Mp = 0;
	// Stat.Mp = max(Stat.Mp - Cost, 0);
}

int ACharacter::TakeDamage(int DamageAmount)
{
	DamageAmount = DamageAmount - Stat.Def;
	DamageAmount = max(DamageAmount, 0);

	Stat.Hp = Stat.Hp - DamageAmount;
	Stat.Hp = max(Stat.Hp, 0);
	return DamageAmount;
}

void ACharacter::Heal(int amount)
{
	int PrevHp = Stat.Hp;
	Stat.Hp += amount;
	Stat.Hp = min(Stat.MaxHp, Stat.Hp);

	int ActualHeal = Stat.Hp - PrevHp;

	PrintName();
	cout << ActualHeal << " HP를 회복했습니다...!" << endl;
}

int ACharacter::GetRandomInt(int Max)
{
	static random_device rd;
	static mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, Max -1);
	return dis(gen);
}

void ACharacter::PrintName()
{
	cout << "[" << Name << "] ";
}

void ACharacter::ShowStat()
{
	cout << "[System] ";
	PrintName();
	
	cout << " HP: " << Stat.Hp << " / " << Stat.MaxHp <<  " MP: " << Stat.Mp << " / " << Stat.MaxMp << endl;
}
