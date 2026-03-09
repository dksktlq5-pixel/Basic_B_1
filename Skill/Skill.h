#pragma once
#include <string>
using namespace std;

class ACharacter;

// 부모 클래스
class USkill
{
public:
    USkill(ACharacter* NewOwner, int NewMpCost, const string& NewName);  

protected:
    ACharacter* Owner = nullptr;
    int MpCost;
    string Name;

public:
    virtual void Play(ACharacter* Target) = 0;
    int GetMpCost();
    const string& GetName() const;
};