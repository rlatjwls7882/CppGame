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

bool Warrior::takeDamage(int damage) {
    hp = max(hp - max(damage-defense, 0), 0);
    return damageLog();
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

void Warrior::saveCharacter() {
    ofstream ofs("character.txt");
    ofs << type
        << name << ' '
        << level << ' '
        << hp << ' '
        << maxHp << ' '
        << atk << ' '
        << exp << ' '
        << gold << ' '
        << defense << ' ';
    ofs.close();
}

void Warrior::loadCharacter() {
    try {
        ifstream ifs("character.txt");
        ifs >> type >> name >> level >> hp >> maxHp >> atk >> exp >> gold >> defense;
        type += ' ';

        if(ifs.fail()) {
            cout << "ĳ���� �ҷ����� ����!\n";
            throw runtime_error("���� �б� ����");
        }
        cout << "ĳ���� �ҷ����� �Ϸ�!\n";
    } catch(const exception&) {
        throw runtime_error("����� ������ �����ϴ�.");
    }
}