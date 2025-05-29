#include<iostream>
#include<vector>

#include "Character.h"
#include "Warrior.h"
#include "Wizard.h"
#include "SaveLoadManager.h"
#include "Dungeon.h"

using namespace std;

int main() {
    cout << "게임을 시작합니다.\n\n";
    SaveLoadManager saveLoadManager;
    Character *character = new Character;
    Dungeon dungeon;
    try {
        cout << "저장된 게임을 불러오시겠습니까?\n"
             << "1. 예\n"
             << "2. 아니오\n"
             << "선택: ";
        int choice; cin >> choice;
        cout << '\n';

        if(choice == 1) {
            saveLoadManager.loadGame(character, dungeon);
            cout << '\n';
        } else {
            cout << "새로운 캐릭터를 생성합니다.\n";
            cout << "캐릭터 이름을 입력하세요: ";
            string name; cin >> name;
            cout << '\n';
			
            cout << "캐릭터 타입을 선택하세요:\n"
				 << "1. 전사\n"
				 << "2. 마법사\n"
				 << "선택: ";
            int choice; cin >> choice;
            cout << '\n';

			switch (choice) {
			    case 1:
				    character = new Warrior(name);
				    break;
			    default:
				    character = new Wizard(name);
				    break;
			}
        }
    } catch (const exception&) {
        cout << "저장된 게임이 없습니다. 새로운 캐릭터를 생성합니다.\n";
        cout << "캐릭터 이름을 입력하세요: ";
        string name; cin >> name;
        cout << '\n';

        cout << "캐릭터 타입을 선택하세요:\n"
            << "1. 전사\n"
            << "2. 마법사\n"
            << "선택: ";
        cout << '\n';
        int choice; cin >> choice;

        switch (choice) {
            case 1:
                character = new Warrior(name);
                break;
            default:
                character = new Wizard(name);
                break;
        }
    }
    dungeon.enter(character);
}