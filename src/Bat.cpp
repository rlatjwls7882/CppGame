#include "Bat.h"

Bat::Bat() {
    hp = getRandomInt(5, 20);
    atk = getRandomInt(3, 8);
    exp = getRandomInt(5, 15);
    gold = getRandomInt(2, 10);
    name = "¹ÚÁã";
}