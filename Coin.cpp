#include "Coin.h"

void Coin::setRect(int x) {
    object.x = x;
    object.y = 350;
    object.w = 60;
    object.h = 60;
}

Coin::Coin(const char* filename, int x, SDL_Renderer *obj_renderer) {
    this->filename = filename;

    surface = IMG_Load(filename);
    texture = SDL_CreateTextureFromSurface(obj_renderer, surface);

    setRect(x);

    collided = false;

    this->obj_renderer = obj_renderer;

    particles = new ParticleEmitter();

    
}

bool Coin::handleCollision(int player) {

    if (player - 50 >= object.x && !collided) {
        collisionResponse();
        return true;
    }
    return false;
}

void Coin::collisionResponse() {
    particles->pe_init(filename, obj_renderer, object.x + 30, object.y + 30, 25, 25, 30);
    collided = true;
}

void Coin::handleMovement() {
    if(!collided) {
        object.x -= 10;
    } else {
        particles->pe_handleMovement();
    }
}

void Coin::update() {
    if (collided) {
        particles->pe_update();
    }
}

void Coin::render() {
    
    if (!collided) {
        SDL_RenderCopy(obj_renderer, texture, NULL, &object);
    } else {
        particles->pe_render();
    }

}

