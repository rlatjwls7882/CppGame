#include<iostream>
#include<string>

#include "Medicine.h"

using namespace std;

Medicine::Medicine(int gold, int hp) {
    this->name = "회복 물약(" + to_string(hp) + ")";
    this->gold = gold;
    this->hp = hp;
}

void Medicine::printInfo(int i) const {
    cout << i << ". " << name << ": " << gold << "골드\n";
}
