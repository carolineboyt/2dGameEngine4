#include "ParticleSystem.h"

void Particle::init(const char* graphic, SDL_Renderer* renderer, int start_x, int start_y, int width, int height, int lifetime, int x_vel, int y_vel) {

    obj_renderer = renderer;

    obj_surface = IMG_Load(graphic);
    obj_texture = SDL_CreateTextureFromSurface(obj_renderer, obj_surface);

    obj_rect.x = start_x;
    obj_rect.y = start_y;
    obj_rect.h = height;
    obj_rect.w = width;

    this->lifetime = lifetime;

    this->x_vel = x_vel;
    this->y_vel = y_vel;
}

void Particle::handleMovement() {
    if (lifetime > 0) {
        obj_rect.x -= 10;
    }
}

void Particle::update() {
    if (lifetime > 0) {
        obj_rect.x += x_vel;
        obj_rect.y += y_vel;
        obj_rect.w = width/2 + width * (int) (10 * lifetime / 100);
        obj_rect.h = height/2 + height * (int) (10 * lifetime / 100);

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

    int x_vel = -1;
    int y_vel = 0;

    for (int i = 0; i < MAX_PARTS; i++) {
        particles[i]->init(graphic, renderer, start_x, start_y, width, height, lifetime, x_vel, y_vel);
        if (i + 1 < MAX_PARTS/2) {
            x_vel += 0.5;
            if (y_vel > -1) {
                y_vel -= 0.5;
            } else {
                y_vel += 0.5;
            }
        } else if (i + 1 == MAX_PARTS/2) {
            x_vel = 1;
            y_vel = 0;
        } else {
            x_vel -= 0.5;
            if (y_vel < 1) {
                y_vel += 0.5;
            } else {
                y_vel -= 0.5;
            }
        }
    }
}

void ParticleEmitter::pe_handleMovement() {
    for (int i = 0; i < MAX_PARTS; i++) {
        particles[i]->handleMovement();
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
