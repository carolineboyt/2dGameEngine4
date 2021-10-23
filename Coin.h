#ifndef COIN_H
#define COIN_H

#include "Object.h"

class Coin: public GameObject {
    private:
        void setRect(int x);

    public:
        Coin(const char* filename, int x);

        void handleMovement() {
            object.x -= 10;
        }
        
};

#endif