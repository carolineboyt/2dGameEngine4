#include "Object.h"

class Coin: public GameObject {
    private:
        void setRect(int x) {
            object.x = x;
            object.y = 350;
            object.w = 60;
            object.h = 60;
        }

    public:
        Coin(const char* filename, int x) {
            texture = NULL;
            surface = IMG_Load(filename);
            setRect(x);
        }

        void handleMovement() {
            object.x -= 10;
        }
        
};