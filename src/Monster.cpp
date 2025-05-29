#pragma once
#include<iostream>

#include "Monster.h"

using namespace std;

Monster::Monster() {
    hp = 50;
    atk = 10;
    exp = 20;
    type = "[몬스터] ";
    name = "몬스터";
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
        cout << "몬스터 불러오기 실패!\n";
        throw runtime_error("파일 읽기 실패");
    }
}
