#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Monster;

class Character {
protected:
    /**
     * type: ĳ���� Ÿ��
     * name: �̸�
     * level: ����
     * hp: ü��
     * maxHp: �ִ� ü��
     * atk: ���ݷ�
     * exp: ����ġ
     * plusHp: ������ �Ҷ����� ������ ü��
     * plusAtk: ������ �Ҷ����� ������ ���ݷ�
     * gold: ���� �ݾ�
     */
    string type;
    string name;
    int level, hp, maxHp, atk, exp, plusHp, plusAtk, gold;
public:
    /**
     * ĳ���� �ʱ� ����
     * ����: 1
     * ü��: 100
     * �ִ� ü��: 100
     * ���ݷ�: 10
     * ����ġ: 0
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