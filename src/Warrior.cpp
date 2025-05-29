#include<iostream>

#include "Warrior.h"

using namespace std;

   /**
    * ���� �ʱ� ����
    * ����: 1
    * ü��: 120
    * �ִ� ü��: 120
    * ���ݷ�: 6
    * ����: 1
    * ����ġ: 0
    */
Warrior::Warrior() : Warrior("����") {}

Warrior::Warrior(string name) {
    this->name = name;
    level = 1;
    hp = maxHp = 120;
    atk = 6;
    exp = 0;
    plusHp = 20;
    plusAtk = 3;
    plusDefense = 1;
	gold = 0;
    defense = 1;
    type = "[����] ";
}

void Warrior::levelUp() {
    cout << "������: " << level << " -> " << level + 1 << '\n'
         << "�ִ� ü��: " << maxHp << " -> " << maxHp + plusHp << '\n'
         << "ü��: " << hp << " -> " << hp + plusHp << '\n'
         << "���ݷ�: " << atk << " -> " << atk + plusAtk << '\n'
         << "����: " << defense << " -> " << defense + plusDefense << '\n\n';
    level++;
    hp += plusHp;
    maxHp += plusHp;
	defense += plusDefense;
    atk += plusAtk;
}

void Warrior::displayInfo() const {
    cout << "------ " << type << name << " ------\n"
         << "����: " << level << "\n"
         << "����ġ: " << exp << " / 50\n"
         << "ü��: " << hp << " / " << maxHp << "\n"
         << "���ݷ�: " << atk << "\n"
         << "����: " << defense << "\n"
         << "���: " << gold << "\n\n";
}
