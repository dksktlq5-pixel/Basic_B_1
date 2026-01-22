#include "Character.h"

Character::Character()
{
    Name = "Unknown";
    Hp = 100;
    Atk = 10;

    cout << "Character 생성됨: " << Name << " (HP: " << Hp << ")" << endl;
}

Character::~Character()
{
    cout << "Character 소멸됨 " << endl;
}

void Character::Attack()
{
    cout << Name << "가 공격합니다! (공격력: " << Atk << ")" << endl;
}

void Character::TakeDamage(int DamageAmount)
{
    Hp -= DamageAmount;
    if (Hp < 0) Hp = 0;

    cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
    cout << "   -> 남은 체력: " << Hp << endl;
}
