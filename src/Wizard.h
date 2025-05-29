#pragma once
#include<iostream>

#include "Character.h"

using namespace std;

class Wizard : public Character {
public:
    /**
     * 마법사 초기 설정
     * 레벨: 1
     * 체력: 60
     * 최대 체력: 60
     * 공격력: 10
     * 방어력: -5
     * 경험치: 0
     */
    Wizard();
    Wizard(string name);
    void levelUp() override;
    void displayInfo() const override;
};