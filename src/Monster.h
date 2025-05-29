#pragma once

#include "Character.h"

class Monster : public Character {
public:
    /**
     * ¸ó½ºÅÍ ÃÊ±â ¼³Á¤
     * Ã¼·Â: 50
     * °ø°İ·Â: 10
     * È¹µæ °æÇèÄ¡: 20
     * È¹µæ °ñµå: 10
     */
    Monster();
    void displayMonster();
    void saveMonster(ofstream& ofs);
    void loadMonster(ifstream& ifs);
};