#include<iostream>

#include "Warrior.h"

using namespace std;

   /**
    * 전사 초기 설정
    * 레벨: 1
    * 체력: 120
    * 최대 체력: 120
    * 공격력: 6
    * 방어력: 1
    * 경험치: 0
    */
Warrior::Warrior() : Warrior("무명") {}

Warrior::Warrior(string name) {
    this->name = name;
    level = 1;
    hp = maxHp = 120;
    atk = 6;
    exp = 0;
    plusHp = 20;
    plusAtk = 3;
    plusDefense = 1;
	gold = 0;
    defense = 1;
    type = "[전사] ";
}

bool Warrior::takeDamage(int damage) {
    hp = max(hp - max(damage-defense, 0), 0);
    return damageLog();
}

void Warrior::levelUp() {
    cout << "레벨업: " << level << " -> " << level + 1 << '\n'
         << "최대 체력: " << maxHp << " -> " << maxHp + plusHp << '\n'
         << "체력: " << hp << " -> " << hp + plusHp << '\n'
         << "공격력: " << atk << " -> " << atk + plusAtk << '\n'
         << "방어력: " << defense << " -> " << defense + plusDefense << '\n\n';
    level++;
    hp += plusHp;
    maxHp += plusHp;
	defense += plusDefense;
    atk += plusAtk;
}

void Warrior::displayInfo() const {
    cout << "------ " << type << name << " ------\n"
         << "레벨: " << level << "\n"
         << "경험치: " << exp << " / 50\n"
         << "체력: " << hp << " / " << maxHp << "\n"
         << "공격력: " << atk << "\n"
         << "방어력: " << defense << "\n"
         << "골드: " << gold << "\n\n";
}

void Warrior::saveCharacter() {
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

void Warrior::loadCharacter() {
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