#include "Engine.h"

#define NUMBER_COINS 10

GameEngine::GameEngine() {
    fps = FPS;
    frame_duration = FRAME_DURATION;
    game_running = true;

    player = new SpriteManager();
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

        background = new TileHandler(game_renderer);

        int x = 200;
        for (int i = 0; i < NUMBER_COINS; i++) {
            Coin* new_coin = new Coin("./images/coin2.png", x, game_renderer);
            coins.push_back(new_coin);
            x += 200;
        }

        counter = new CoinCounter("./images/coin2.png", game_renderer);

}

void GameEngine::handleInput() {
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) { game_running = false; }

        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_RIGHT:
                    player->setState("running");
                    background->scroll();
                    for (int i = 0; i < NUMBER_COINS; i++) {
                        coins[i]->handleMovement();
                        if (coins[i]->handleCollision(player->getPos())) {
                            counter->addCoin();
                        } 
                    }
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
                    break;
                default:
                    player->setState("idle");

            }
        }
    }
}

void GameEngine::updateMechanics() {
    player->updateMovement();
    for (int i = 0; i < NUMBER_COINS; i++) {
        
        coins[i]->update();
    }
}

void GameEngine::render() {
    SDL_RenderClear(game_renderer);

    background->renderBackground();

    for (int i = 0; i < NUMBER_COINS; i++) {
        coins[i]->render();
    }

    counter->render();
    
    player->render(game_renderer);
    SDL_RenderPresent(game_renderer);
}