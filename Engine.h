#ifndef ENGINE_H
#define ENGINE_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "SpriteManager.h"
#include "TileHandler.h"
#include "Coin.h"
#include "CoinCounter.h"

using namespace std;

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define FPS 60
#define FRAME_DURATION 1000 / FPS

class GameEngine {
    private:
        SDL_Window* game_window;
        SDL_Renderer* game_renderer;
        bool game_running;
        int fps;
        int frame_duration;
        SpriteManager* player;
        TileHandler* background;
        vector<Coin*> coins;
        CoinCounter* counter;

    public:
        GameEngine();

        ~GameEngine();

        void init();

        bool getGameRunning() {
            return game_running;
        }

        void handleInput();

        void updateMechanics();

        void render();
};

#endif