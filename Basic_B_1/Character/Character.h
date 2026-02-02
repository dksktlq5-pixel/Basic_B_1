#pragma once
#include <iostream>
#include <string>

using namespace std;

struct FUnitStat
{
	int MaxHp;
	int MaxMp;
	int Atk;
	int Def;
	int Critical;

	int Hp = 0;
	int Mp = 0;
	
	FUnitStat()
	{
	}

	FUnitStat(int MaxHp, int MaxMp, int Atk, int Def, int Critical)
	{
		this->MaxHp = MaxHp;
		this->MaxMp = MaxMp;
		this->Atk = Atk;
		this->Def = Def;
		this->Critical = Critical;
	}
};

class ACharacter;

//데이터 덩어리
struct FDamageResult
{
	//공격자와 대상 포인터를 추가.
	ACharacter* Attacker;
	ACharacter* Target;

	int Damage;
	bool bCritical;
	void PrintMessage(const string& AttackMessage);
};

class ACharacter
{
public:
	ACharacter(const string& NewName, const FUnitStat& NewStat);
	~ACharacter();

protected:
	string Name;
	FUnitStat Stat;

public:
	virtual FDamageResult Attack(ACharacter* Target);
	int TakeDamage(int DamageAmount);
	int GetHp() { return Stat.Hp; }

	const string& GetName() { return Name; }
	bool IsDead() { return Stat.Hp <= 0; }

	virtual void UseSkill(ACharacter* Target) = 0;

	void PrintName();

	void Heal(int amount);

private:
	int GetRandomInt();
};
