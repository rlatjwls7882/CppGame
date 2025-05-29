#pragma once
#include<iostream>

#include "Character.h"

using namespace std;

class Wizard : public Character {
protected:
    /**
    * defense: ����
    * plusDefense: ������ �� ������ ������ ����
    */
    int defense, plusDefense;
public:
    /**
     * ������ �ʱ� ����
     * ����: 1
     * ü��: 60
     * �ִ� ü��: 60
     * ���ݷ�: 10
     * ����: -5
     * ����ġ: 0
     */
    Wizard();
    Wizard(string name);
    void levelUp() override;
    void displayInfo() const override;
	void saveCharacter() override;
	void loadCharacter() override;
};