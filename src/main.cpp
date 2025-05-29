#include<iostream>
#include<vector>

#include "Character.h"
#include "Warrior.h"
#include "Wizard.h"
#include "SaveLoadManager.h"
#include "Dungeon.h"

using namespace std;

Character* createCharacter() {
    cout << "ĳ���� �̸��� �Է��ϼ���: ";
    string name; cin >> name;
    cout << '\n';

    cout << "ĳ���� Ÿ���� �����ϼ���:\n"
         << "1. ����\n"
         << "2. ������\n"
         << "����: ";
    int choice; cin >> choice;
    cout << '\n';

	switch(choice) {
	    case 1:
		    return new Warrior(name);
	    default:
		    return new Wizard(name);
	}
}

int main() {
    cout << "������ �����մϴ�.\n\n";
    SaveLoadManager saveLoadManager;
    Character *character = new Character;
    Dungeon dungeon;

    try {
        cout << "����� ������ �ҷ����ðڽ��ϱ�?\n"
             << "1. ��\n"
             << "2. �ƴϿ�\n"
             << "����: ";
        int choice; cin >> choice;
        cout << '\n';

		switch(choice) {
		    case 1:
                saveLoadManager.loadGame(character, dungeon);
                cout << '\n';
                break;
			default:
                cout << "���ο� ĳ���͸� �����մϴ�.\n";
                character = createCharacter();
                break;
        }
    } catch(const exception&) {
        cout << "����� ������ �����ϴ�. ���ο� ĳ���͸� �����մϴ�.\n";
        character = createCharacter();
    }
    dungeon.enter(character);
}