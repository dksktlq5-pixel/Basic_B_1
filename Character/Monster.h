#pragma once
#include "Character.h"

class AMonster : public ACharacter
{
public:
	AMonster(const string& NewName, const FUnitStat& NewStat);
	~AMonster() override;

public:
	void PlayTurn(ACharacter* Target) override;
};
