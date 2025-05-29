#include "Snake.h"

Snake::Snake() {
    hp = getRandomInt(15, 30);
    atk = getRandomInt(5, 12);
    exp = getRandomInt(15, 25);
    gold = getRandomInt(5, 10);
    name = "¹ì";
}
