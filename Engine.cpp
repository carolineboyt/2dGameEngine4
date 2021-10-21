#include "Engine.h"

GameEngine::GameEngine() {
    fps = FPS;
    frame_duration = FRAME_DURATION;
    game_running = true;

    player = new SpriteManager();
    background = new TileHandler();
}

GameEngine::~GameEngine() {
    delete player;

    SDL_DestroyRenderer(game_renderer);
    SDL_DestroyWindow(game_window);

    IMG_Quit();
    SDL_Quit();
}

void GameEngine::init() {
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
}

void GameEngine::handleInput() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) { game_running = false; }

        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_RIGHT:
                    player->setState("running");
                    break;
                default:
                    player->setState("idle");
                    break;
            }
        }

        if (event.type == SDL_KEYUP) {
            switch (event.key.keysym.sym) {
                case SDLK_RIGHT:
                    player->setState("idle");
                    background->scroll();
                    break;
                default:
                    player->setState("idle");

            }
        }
    }
}

void GameEngine::updateMechanics() {
    player->updateMovement();
}

void GameEngine::render() {
    SDL_RenderClear(game_renderer);

    background->renderBackground(game_renderer);
    
    player->render(game_renderer);
    SDL_RenderPresent(game_renderer);
}