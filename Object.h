#ifndef OBJECT_H
#define OBJECT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

using namespace std;

class GameObject {
    protected:
        SDL_Surface* surface;
        SDL_Texture* texture;
        SDL_Rect object;
    
    public:
        GameObject();

        void setRect();

        void handleAnimation();

        void render(SDL_Renderer* objectRenderer);

};



#endif