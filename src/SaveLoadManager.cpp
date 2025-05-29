#pragma once
#include<iostream>

#include "SaveLoadManager.h"
#include "Dungeon.h"
#include "Warrior.h"
#include "Wizard.h"

using namespace std;

void SaveLoadManager::saveGame(Character*& character, Dungeon& dungeon) {
    character->saveCharacter();
	dungeon.saveDungeon();
    cout << "게임 저장 완료!\n";
}

void SaveLoadManager::loadGame(Character*& character, Dungeon& dungeon) {
    try {
        ifstream ifs("character.txt");
        string type; ifs >> type;

        if(type.compare("[전사]")==0) {
            character = new Warrior();
		} else if(type.compare("[마법사]")==0) {
			character = new Wizard();
        }

        character->loadCharacter();
		dungeon.loadDungeon();
    } catch(const exception&) {
        throw runtime_error("저장된 게임이 없습니다.");
    }
    cout << "게임 불러오기 완료!\n";
}
