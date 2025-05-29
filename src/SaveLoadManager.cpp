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
    cout << "���� ���� �Ϸ�!\n";
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
        cout << "ĳ���� �ҷ����� �Ϸ�!\n";
        cout << "���� �ҷ����� �Ϸ�!\n";
    } catch(const exception&) {
        throw runtime_error("����� ������ �����ϴ�.");
    }
}
