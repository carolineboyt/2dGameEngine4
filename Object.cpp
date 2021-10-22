#include "Object.h"

GameObject::GameObject(const char* filename) {
    texture = NULL;
    surface = IMG_Load(filename);
}

void GameObject::render(SDL_Renderer* objectRenderer) {
    texture = SDL_CreateTextureFromSurface(objectRenderer, surface);

    SDL_RenderCopy(objectRenderer, texture, NULL, &object);
}