#pragma once
#include<iostream>

#include "Character.h"

using namespace std;

class Warrior : public Character {
public:
    /**
     * 전사 초기 설정
     * 레벨: 1
     * 체력: 120
     * 최대 체력: 120
     * 공격력: 6
     * 방어력: 1
     * 경험치: 0
     */
    Warrior();
    Warrior(string name);
    void levelUp() override;
    void displayInfo() const override;
};