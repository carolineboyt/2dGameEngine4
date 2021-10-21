#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <string>

using namespace std;

class SpriteManager {
    private:
        SDL_Rect running;
        SDL_Rect idle;
        SDL_Rect jumping;
        SDL_Texture* sprite_texture;
        SDL_Surface* sprite_surface;
        SDL_Rect dest;
        int framecounter;
        string state;
        

    public:

        SpriteManager();

        void setState(string state) {
            if (this->state != state) {
                this->state = state;
                idle.x = 0;
                running.x = 0;
            }
        }

        void updateMovement();

        void render(SDL_Renderer* object_renderer);
};

#endif