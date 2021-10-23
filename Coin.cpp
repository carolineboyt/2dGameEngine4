#include "Coin.h"

void Coin::setRect(int x) {
    object.x = x;
    object.y = 350;
    object.w = 60;
    object.h = 60;
}

Coin::Coin(const char* filename, int x) {
    texture = NULL;
    surface = IMG_Load(filename);
    setRect(x);
}

