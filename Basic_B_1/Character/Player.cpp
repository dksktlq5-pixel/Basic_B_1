#include "Player.h"
#include "Character.h"
#include <iostream>

using namespace std;

APlayer::APlayer(string name, const FUnitStat& NewStat)
	: ACharacter(name, NewStat)
{
	Level = 1;
	Exp = 0;

	cout << "Player 생성됨: "
		<< Name << " (HP: " << Stat.Hp
		<< ", ATK: " << Stat.Atk
		<< ")" << endl;
}

void APlayer::GainExp(int amount)
{
	Exp += amount;
	cout << Name << "이(가) "
		<< amount << " 경험치 획득! (현재 EXP: "
		<< Exp << ")" << endl;

	constexpr int MAX_LEVEL = 10;
	constexpr int MAX_EXP = 100;
	
	while (Exp >= MAX_EXP && Level < MAX_LEVEL)
	{
		Exp -= MAX_EXP;
		LevelUp();
	}
}

void APlayer::LevelUp()
{
	Level++;

	Stat.Hp += Level * 20;
	Stat.Atk += Level * 5;

	cout << "레벨 업! "
		<< Name << " Lv" << Level
		<< " (HP: " << Stat.Hp
		<< ", ATK: " << Stat.Atk << ")" << endl;
}

void APlayer::UseItem()
{

}

FDamageResult APlayer::Attack(ACharacter* Target)
{
	FDamageResult result = ACharacter::Attack(Target);
	string AttackMessage = "이(가) 대검으로 내려칩니다!";
	if (result.bCritical)
	{
		AttackMessage = "이(가) 치명타 공격합니다!";
	}

	cout << "푸직! " << Name << AttackMessage << "데미지: " << result.Damage << endl;
	cout << Target->GetName() << "Hp: " << Target->GetHp() << endl;
	return result;
}