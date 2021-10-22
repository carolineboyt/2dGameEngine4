#include "Object.h"

GameObject::GameObject() {
    texture = NULL;
    surface = NULL;
}

void GameObject::render(SDL_Renderer* objectRenderer) {
    texture = SDL_CreateTextureFromSurface(objectRenderer, surface);

    SDL_RenderCopy(objectRenderer, texture, NULL, &object);
}