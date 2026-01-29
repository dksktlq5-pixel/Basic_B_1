#include "Monster.h"
#include "Character.h"

AMonster::AMonster(const string& Name, const FUnitStat& NewStat)
	: ACharacter(Name, NewStat)
{

}

void AMonster::Attack(ACharacter* Target)
{
	cout << "삭삭! " << Name << "이(가) 할큅니다!" << endl;

	ACharacter::Attack(Target);
}
