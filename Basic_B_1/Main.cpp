#include "Character/Player.h"
#include "Character/Monster.h"
#include <clocale>
#include <windows.h>
#include <iostream>

using namespace std;

class BattleManager
{
public:
    void WaitForPlayerInput()
    {
        system("pause");
        cout << endl;
    }

    bool BattleTurn(ACharacter* Attacker, ACharacter* Defender)
    {
        Attacker->PlayTurn(Defender);
		Attacker->ShowStat(), Defender->ShowStat();
        WaitForPlayerInput();

        if (Defender->IsDead())
        {
            cout << Defender->GetName() << "(이)가 쓰러졌습니다!" << endl;
            return true;
        }
        return false;
    }

    void RunBattle(ACharacter* Player, ACharacter* Monster)
    {
        cout << "===  데스매치 시작!  ===" << endl;
        Sleep(1000);

        while (true)
        {
            if (BattleTurn(Player, Monster)) break;
            if (BattleTurn(Monster, Player)) break;
        }

        cout << "===  전투 종료  ===" << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Korean");

    ACharacter* Player = new APlayer("용사", FUnitStat(200, 50, 30, 5, 10));
    ACharacter* Monster = new AMonster("몬스터", FUnitStat(100, 30, 20, 3, 10));

    BattleManager* Manager = new BattleManager();
    Manager->RunBattle(Player, Monster);

    delete Player;
    delete Monster;

	Manager->WaitForPlayerInput();
    delete Manager;

    return 0;
}
