#pragma once
#include<iostream>
#include<string>
#include<fstream>

#include "Character.h"
#include "Monster.h"

using namespace std;

   /**
    * 캐릭터 초기 설정
    * 레벨: 1
    * 체력: 100
    * 최대 체력: 100
    * 공격력: 10
    * 경험치: 0
    */
Character::Character() : Character("무명") {}

Character::Character(string name) {
    this->name = name;
    level = 1;
    hp = maxHp = 100;
    atk = 10;
    exp = 0;
    gold = 0;
    plusHp = 10;
    plusAtk = 5;
    type = "[캐릭터] ";
}

void Character::killMonster(Character*& target) {
    exp += target->exp;
    gold += target->gold;
    cout << "승리! 경험치" << target->exp << ", 골드 " << target->exp << " 획득!\n\n";

    while(exp >= 50) {
        exp -= 50;
        levelUp();
    }
}

void Character::killMonster(Monster*& target) {
    exp += target->exp;
    gold += target->gold;
    cout << "\n승리! 경험치" << target->exp << ", 골드 " << target->gold << " 획득!\n\n";

    while(exp >= 50) {
        exp -= 50;
        levelUp();
    }
}

void Character::levelUp() {
    int nextAtk = atk + plusAtk;
    cout << "레벨업: " << level << " -> " << level + 1 << '\n'
         << "최대 체력: " << maxHp << " -> " << maxHp + plusHp << '\n'
         << "체력: " << hp << " -> " << hp + plusHp << '\n'
         << "공격력: " << atk << " -> " << nextAtk << '\n\n';
    level++;
    hp += plusHp;
    maxHp += plusHp;
    atk = nextAtk;
}

bool Character::damageLog() const {
    cout << type << name << "(은/는) 공격을 받았다.\n"
         << type << name << "의 체력이 " << hp << "로 감소했다.\n";
    if(!isAlive()) {
        cout << type << name << "(은/는) 사망했다.\n";
        return false;
    }
    return true;
}

bool Character::takeDamage(int damage) {
    hp = max(hp - damage, 0);
    return damageLog();
}

bool Character::attack(Character*& target) const {
    cout << type << name << "의 공격!\n";
    return target->takeDamage(atk);
}

bool Character::attack(Monster*& target) const {
    cout << type << name << "의 공격!\n";
    return target->takeDamage(atk);
}

bool Character::isAlive() const {
    return hp > 0;
}

void Character::displayInfo() const {
    cout << "------ " << type << name << " ------\n"
         << "레벨: " << level << "\n"
         << "경험치: " << exp << " / 50\n"
         << "체력: " << hp << " / " << maxHp << "\n"
         << "공격력: " << atk << "\n"
         << "골드: " << gold << "\n\n";
}

void Character::saveCharacter() {
    ofstream ofs("character.txt");
    ofs << type
        << name << ' '
        << level << ' '
        << hp << ' '
        << maxHp << ' '
        << atk << ' '
        << exp << ' '
        << gold << ' ';
    ofs.close();
}

void Character::loadCharacter() {
    try {
        ifstream ifs("character.txt");
        ifs >> type >> name >> level >> hp >> maxHp >> atk >> exp >> gold;
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

int Character::getRandomInt(int min, int max) {
    return rand() % (max-min+1) + min;
}

bool Character::useMedicine(int hp, int gold) {
    if(this->gold < gold) {
        cout << "골드가 부족합니다.\n\n";
        return false;
    }

    int nextHp = min(this->hp + hp, maxHp);
    cout << type << name << "이(가) 회복 물약을 사용했습니다.\n"
         << "체력이 " << this->hp << "에서 " << nextHp << " 로 변화했습니다.\n\n";
	
    this->gold -= gold;
    this->hp = nextHp;
    return true;
}
