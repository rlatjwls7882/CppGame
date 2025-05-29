#pragma once
#include<iostream>

#include "Character.h"

using namespace std;

class Warrior : public Character {
public:
    /**
     * ���� �ʱ� ����
     * ����: 1
     * ü��: 120
     * �ִ� ü��: 120
     * ���ݷ�: 6
     * ����: 1
     * ����ġ: 0
     */
    Warrior();
    Warrior(string name);
    void levelUp() override;
    void displayInfo() const override;
};