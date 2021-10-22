#ifndef TILEHANDLER_H
#define TILEHANDLER_H

#include <iostream>
#include <fstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <vector>
#include <string>
#include <sstream>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

using namespace std;

class TileHandler {
    private:

        int tilesize;
        vector< vector<int> > tiles;

        SDL_Texture* background_texture;
        SDL_Surface* tilesheet_surface;

        SDL_Rect wall_tile;
        SDL_Rect wall2_tile;
        SDL_Rect floor_tile;
        SDL_Rect subfloor_tile;

        SDL_Rect waterFountainTL_tile;
        SDL_Rect waterFountainTR_tile;
        SDL_Rect waterFountainBL_tile;
        SDL_Rect waterFountainBR_tile;

        SDL_Rect doorTL_tile;
        SDL_Rect doorTR_tile;
        SDL_Rect doorML_tile;
        SDL_Rect doorMR_tile;
        SDL_Rect doorBL_tile;
        SDL_Rect doorBR_tile;


        SDL_Rect window;
        SDL_Texture* window_texture;

        SDL_Rect screen;
        
    public:
        TileHandler();

        void readTileMap();

        void setTileRects();

        void scroll() {
            window.x += 10;
        }

        void renderBackground(SDL_Renderer* background_renderer);
};

#endif