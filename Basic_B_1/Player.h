#pragma once
#include "ACharacter.h"
#include <iostream>
#include <string>
using namespace std;

class Player : public ACharacter
{
private:
    int level;
    int exp;
    int maxLevel;

public:
    Player(string name)
    {
        Name = name;
        level = 1;
        Hp = 200;
        Atk = 30;
        exp = 0;
        maxLevel = 10;

        cout << "Player 생성됨: " << Name << " (HP: " << Hp << ", ATK: " << Atk << ")" << endl;
    }

    void GainExp(int amount)
    {
        exp += amount;
        cout << Name << "이(가) 경험치 " << amount << " 획득! (총 EXP: " << exp << ")" << endl;

        while (exp >= 100 && level < maxLevel)
        {
            exp -= 100;
            LevelUp();
        }
    }

    void LevelUp()
    {
        level++;
        Hp += level * 20;
        Atk += level * 5;
        cout << "🎉 레벨업! " << Name << " Lv" << level << " (HP: " << Hp << ", ATK: " << Atk << ")" << endl;
    }

    int GetLevel() { return level; }
    int GetExp() { return exp; }
};
