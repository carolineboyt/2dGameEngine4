#ifndef COINCOUNTER_H
#define COINCOUNTER_H

#include "Object.h"
#include <SDL2/SDL_ttf.h>
#include <string>

using namespace std;


class CoinCounter: public GameObject {
    private:
        int coins;

        SDL_Surface* text_surface;
        SDL_Texture* text_texture;
        SDL_Rect text_rect;

    public:

        CoinCounter(const char* filename, SDL_Renderer* renderer);

        void addCoin();

        void updateTexture();

        void render();
};

#endif