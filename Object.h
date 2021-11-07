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

        SDL_Renderer* obj_renderer;
    
    public:
        GameObject();

        void setRect(int x);      

        void collisionResponse();

        void render();

};



#endif