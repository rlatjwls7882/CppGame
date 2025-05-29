#include "Imp.h"

Imp::Imp() {
    hp = getRandomInt(20, 35);
    atk = getRandomInt(10, 18);
    exp = getRandomInt(20, 35);
    gold = getRandomInt(15, 25);
    name = "юсга";
}
