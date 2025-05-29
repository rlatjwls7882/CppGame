#pragma once
#include<iostream>

#include "Character.h"

using namespace std;

class Warrior : public Character {
protected:
	/**
	 * defense: ����
	 * plusDefense: ������ �� ������ ������ ����
	 */
	int defense, plusDefense;
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
	bool takeDamage(int damage) override;;
    void levelUp() override;
    void displayInfo() const override;
	void saveCharacter() override;
	void loadCharacter() override;
};