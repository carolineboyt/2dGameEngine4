#include "CoinCounter.h"
#include <iostream>


CoinCounter::CoinCounter(const char* filename, SDL_Renderer* renderer) {
    if ( TTF_Init() < 0 ) {
        cout << "Error initializing SDL_ttf: " << TTF_GetError() << endl;
    }

    coins = 0;

    obj_renderer = renderer;

    surface = IMG_Load(filename);
    texture = SDL_CreateTextureFromSurface(obj_renderer, surface);

    object.x = 680;
    object.y = 17;
    object.w = 35;
    object.h = 35;

    text_surface = NULL;
    text_texture = NULL;

    text_rect.x = 720;
    text_rect.y = 10;
    text_rect.w = 55;
    text_rect.h = 50;

    updateTexture();
}

void CoinCounter::addCoin() {
    coins += 1;
    SDL_FreeSurface(text_surface);
    SDL_DestroyTexture(text_texture);
    updateTexture();   
}

void CoinCounter::updateTexture() {
    string num = to_string(coins);
    const char* numchar = num.c_str();
    const char* label = "x ";

    char message[12];
    strcat(message, label);
    strcat(message, numchar);

    TTF_Font* font = TTF_OpenFont("./fonts/munro.ttf", 18);
    if ( !font ) {
        cout << "Failed to load font: " << TTF_GetError() << endl;
    }
    SDL_Color White = {255, 255, 255};

    text_surface = TTF_RenderText_Solid(font, message, White);
    text_texture = SDL_CreateTextureFromSurface(obj_renderer, text_surface);
}

void CoinCounter::render() {
    
    SDL_RenderCopy(obj_renderer, texture, NULL, &object);
    SDL_RenderCopy(obj_renderer, text_texture, NULL, &text_rect);

}