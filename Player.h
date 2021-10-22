#ifndef PLAYER_H
#define PLAYER_H

#include "SpriteManager.h"

class Player: public SpriteManager {
    private:
        SDL_Rect running;
        SDL_Rect idle;
        SDL_Rect jumping;
    public:
        Player(const char* filename);

        void setPosition();

        void setState(string state);

        void updateMovement();

        void render(SDL_Renderer* object_renderer);

};

#endif