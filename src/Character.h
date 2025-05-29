#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Monster;

class Character {
protected:
    /**
     * type: 캐릭터 타입
     * name: 이름
     * level: 레벨
     * hp: 체력
     * maxHp: 최대 체력
     * atk: 공격력
     * exp: 경험치
     * plusHp: 레벨업 할때마다 오르는 체력
     * plusAtk: 레벨업 할때마다 오르는 공격력
     * gold: 소지 금액
     */
    string type;
    string name;
    int level, hp, maxHp, atk, exp, plusHp, plusAtk, gold;
public:
    /**
     * 캐릭터 초기 설정
     * 레벨: 1
     * 체력: 100
     * 최대 체력: 100
     * 공격력: 10
     * 경험치: 0
     */
    Character();
    Character(string name);
    void killMonster(Character*& target);
    void killMonster(Monster*& target);
    virtual void levelUp();
    bool damageLog() const;
    virtual bool takeDamage(int damage);
    bool attack(Character*& target) const;
    bool attack(Monster*& target) const;
    bool isAlive() const;
    virtual void displayInfo() const;
    virtual void saveCharacter();
    virtual void loadCharacter();
    int getRandomInt(int min, int max);
    bool useMedicine(int hp, int gold);
};