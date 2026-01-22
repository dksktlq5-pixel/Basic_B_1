#pragma once
#include "Player.h"
#include "Monster.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Battle
{
public:
    static void Fight(Player& player, Monster& monster);
};
