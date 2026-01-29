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

void APlayer::Attack(ACharacter* Target)
{
	cout << Name << "이(가) 무기로 공격합니다" << endl;
	ACharacter::Attack(Target);
}