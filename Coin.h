#ifndef COIN_H
#define COIN_H

#include "ParticleSystem.h"
#include "Object.h"

class Coin: public GameObject {
    private:
        void setRect(int x);
        ParticleEmitter* particles;
        const char* filename;
        bool collided;

    public:
        Coin(const char* filename, int x, SDL_Renderer* obj_renderer);

        void handleMovement();

        void update();

        bool handleCollision(int);

        void collisionResponse();

        void render();
        
};

#endif