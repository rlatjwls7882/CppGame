#pragma once

#include "Character.h"
#include "Monster.h"

class BattleManager {
public:
    void startBattle(Character*& character, Monster*& monster);
};