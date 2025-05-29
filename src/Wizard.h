#pragma once
#include<iostream>

#include "Character.h"

using namespace std;

class Wizard : public Character {
protected:
    /**
    * defense: 방어력
    * plusDefense: 레벨업 할 때마다 오르는 방어력
    */
    int defense, plusDefense;
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
	void saveCharacter() override;
	void loadCharacter() override;
};