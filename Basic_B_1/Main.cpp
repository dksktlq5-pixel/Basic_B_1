#include "Character/Player.h"
#include "Character/Monster.h"
#include <clocale>
#include <windows.h>
#include <iostream>

using namespace std;

void WaitForPlayerInput()
{
    system("pause");
    cout << endl;
}

int main()
{
   setlocale(LC_ALL, "Korean");
   ACharacter* Player = new APlayer("용사",FUnitStat(140, 15, 28, 4, 15));
   ACharacter* Monster = new AMonster("오크",FUnitStat(120, 20, 26, 3, 10));

    cout << "===  데스매치 시작!  ===" << endl;
    Sleep(1000);

    while (!Player->IsDead() && !Monster->IsDead())
    {
        Player->PlayTurn(Monster);
        if (Monster->IsDead())
        {
            cout << "몬스터가 쓰러졌습니다! 승리!" << endl;
            break;
        }
        WaitForPlayerInput();

        Monster->PlayTurn(Player);
        if (Player->IsDead())
        {
            cout << "플레이어가 쓰러졌습니다... 패배..." << endl;
            break;
        }
        WaitForPlayerInput();

    }

    delete Player;
    delete Monster;
    return 0;
}
