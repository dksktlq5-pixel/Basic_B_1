#include "ACharacter.h"
#include <random>
#include <Windows.h> 

ACharacter::ACharacter(string NewName, int NewHp, int NewAtk, int NewDef, int NewCri)
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

int ACharacter::GetRandomInt()
{
    static random_device rd;

    static mt19937 gen(rd());

    uniform_int_distribution<int> dis(0, 100);

    return dis(gen);
}

void ACharacter::Attack(ACharacter* Target)
{
    int Damage = Atk;

	int Random = GetRandomInt();
	
    if (Random <= Critical)
    {
        cout << Name << "이(가) 크리티컬 공격!" << Damage << endl;
        Damage = (int)Atk * 1.5f;
    }
    else
    {
		cout << Name << "이(가) 일반 공격." << Damage << endl;
    }
    
    Target->TakeDamage(Damage);
}

void ACharacter::TakeDamage(int DamageAmount)
{
    int ActualDamage = DamageAmount - Def;

    if (DamageAmount > 0 && ActualDamage < 0)
        ActualDamage = 0;

    Hp -= ActualDamage;

    if (Hp < 0) Hp = 0;

    cout << Name << " HP: " << Hp << endl;

    if (IsDead())
        cout << Name << "이(가) 쓰러졌습니다!" << endl;
}