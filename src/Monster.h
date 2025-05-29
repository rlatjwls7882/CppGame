#pragma once

#include "Character.h"

class Monster : public Character {
public:
    /**
     * ���� �ʱ� ����
     * ü��: 50
     * ���ݷ�: 10
     * ȹ�� ����ġ: 20
     * ȹ�� ���: 10
     */
    Monster();
    void displayMonster();
    void saveMonster(ofstream& ofs);
    void loadMonster(ifstream& ifs);
};