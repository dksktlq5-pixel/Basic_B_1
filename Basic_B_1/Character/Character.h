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

class ACharacter
{
public:
	ACharacter(const string& NewName, const FUnitStat& NewStat);
	~ACharacter();
	
protected:
    string Name;
    FUnitStat Stat;

public:
    void Attack(ACharacter* Target);
    void TakeDamage(int DamageAmount);
	
    const string& GetName() { return Name; }
    bool IsDead() { return Stat.Hp <= 0; }
	
private:
	int GetRandomInt();
};
