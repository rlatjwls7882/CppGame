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
        character->loadCharacter();
		dungeon.loadDungeon();

        if(character->isWarrior()) {
            character = new Warrior();
		} else if(character->isWizard()) {
			character = new Wizard();
        }
        character->loadCharacter();
        cout << "캐릭터 불러오기 완료!\n";
        cout << "게임 불러오기 완료!\n";
    } catch(const exception&) {
        throw runtime_error("저장된 게임이 없습니다.");
    }
}
