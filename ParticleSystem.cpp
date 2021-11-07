#include "ParticleSystem.h"

#include <iostream>

void Particle::init(const char* graphic, SDL_Renderer* renderer, int start_x, int start_y, int width, int height, int lifetime, float x_vel, float y_vel) {

    obj_renderer = renderer;

    obj_surface = IMG_Load(graphic);
    obj_texture = SDL_CreateTextureFromSurface(obj_renderer, obj_surface);

    x_pos = start_x;
    y_pos = start_y;

    this->width = width;
    this->height = height;

    obj_rect.x = x_pos;
    obj_rect.y = y_pos;
    obj_rect.h = height;
    obj_rect.w = width;

    this->lifetime = lifetime;

    this->x_vel = x_vel;
    this->y_vel = y_vel;
}

void Particle::update() {
    if (lifetime > 0) {
        x_pos += x_vel;
        y_pos += y_vel;

        // width = 
        // height = 

        obj_rect.x = x_pos;
        obj_rect.y = y_pos;
        obj_rect.w = width / 2 + width * lifetime/10;
        obj_rect.h = height / 2 + height * lifetime/10;

        // cout << "x: " << obj_rect.x << endl;
        // cout << "y: " << obj_rect.y << endl;

        lifetime -= 1;
    }
}

void Particle::render() {
    if (lifetime > 0) {
        SDL_RenderCopy(obj_renderer, obj_texture, NULL, &obj_rect);
    }
}

ParticleEmitter::ParticleEmitter() {
    for (int i = 0; i < MAX_PARTS; i++) {
        Particle* new_particle= new Particle();
        particles.push_back(new_particle);
    }
}

void ParticleEmitter::pe_init(const char* graphic, SDL_Renderer* renderer, int start_x, int start_y, int width, int height, int lifetime) {

    float x_vel = -10;
    float y_vel = 0;

    for (int i = 0; i < MAX_PARTS; i++) {
        particles[i]->init(graphic, renderer, start_x, start_y, width, height, lifetime, x_vel, y_vel);
        if (i + 1 < MAX_PARTS/2) {
            x_vel += 5;
            if (y_vel > -10) {
                y_vel -= 5;
            } else {
                y_vel += 5;
            }
        } else if (i + 1 == MAX_PARTS/2) {
            x_vel = 10;
            y_vel = 0;
        } else {
            x_vel -= 5;
            if (y_vel < 10) {
                y_vel += 5;
            } else {
                y_vel -= 5;
            }
        }
    }
}

void ParticleEmitter::pe_update() {
    for (int i = 0; i < MAX_PARTS; i++) {
        particles[i]->update();
    }
}

void ParticleEmitter::pe_render() {
    for (int i = 0; i < MAX_PARTS; i++) {
        particles[i]->render();
    }
}
