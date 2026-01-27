#include "Character/Player.h"
#include "Character/Monster.h"
#include <clocale>
#include <windows.h>

int main()
{
    std::setlocale(LC_ALL, "Korean");

    FUnitStat PlayerStat = { 250, 40, 5, 20 }; 
    FUnitStat MonsterStat = { 200, 30, 3, 10 }; 

    ACharacter* Player = new ACharacter("용사", PlayerStat);
	ACharacter* Monster = new ACharacter("오크", MonsterStat);

    cout << "===  데스매치 시작!  ===" << endl;
    Sleep(1000);

    while (!Player->IsDead() && !Monster->IsDead())
    {
        Player->Attack(Monster);
        if (Monster->IsDead())
        {
            cout << "몬스터가 쓰러졌습니다! 승리!" << endl;
            break;
        }

        Sleep(500);
        Monster->Attack(Player);
        if (Player->IsDead())
        {
            cout << "플레이어가 쓰러졌습니다... 패배..." << endl;
            break;
        }

        Sleep(1000);
    }

    delete Player;
    delete Monster;
    return 0;
}
