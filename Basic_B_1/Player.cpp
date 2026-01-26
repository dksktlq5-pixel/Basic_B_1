#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(string name, const FUnitStat& NewStat)
    : ACharacter(name, NewStat)
{
    level = 1;
    exp = 0;
    maxLevel = 10;

    cout << "Player 생성됨: "
        << Name << " (HP: " << Stat.Hp << ", ATK: " << Stat.Atk << ")" << endl;
}

void Player::GainExp(int amount)
{
    exp += amount;
    cout << Name << "이(가) "
        << amount << " 경험치 획득! (현재 EXP: " << exp << ")" << endl;

    while (exp >= 100 && level < maxLevel)
    {
        exp -= 100;
        LevelUp();
    }
}

void Player::LevelUp()
{
    level++;

    Stat.Hp += level * 20;
    Stat.Atk += level * 5;

    cout << "레벨 업! "
        << Name << " Lv" << level
        << " (HP: " << Stat.Hp
        << ", ATK: " << Stat.Atk << ")" << endl;
}

int Player::GetLevel() const
{
    return level;
}

int Player::GetExp() const
{
    return exp;
}
