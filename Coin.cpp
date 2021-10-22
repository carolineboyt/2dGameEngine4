#include "Object.h"

class Coin: public GameObject {
    private:

    public:
        Coin(const char* filename, int x) {
            texture = NULL;
            surface = IMG_Load(filename);
            object.x = x;
            object.y = 0;
        }
};