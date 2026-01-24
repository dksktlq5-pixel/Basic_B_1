#pragma once
#include <iostream>
#include <string>
using namespace std;

class ACharacter
{
public:
    string Name;
    int Hp;
    int Atk;
    int Def;
    int Critical;

public:
    //크리티컬도 int로
    ACharacter(string NewName = "Unknown", int NewHp = 100, int NewAtk = 10, int NewDef = 0, float NewCri = 0.0f);

    ~ACharacter();

    //코딩 스타일 - 파라미터도 대문자 시작
    void Attack(ACharacter* target);
    void TakeDamage(int DamageAmount);

    int GetHp() { return Hp; }
    bool IsDead() { return Hp <= 0; }
    int GetAtk() { return Atk; }
    int GetDef() { return Def; }
    float GetCritical() { return Critical; }
    string GetName() { return Name; }
};
