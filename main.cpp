#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

#include "Engine.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

const int fps = 60;
const int frame_duration = 1000 / fps;

int main() {

    Uint32 this_start_time;
    Uint32 this_duration;

    GameEngine *engine = new GameEngine();
    engine->init();

    while(engine->getGameRunning()){

        this_start_time = SDL_GetTicks();

        engine->handleInput();
        engine->updateMechanics();
        engine->render();

        this_duration = SDL_GetTicks() - this_start_time;

        if (this_duration < frame_duration) {
            SDL_Delay(frame_duration - this_duration);
        }
    }
//   Uint32 this_start_time, this_duration;
  
//   GameEngine *engine = new GameEngine();
//   engine->init();

//   while(engine->getGameRunning()){

//     this_start_time = SDL_GetTicks();

//     engine->handleInput();
//     engine->updateMechanics();
//     engine->render();

//     this_duration = SDL_GetTicks() - this_start_time;

//     if (this_duration < FRAME_DURATION) {
//       SDL_Delay(FRAME_DURATION - this_duration);
//     }
//   }

//   delete(engine);

  return 0;
}