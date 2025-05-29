#pragma once

#include "Character.h"

class Dungeon;

class SaveLoadManager {
public:
    void saveGame(Character*& character, Dungeon& dungeon);
    void loadGame(Character*& character, Dungeon& dungeon);
};
