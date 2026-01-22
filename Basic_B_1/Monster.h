#pragma once
#include "ACharacter.h"

class Monster : public ACharacter {
public:
    Monster(string _Name, int _Hp, int _Atk, int _Def, float _Cri)
        : ACharacter(_Name, _Hp, _Atk, _Def, _Cri) {
    }

    // 몬스터만의 특별한 공격 방식 등을 오버라이딩 가능
};