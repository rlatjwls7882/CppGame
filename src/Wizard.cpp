#include<iostream>

#include "Wizard.h"

using namespace std;

    /**
     * 마법사 초기 설정
     * 레벨: 1
     * 체력: 60
     * 최대 체력: 60
     * 공격력: 10
     * 방어력: -5
     * 경험치: 0
     */
Wizard::Wizard() : Wizard("무명") {}

Wizard::Wizard(string name) {
    this->name = name;
    level = 1;
    hp = maxHp = 60;
    atk = 10;
    exp = 0;
    plusHp = 10;
    plusAtk = 6;
	defense = -5;
    plusDefense = 0;
    gold = 0;
    type = "[마법사] ";
}

void Wizard::levelUp() {
    cout << "레벨업: " << level << " -> " << level + 1 << '\n'
         << "최대 체력: " << maxHp << " -> " << maxHp + plusHp << '\n'
         << "체력: " << hp << " -> " << hp + plusHp << '\n'
         << "공격력: " << atk << " -> " << atk + plusAtk << "\n\n";
    level++;
    hp += plusHp;
    maxHp += plusHp;
    atk += plusAtk;
}

void Wizard::displayInfo() const {
    cout << "------ " << type << name << " ------\n"
         << "레벨: " << level << "\n"
         << "경험치: " << exp << " / 50\n"
         << "체력: " << hp << " / " << maxHp << "\n"
         << "공격력: " << atk << "\n"
		 << "방어력: " << defense << "\n"
         << "골드: " << gold << "\n\n";
}

void Wizard::saveCharacter() {
    ofstream ofs("character.txt");
    ofs << type
        << name << ' '
        << level << ' '
        << hp << ' '
        << maxHp << ' '
        << atk << ' '
        << exp << ' '
        << gold << ' '
        << defense << ' ';
    ofs.close();
}

void Wizard::loadCharacter() {
    try {
        ifstream ifs("character.txt");
        ifs >> type >> name >> level >> hp >> maxHp >> atk >> exp >> gold >> defense;
        type += ' ';

        if(ifs.fail()) {
            cout << "캐릭터 불러오기 실패!\n";
            throw runtime_error("파일 읽기 실패");
        }
        cout << "캐릭터 불러오기 완료!\n";
    } catch(const exception&) {
        throw runtime_error("저장된 게임이 없습니다.");
    }
}
