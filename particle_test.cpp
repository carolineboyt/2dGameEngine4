#include "ParticleSystem.h"
#include "Engine.h"

const int fps = 60;
const int frame_duration = 1000 / fps;

int main() {

    SDL_Window* game_window;
    SDL_Renderer* game_renderer;
    ParticleEmitter* particles = new ParticleEmitter();
    SDL_Rect window;
        window.x = 0;
        window.y = 0;
        window.w = 800;
        window.h = 600;

    

     if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        cout << "Error initializing SDL: " << SDL_GetError() << endl;
    }

    IMG_Init(IMG_INIT_PNG);

    game_window = SDL_CreateWindow("my_game",
                SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED,
                SCREEN_WIDTH,
                SCREEN_HEIGHT, 0);
    game_renderer = SDL_CreateRenderer(game_window,-1,0);
    

    particles->pe_init("./images/coin2.png", game_renderer, 250, 350, 50, 50, 30);
    bool game_running = true;

    Uint32 this_start_time;
    Uint32 this_duration;

    while(game_running){

        this_start_time = SDL_GetTicks();

        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                game_running = false;
            }
        }
        particles->pe_update();

        SDL_RenderClear(game_renderer);
        SDL_SetRenderDrawColor(game_renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(game_renderer, &window);

        particles->pe_render();

        SDL_RenderPresent(game_renderer);

         this_duration = SDL_GetTicks() - this_start_time;

        if (this_duration < frame_duration) {
        SDL_Delay(frame_duration - this_duration);
        }

    }

    SDL_DestroyRenderer(game_renderer);
    SDL_DestroyWindow(game_window);

    IMG_Quit();
    SDL_Quit();

    

    return 0;
}