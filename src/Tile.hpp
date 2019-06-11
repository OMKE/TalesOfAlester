#ifndef TILE_H
#define TILE_H

#include <iostream>
#include "SDL2/SDL.h"

class Tile {
    private:
        SDL_Rect *tileRect;
    public:
        Tile(int x, int y, int width, int height);
        Tile(std::istream &ifs);

        SDL_Rect* getTileRect();
        int getTileRectX();
        int getTileRectY();
        int getTileWidth();
        int getTileHeight();
        ~Tile();
};


#endif // TILE_H