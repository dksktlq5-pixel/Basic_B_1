#pragma once
#include <iostream>
#include <string>
using namespace std;

class Character
{
public:
    Character();
    ~Character();

protected:
    string Name;
    int Hp;
    int Atk;

public:
    void Attack();
    void TakeDamage(int DamageAmount);

    int GetHp() { return Hp; }
    bool IsDead() { return Hp <= 0; }
    int GetAtk() { return Atk; }
    string GetName() { return Name; }

    void ShowStatus()
    {
        cout << Name << " | HP: " << Hp << " | ATK: " << Atk << endl;
    }
};
