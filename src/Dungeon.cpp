#include<iostream>
#include<vector>
#include<thread>
#include<random>

#include "Dungeon.h"

using namespace std;

int randInt(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

Dungeon::Dungeon() {
    int cnt = randInt(6, 19);
    for(int i=0;i<cnt;i++) {
        Monster* monster;
        switch(randInt(0, 9)) {
            case 0:
                monster = new Goblin();
                break;
            case 1:
                monster = new Bat();
                break;
            case 2:
                monster = new Wolf();
                break;
		    case 3:
			    monster = new Snake();
			    break;
		    case 4:
			    monster = new Scorpion();
			    break;
		    case 5:
			    monster = new Orc();
			    break;
		    case 6:
			    monster = new Imp();
			    break;
		    case 7:
			    monster = new Duck();
			    break;
            default:
                monster = new Slime();
                break;
        }
        monsters.push_back(monster);
    }
}

void Dungeon::enter(Character*& character) {
    cout << "던전에 입장중입니다.\n\n";
    this_thread::sleep_for(chrono::seconds(1));

    BattleManager BattleManager;
    SaveLoadManager SaveLoadManager;
    while(monsters.size()) {
        character->displayInfo();
        cout << "현재 남은 몬스터 수: " << monsters.size() << "\n"
             << "0. 세이브\n"
             << "1. 상점에 가기\n";

        for(int i=0;i<monsters.size();i++) {
            cout << i+2 << ". ";
            monsters[i]->displayMonster();
        }

        cout << "선택 : ";
        int choice; cin >> choice;
        cout << '\n';

        Store store;
        switch(choice) {
            case 0:
			    SaveLoadManager.saveGame(character, *this);
				return;
			case 1:
                while(!store.empty()) {
                    store.displayItems();
                    cout << "구매할 아이템 번호를 선택하세요: ";
                    int choice; cin >> choice;
					cout << '\n';

                    if(choice==0) break;
                    store.buyItem(choice, character);
                }
				break;
			default:
                int index = choice - 2;
                Monster*& target = monsters[index];
                BattleManager.startBattle(character, target);

                if(!character->isAlive()) {
                    cout << '\n';
                    character->displayInfo();
                    return;
                }
                character->killMonster(target);
                monsters.erase(monsters.begin()+index);
				break;
        }
        cout << '\n';
    }
    cout << "던전을 클리어했습니다!\n";
}

void Dungeon::saveDungeon() {
    try {
        ofstream ofs("monster.txt");
        ofs << monsters.size() << '\n';
        for(Monster* monster : monsters) {
            monster->saveMonster(ofs);
        }
	} catch(const exception&) {
		throw runtime_error("던전 저장 실패");
    }
}

void Dungeon::loadDungeon() {
    try {
        ifstream ifs("monster.txt");
        int cnt; ifs >> cnt;
        monsters.clear();

        while(cnt--) {
			monsters.push_back(new Monster);
            monsters.back()->loadMonster(ifs);
        }
        cout << "던전 불러오기 완료!\n";
    } catch(const exception&) {
        throw runtime_error("저장된 던전이 없습니다.");
    }
}
