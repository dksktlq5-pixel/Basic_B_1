#include "ACharacter.h"
#include <random>
#include <Windows.h> 

ACharacter::ACharacter(string NewName, int NewHp, int NewAtk, int NewDef, float NewCri)
{
    Name = NewName;
    Hp = NewHp;
    Atk = NewAtk;
    Def = NewDef;
    Critical = (int)NewCri; 

    cout << "Character 생성됨: " << Name << " (HP: " << Hp << ", ATK: " << Atk << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "Character 소멸됨: " << Name << endl;
}

int getRandomInt()
{
    static random_device rd;

    static mt19937 gen(rd());

    uniform_int_distribution<int> dis(0, 100);

    return dis(gen);
}
void ACharacter::Attack(ACharacter* target)
{
    int damage = Atk;

	int random = getRandomInt();
	
    if (random <= Critical)
    {
        cout << Name << "이(가) 크리티컬 공격!" << damage << endl;
        damage = Atk * 1.5;
    }
    else
    {
		cout << Name << "이(가) 일반 공격." << damage << endl;
    }
    target->TakeDamage(damage);
}

void ACharacter::TakeDamage(int DamageAmount)
{
    Hp -= DamageAmount;
    if (Hp < 0) Hp = 0;

    cout << Name << "가 " << DamageAmount << "의 피해를 입었습니다." << endl;
    cout << "   -> 남은 체력: " << Hp << endl;

    if (IsDead())
    {
        cout << Name << "이(가) 쓰러졌습니다!" << endl;
    }
}