#pragma once
#include "Character.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Monster : public Character
{
public:
    Monster(string name, int playerLevel)
    {
        srand((unsigned int)time(0));
        Name = name;
        Hp = playerLevel * 20 + rand() % (playerLevel * 11);
        Atk = playerLevel * 5 + rand() % (playerLevel * 6);

        cout << "Monster 생성됨: " << Name << " (HP: " << Hp << ", ATK: " << Atk << ")\n";
    }
};
