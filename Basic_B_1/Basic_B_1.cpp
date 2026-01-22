#include "Player.h"
#include "Monster.h"
#include "Battle.h"
#include <windows.h>


int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Player hero("Hero");
    hero.ShowStatus();

    Monster slime("Slime", hero.GetLevel());

    Battle::Fight(hero, slime);

    hero.ShowStatus();
}
