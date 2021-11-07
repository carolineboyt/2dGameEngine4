#include "Object.h"

GameObject::GameObject() {
    texture = NULL;
    surface = NULL;
}



void GameObject::render() {
    texture = SDL_CreateTextureFromSurface(obj_renderer, surface);

    SDL_RenderCopy(obj_renderer, texture, NULL, &object);
}