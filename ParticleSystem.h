#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <vector>

using namespace std;

#define MAX_PARTS 8

class Particle {

    private:
    
        SDL_Rect obj_rect;
        SDL_Texture* obj_texture;
        SDL_Surface* obj_surface;

        float x_pos;
        float y_pos;
        float x_vel;
        float y_vel;

        int width;
        int height;

        int state;
        int lifetime;

        SDL_Renderer* obj_renderer;

    public:

        Particle() {
            state = 0;
        }

        void init(const char* graphic, SDL_Renderer* renderer, int start_x, int start_y, int width, int height, int lifetime, float x_vel, float y_vel);

        void handleMovement();

        void update();

        void render();
};

class ParticleEmitter {

    private:
        vector<Particle*> particles;

    public:
    
        ParticleEmitter();

        void pe_init(const char* graphic, SDL_Renderer* renderer, int start_x, int start_y, int width, int height, int lifetime);

        void pe_handleMovement();

        void pe_update();

        void pe_render();

        void pe_quit();
};


#endif