#include "SpriteManager.h"

SpriteManager::SpriteManager() {
    sprite_texture = NULL;
    sprite_surface = IMG_Load("./images/new-sprite.png");

    state = "idle";

    running.x = 0;
    running.y = 0;
    running.w = 525;
    running.h = 770;

    idle.x = 0;
    idle.y = 770;
    idle.w = 525;
    idle.h = 770;

    dest.x = 35;
    dest.y = 300;
    dest.h = 174;
    dest.w = 118;

    framecounter = 0;

}

void SpriteManager::updateMovement() {
    if (state == "running") {
        if (framecounter >= 36) {
            running.x = 0;
            framecounter = 0;
        } else if (framecounter != 0 && framecounter % 6 == 0) {
            running.x += 525;
            framecounter+=1; 
        } else {
            framecounter += 1;
        }
    } else {
        if (framecounter >= 100) {
            idle.x = 0;
            framecounter = 0;
        } else if (framecounter == 0 || (framecounter % 25 != 0 )) {
            
            framecounter+=1; 
        } else {
            idle.x += 525;
            framecounter += 1;
        }
    }
}

void SpriteManager::render(SDL_Renderer* object_renderer) {
    sprite_texture = SDL_CreateTextureFromSurface(object_renderer, sprite_surface);
    if (state == "running") {
        SDL_RenderCopy(object_renderer, sprite_texture, &running, &dest);
    } else {
        SDL_RenderCopy(object_renderer, sprite_texture, &idle, &dest);
    }
    
}