#pragma once
#include<iostream>

#include "Monster.h"

using namespace std;

Monster::Monster() {
    hp = 50;
    atk = 10;
    exp = 20;
    type = "[����] ";
    name = "����";
    gold = 10;
}

void Monster::displayMonster() {
    cout << type << name << '\n';
}

void Monster::saveMonster(ofstream& ofs) {
    ofs << name << ' '
        << hp << ' '
        << atk << ' '
        << gold << ' '
        << exp << '\n';
}

void Monster::loadMonster(ifstream& ifs) {
    ifs >> name >> hp >> atk >> gold >> exp;
    
    if(ifs.fail()) {
        cout << "���� �ҷ����� ����!\n";
        throw runtime_error("���� �б� ����");
    }
}
