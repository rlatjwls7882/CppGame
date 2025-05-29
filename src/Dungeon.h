#pragma once
#include<vector>

#include "Character.h"
#include "BattleManager.h"
#include "SaveLoadManager.h"
#include "Store.h"

#include "Monster.h"
#include "Goblin.h"
#include "Slime.h"
#include "Bat.h"
#include "Wolf.h"
#include "Snake.h"
#include "Scorpion.h"
#include "Orc.h"
#include "Imp.h"
#include "Duck.h"

class Dungeon {
protected:
    vector<Monster*> monsters;
public:
    Dungeon();
    void enter(Character*& character);
    void saveDungeon();
    void loadDungeon();
};