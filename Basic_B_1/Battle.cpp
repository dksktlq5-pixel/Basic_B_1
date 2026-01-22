#include "Battle.h"

void Battle::Fight(Player& player, Monster& monster)
{
    cout << "\n=== 전투 시작! ===\n";

    srand((unsigned int)time(0));

    while (!player.IsDead() && !monster.IsDead())
    {
        // 플레이어 턴
        player.Attack();
        monster.TakeDamage(player.GetAtk());
        if (monster.IsDead())
        {
            cout << monster.GetName() << " 처치!\n";
            player.GainExp(50); // 승리 경험치
            break;
        }

        // 몬스터 턴
        monster.Attack();
        player.TakeDamage(monster.GetAtk());
        if (player.IsDead())
        {
            cout << player.GetName() << " 패배...\n";
            break;
        }
    }

    cout << "=== 전투 종료 ===\n\n";
}
