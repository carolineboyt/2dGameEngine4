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
        TileHandler() {
            tilesize = 105;

            readTileMap();
            setTileRects();

            window.x = 0;
            window.y = 0;
            window.w = SCREEN_WIDTH;
            window.h = SCREEN_HEIGHT;

            screen.x = 0;
            screen.y = 0;
            screen.w = SCREEN_WIDTH;
            screen.h = SCREEN_HEIGHT;

            background_texture = NULL;
            tilesheet_surface = IMG_Load("./images/tilesheet5.png");
        }

        void readTileMap() {
            ifstream tileMapFile ("./tilemap.txt");

            string line;
            int x = 0;
            int y = 0;
            
            while (getline(tileMapFile, line)) {
                size_t pos = 0;
                string token;
                vector<int> tile_x;
                while ((pos = line.find(" ")) != string::npos) {
                    
                    token = line.substr(0, pos);
                    int tile = stoi(token);
                    tile_x.push_back(tile);
                    // cout << tile << " ";
                    line.erase(0, pos + 1);
                }
                tiles.push_back(tile_x);
            }

        }

        void setTileRects() {
            

            // SDL_Rect wall_tile;
            wall_tile.x = 0;
            wall_tile.y = 0;
            wall_tile.w = tilesize;
            wall_tile.h = tilesize;

            wall2_tile.x = 0;
            wall2_tile.y = 105;
            wall2_tile.w = tilesize;
            wall2_tile.h = tilesize;

            // SDL_Rect floor_tile;
            floor_tile.x = 105;
            floor_tile.y = 0;
            floor_tile.w = tilesize;
            floor_tile.h = tilesize;

            // SDL_Rect subfloor_tile;
            subfloor_tile.x = 210;
            subfloor_tile.y = 0;
            subfloor_tile.w = tilesize;
            subfloor_tile.h = tilesize;

            // SDL_Rect waterFountainTL_tile;
            waterFountainTL_tile.x = 315;
            waterFountainTL_tile.y = 0;
            waterFountainTL_tile.w = tilesize;
            waterFountainTL_tile.h = tilesize;

            // SDL_Rect waterFountainTR_tile;
            waterFountainTR_tile.x = 420;
            waterFountainTR_tile.y = 0;
            waterFountainTR_tile.w = tilesize;
            waterFountainTR_tile.h = tilesize;

            // SDL_Rect waterFountainBL_tile;
            waterFountainBL_tile.x = 315;
            waterFountainBL_tile.y = 105;
            waterFountainBL_tile.w = tilesize;
            waterFountainBL_tile.h = tilesize;

            // SDL_Rect waterFountainBR_tile;
            waterFountainBR_tile.x = 420;
            waterFountainBR_tile.y = 105;
            waterFountainBR_tile.w = tilesize;
            waterFountainBR_tile.h = tilesize;

            // SDL_Rect doorTL_tile;
            doorTL_tile.x = 105;
            doorTL_tile.y = 105;
            doorTL_tile.w = tilesize;
            doorTL_tile.h = tilesize;

            // SDL_Rect doorTR_tile;
            doorTR_tile.x = 210;
            doorTR_tile.y = 105;
            doorTR_tile.w = tilesize;
            doorTR_tile.h = tilesize;

            // SDL_Rect doorML_tile;
            doorML_tile.x = 105;
            doorML_tile.y = 210;
            doorML_tile.h = tilesize;
            doorML_tile.w = tilesize;

            // SDL_Rect doorMR_tile;
            doorMR_tile.x = 210;
            doorMR_tile.y = 210;
            doorMR_tile.h = tilesize;
            doorMR_tile.w = tilesize;

            // SDL_Rect doorBL_tile;
            doorBL_tile.x = 105;
            doorBL_tile.y = 315;
            doorBL_tile.w = tilesize;
            doorBL_tile.h = tilesize;

            // SDL_Rect doorBR_tile;
            doorBR_tile.x = 210;
            doorBR_tile.y = 315;
            doorBR_tile.w = tilesize;
            doorBR_tile.h = tilesize;
        }

        // void createBackgroundSurface(SDL_Renderer* background_renderer) {
        //     background_texture = SDL_CreateTextureFromSurface(background_renderer, tilesheet_surface);
        //     window_texture = SDL_CreateTexture(background_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
        //     SDL_SetRenderTarget(background_renderer, window_texture);

        //     SDL_Rect dest;

        //     dest.x = window.x;
        //     dest.y = window.y;
        //     dest.w = 75;
        //     dest.h = 75;

        //     SDL_SetRenderDrawColor(background_renderer, 255, 255, 255, 255);
        //     SDL_RenderFillRect(background_renderer, &window);

        //     for (int i = 0; i < tiles.size(); i++) {
        //         vector<int> tile_x = tiles.at(i);
        //         for (int j = 0; j < tile_x.size(); j++) {
        //             switch (tiles.at(i).at(j)) {
        //                 case 0:
        //                     SDL_RenderCopy(background_renderer, background_texture, &wall_tile, &dest);
        //                     break;
        //                 case 1:
        //                     SDL_RenderCopy(background_renderer, background_texture, &floor_tile, &dest);
        //                     break;
        //                 case 2:
        //                     SDL_RenderCopy(background_renderer, background_texture, &subfloor_tile, &dest);
        //                     break;
        //                 case 3:
        //                     SDL_RenderCopy(background_renderer, background_texture, &wall_tile, &dest);
        //                     SDL_RenderCopy(background_renderer, background_texture, &waterFountainTL_tile, &dest);
        //                     break;
        //                 case 4:
        //                     SDL_RenderCopy(background_renderer, background_texture, &wall_tile, &dest);
        //                     SDL_RenderCopy(background_renderer, background_texture, &waterFountainTR_tile, &dest);
        //                     break;
        //                 case 5:
        //                     SDL_RenderCopy(background_renderer, background_texture, &wall2_tile, &dest);
        //                     break;
        //                 case 6:
        //                     SDL_RenderCopy(background_renderer, background_texture, &wall2_tile, &dest);
        //                     SDL_RenderCopy(background_renderer, background_texture, &doorTL_tile, &dest);
        //                     break;
        //                 case 7:
        //                     SDL_RenderCopy(background_renderer, background_texture, &wall2_tile, &dest);
        //                     SDL_RenderCopy(background_renderer, background_texture, &doorTR_tile, &dest);
        //                     break;
        //                 case 8:
        //                     SDL_RenderCopy(background_renderer, background_texture, &wall2_tile, &dest);
        //                     SDL_RenderCopy(background_renderer, background_texture, &waterFountainBL_tile, &dest);
        //                     break;
        //                 case 9:
        //                     SDL_RenderCopy(background_renderer, background_texture, &wall2_tile, &dest);
        //                     SDL_RenderCopy(background_renderer, background_texture, &waterFountainBR_tile, &dest);
        //                     break;
        //                 case 11:
        //                     SDL_RenderCopy(background_renderer, background_texture, &wall_tile, &dest);
        //                     SDL_RenderCopy(background_renderer, background_texture, &doorML_tile, &dest);
        //                     break;
        //                 case 12:
        //                     SDL_RenderCopy(background_renderer, background_texture, &wall_tile, &dest);
        //                     SDL_RenderCopy(background_renderer, background_texture, &doorMR_tile, &dest);
        //                     break;
        //                 case 16:
        //                     SDL_RenderCopy(background_renderer, background_texture, &wall2_tile, &dest);
        //                     SDL_RenderCopy(background_renderer, background_texture, &doorBL_tile, &dest);
        //                     break;
        //                 case 17:
        //                     SDL_RenderCopy(background_renderer, background_texture, &wall2_tile, &dest);
        //                     SDL_RenderCopy(background_renderer, background_texture, &doorBR_tile, &dest);
        //                     break;
        //                 default:
        //                     SDL_RenderCopy(background_renderer, background_texture, &wall_tile, &dest);
        //                     break;
        //             }
        //             dest.x += 75;
        //         } 
        //         dest.y += 75;
        //         dest.x = window.x;
        //     }
        // }

        void scroll() {
            window.x += 10;
        }

        void renderBackground(SDL_Renderer* background_renderer) {
            background_texture = SDL_CreateTextureFromSurface(background_renderer, tilesheet_surface);
            window_texture = SDL_CreateTexture(background_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);
            SDL_SetRenderTarget(background_renderer, window_texture);

            SDL_Rect dest;

            dest.x = window.x;
            dest.y = window.y;
            dest.w = 75;
            dest.h = 75;

            SDL_SetRenderDrawColor(background_renderer, 255, 255, 255, 255);
            SDL_RenderFillRect(background_renderer, &window);

            for (int i = 0; i < tiles.size(); i++) {
                vector<int> tile_x = tiles.at(i);
                for (int j = 0; j < tile_x.size(); j++) {
                    switch (tiles.at(i).at(j)) {
                        case 0:
                            SDL_RenderCopy(background_renderer, background_texture, &wall_tile, &dest);
                            break;
                        case 1:
                            SDL_RenderCopy(background_renderer, background_texture, &floor_tile, &dest);
                            break;
                        case 2:
                            SDL_RenderCopy(background_renderer, background_texture, &subfloor_tile, &dest);
                            break;
                        case 3:
                            SDL_RenderCopy(background_renderer, background_texture, &wall_tile, &dest);
                            SDL_RenderCopy(background_renderer, background_texture, &waterFountainTL_tile, &dest);
                            break;
                        case 4:
                            SDL_RenderCopy(background_renderer, background_texture, &wall_tile, &dest);
                            SDL_RenderCopy(background_renderer, background_texture, &waterFountainTR_tile, &dest);
                            break;
                        case 5:
                            SDL_RenderCopy(background_renderer, background_texture, &wall2_tile, &dest);
                            break;
                        case 6:
                            SDL_RenderCopy(background_renderer, background_texture, &wall2_tile, &dest);
                            SDL_RenderCopy(background_renderer, background_texture, &doorTL_tile, &dest);
                            break;
                        case 7:
                            SDL_RenderCopy(background_renderer, background_texture, &wall2_tile, &dest);
                            SDL_RenderCopy(background_renderer, background_texture, &doorTR_tile, &dest);
                            break;
                        case 8:
                            SDL_RenderCopy(background_renderer, background_texture, &wall2_tile, &dest);
                            SDL_RenderCopy(background_renderer, background_texture, &waterFountainBL_tile, &dest);
                            break;
                        case 9:
                            SDL_RenderCopy(background_renderer, background_texture, &wall2_tile, &dest);
                            SDL_RenderCopy(background_renderer, background_texture, &waterFountainBR_tile, &dest);
                            break;
                        case 11:
                            SDL_RenderCopy(background_renderer, background_texture, &wall_tile, &dest);
                            SDL_RenderCopy(background_renderer, background_texture, &doorML_tile, &dest);
                            break;
                        case 12:
                            SDL_RenderCopy(background_renderer, background_texture, &wall_tile, &dest);
                            SDL_RenderCopy(background_renderer, background_texture, &doorMR_tile, &dest);
                            break;
                        case 16:
                            SDL_RenderCopy(background_renderer, background_texture, &wall2_tile, &dest);
                            SDL_RenderCopy(background_renderer, background_texture, &doorBL_tile, &dest);
                            break;
                        case 17:
                            SDL_RenderCopy(background_renderer, background_texture, &wall2_tile, &dest);
                            SDL_RenderCopy(background_renderer, background_texture, &doorBR_tile, &dest);
                            break;
                        default:
                            SDL_RenderCopy(background_renderer, background_texture, &wall_tile, &dest);
                            break;
                    }
                    dest.x += 75;
                } 
                dest.y += 75;
                dest.x = window.x;
            }
            SDL_SetRenderTarget(background_renderer, NULL);
            SDL_RenderCopy(background_renderer, window_texture, &window, &screen);
        }

};

#endif