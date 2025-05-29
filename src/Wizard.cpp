#include<iostream>

#include "Wizard.h"

using namespace std;

    /**
     * ������ �ʱ� ����
     * ����: 1
     * ü��: 60
     * �ִ� ü��: 60
     * ���ݷ�: 10
     * ����: -5
     * ����ġ: 0
     */
Wizard::Wizard() : Wizard("����") {}

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
    type = "[������] ";
}

void Wizard::levelUp() {
    cout << "������: " << level << " -> " << level + 1 << '\n'
         << "�ִ� ü��: " << maxHp << " -> " << maxHp + plusHp << '\n'
         << "ü��: " << hp << " -> " << hp + plusHp << '\n'
         << "���ݷ�: " << atk << " -> " << atk + plusAtk << '\n\n';
    level++;
    hp += plusHp;
    maxHp += plusHp;
    atk += plusAtk;
}

void Wizard::displayInfo() const {
    cout << "------ " << type << name << " ------\n"
         << "����: " << level << "\n"
         << "����ġ: " << exp << " / 50\n"
         << "ü��: " << hp << " / " << maxHp << "\n"
         << "���ݷ�: " << atk << "\n"
		 << "����: " << defense << "\n"
         << "���: " << gold << "\n\n";
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
            cout << "ĳ���� �ҷ����� ����!\n";
            throw runtime_error("���� �б� ����");
        }
        cout << "ĳ���� �ҷ����� �Ϸ�!\n";
    } catch(const exception&) {
        throw runtime_error("����� ������ �����ϴ�.");
    }
}