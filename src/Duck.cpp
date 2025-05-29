#include "Duck.h"

Duck::Duck() {
    hp = getRandomInt(2, 10);
    atk = getRandomInt(150, 200);
    exp = getRandomInt(5, 10);
    gold = getRandomInt(2, 10);
    name = "¿À¸®";
}