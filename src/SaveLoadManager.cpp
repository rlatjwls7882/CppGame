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
        ifstream ifs("character.txt");
        string type; ifs >> type;

        if(type.compare("[����]")==0) {
            character = new Warrior();
		} else if(type.compare("[������]")==0) {
			character = new Wizard();
        }

        character->loadCharacter();
		dungeon.loadDungeon();
    } catch(const exception&) {
        throw runtime_error("����� ������ �����ϴ�.");
    }
    cout << "���� �ҷ����� �Ϸ�!\n";
}
