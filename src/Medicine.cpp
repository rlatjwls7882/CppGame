#include<iostream>
#include<string>

#include "Medicine.h"

using namespace std;

Medicine::Medicine(int gold, int hp) {
    this->name = "ȸ�� ����(" + to_string(hp) + ")";
    this->gold = gold;
    this->hp = hp;
}

void Medicine::printInfo(int i) const {
    cout << i << ". " << name << ": " << gold << "���\n";
}
