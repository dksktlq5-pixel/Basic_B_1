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

	result.PrintMessage(AttackMessage);
	return result;
}

void APlayer::UseSkill(ACharacter* Target)
{
	if (Stat.Mp < 0)
	{
		cout << "Mp가 부족합니다." << endl;
		return;
	}

	Stat.Mp -= 10; //mp 10 소모
	int Damage = Stat.Atk * 2;
	int FinalDamage = Target->TakeDamage(Damage);

	FDamageResult result;
	result.Attacker = this;
	result.Target = Target;
	result.Damage = FinalDamage;
	result.bCritical = false;

	string SkillMassage = "이(가) 엄청난 힘을 사용했다!";
	result.PrintMessage(SkillMassage);
}

//테이크데미지에서 받아와서 데미지 리절트 세팅해서 메시지 출력