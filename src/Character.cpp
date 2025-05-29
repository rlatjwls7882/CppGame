#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include "Character.h"
#include "Monster.h"

using namespace std;

   /**
    * ĳ���� �ʱ� ����
    * ����: 1
    * ü��: 100
    * �ִ� ü��: 100
    * ���ݷ�: 10
    * ����ġ: 0
    */
Character::Character() : Character("����") {}

Character::Character(string name) {
    this->name = name;
    level = 1;
    hp = maxHp = 100;
    atk = 10;
    exp = 0;
    gold = 0;
    plusHp = 10;
    plusAtk = 5;
    type = "[ĳ����] ";
}

void Character::killMonster(Character*& target) {
    exp += target->exp;
    gold += target->gold;
    cout << "�¸�! ����ġ" << target->exp << ", ��� " << target->exp << " ȹ��!\n\n";

    while(exp >= 50) {
        exp -= 50;
        levelUp();
    }
}

void Character::killMonster(Monster*& target) {
    exp += target->exp;
    gold += target->gold;
    cout << "\n�¸�! ����ġ" << target->exp << ", ��� " << target->gold << " ȹ��!\n\n";

    while(exp >= 50) {
        exp -= 50;
        levelUp();
    }
}

void Character::levelUp() {
    cout << "������: " << level << " -> " << level + 1 << '\n'
         << "�ִ� ü��: " << maxHp << " -> " << maxHp + plusHp << '\n'
         << "ü��: " << hp << " -> " << hp + plusHp << '\n'
         << "���ݷ�: " << atk << " -> " << atk + plusAtk << '\n\n';
    level++;
    hp += plusHp;
    maxHp += plusHp;
    atk += plusAtk;
}

bool Character::damageLog() const {
    cout << type << name << "(��/��) ������ �޾Ҵ�.\n"
         << type << name << "�� ü���� " << hp << "�� �����ߴ�.\n";
    if(!isAlive()) {
        cout << type << name << "(��/��) ����ߴ�.\n";
        return false;
    }
    return true;
}

bool Character::takeDamage(int damage) {
    hp = max(hp - damage, 0);
    return damageLog();
}

bool Character::attack(Character*& target) const {
    cout << type << name << "�� ����!\n";
    return target->takeDamage(atk);
}

bool Character::attack(Monster*& target) const {
    cout << type << name << "�� ����!\n";
    return target->takeDamage(atk);
}

bool Character::isAlive() const {
    return hp > 0;
}

void Character::displayInfo() const {
    cout << "------ " << type << name << " ------\n"
         << "����: " << level << "\n"
         << "����ġ: " << exp << " / 50\n"
         << "ü��: " << hp << " / " << maxHp << "\n"
         << "���ݷ�: " << atk << "\n"
         << "���: " << gold << "\n\n";
}

void Character::saveCharacter() {
    ofstream ofs("character.txt");
    ofs << type
        << name << ' '
        << level << ' '
        << hp << ' '
        << maxHp << ' '
        << atk << ' '
        << exp << ' '
        << gold << ' ';
    ofs.close();
}

void Character::loadCharacter() {
    try {
        ifstream ifs("character.txt");
        ifs >> type >> name >> level >> hp >> maxHp >> atk >> exp >> gold;
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

int Character::getRandomInt(int min, int max) {
    return rand() % (max-min+1) + min;
}

bool Character::useMedicine(int hp, int gold) {
    if(this->gold < gold) {
        cout << "��尡 �����մϴ�.\n\n";
        return false;
    }

    int nextHp = min(this->hp + hp, maxHp);
    cout << type << name << "��(��) ȸ�� ������ ����߽��ϴ�.\n"
         << "ü���� " << this->hp << "���� " << nextHp << " �� ��ȭ�߽��ϴ�.\n\n";
	
    this->gold -= gold;
    this->hp = nextHp;
    return true;
}
