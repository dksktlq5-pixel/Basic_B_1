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
    string Name;
    FUnitStat Stat;

public:
    ACharacter(string NewName, const FUnitStat& NewStat);

    ~ACharacter();

    void Attack(ACharacter* Target);
    void TakeDamage(int DamageAmount);

    int GetHp() { return Stat.Hp; }
    int GetAtk() { return Stat.Atk; }
    int GetDef() { return Stat.Def; }
    int GetCritical() { return Stat.Critical; }
    string GetName() { return Name; }
    bool IsDead() { return Stat.Hp <= 0; }

	int GetRandomInt();
};
