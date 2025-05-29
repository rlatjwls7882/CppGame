#include<iostream>
#include<vector>

#include "Character.h"
#include "Warrior.h"
#include "Wizard.h"
#include "SaveLoadManager.h"
#include "Dungeon.h"

using namespace std;

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

        if(choice == 1) {
            saveLoadManager.loadGame(character, dungeon);
            cout << '\n';
        } else {
            cout << "���ο� ĳ���͸� �����մϴ�.\n";
            cout << "ĳ���� �̸��� �Է��ϼ���: ";
            string name; cin >> name;
            cout << '\n';
			
            cout << "ĳ���� Ÿ���� �����ϼ���:\n"
				 << "1. ����\n"
				 << "2. ������\n"
				 << "����: ";
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
        cout << "����� ������ �����ϴ�. ���ο� ĳ���͸� �����մϴ�.\n";
        cout << "ĳ���� �̸��� �Է��ϼ���: ";
        string name; cin >> name;
        cout << '\n';

        cout << "ĳ���� Ÿ���� �����ϼ���:\n"
            << "1. ����\n"
            << "2. ������\n"
            << "����: ";
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