#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(string name)
	: ACharacter(name, 200, 30, 0, 0) // 부모 클래스 생성자 호출
{
	level = 1;
	exp = 0;
	maxLevel = 10;
	cout << "Player 생성됨: " << Name << " (HP: " << Hp << ", ATK: " << Atk << ")" << endl;
}

void Player::GainExp(int amount)
{
	exp += amount;
	cout << Name << "이(가) " << amount << " 경험치 획득! (현재 EXP: " << exp << ")" << endl;
	while (exp >= 100 && level < maxLevel)
	{
		exp -= 100;
		LevelUp();
	}
}

void Player::LevelUp()
{
	level++;
	Hp += level * 20;
	Atk += level * 5;
	cout << "레벨 업! " << Name << " Lv" << level << " (HP: " << Hp << ", ATK: " << Atk << ")" << endl;
}

int Player::GetLevel() 
{ 
	return level; 
}
int Player::GetExp() 
{ 
	return exp; 
}