#include<iostream>
#include<thread>

#include "BattleManager.h"

using namespace std;

void BattleManager::startBattle(Character*& character, Monster*& monster) {
    while(true) {
        if(!character->attack(monster)) return;
        cout << '\n';
        this_thread::sleep_for(chrono::seconds(1));

        if(!monster->attack(character)) return;
        cout << '\n';
        this_thread::sleep_for(chrono::seconds(1));
    }
}
