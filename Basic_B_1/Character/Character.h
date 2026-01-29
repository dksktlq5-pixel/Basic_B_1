#pragma once
#include <iostream>
#include <string>

using namespace std;

struct FUnitStat
{
	int Hp;
	int Atk;
	int Def;
	int Critical;
};

//데이터 덩어리
struct FDamageResult
{
	int Damage;
	bool bCritical;
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

private:
	int GetRandomInt();
};
