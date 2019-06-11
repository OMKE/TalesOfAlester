#include "Tile.hpp"


Tile::Tile(std::istream &ifs){
    int x, y, width, height;
    ifs >> x >> y >> width >> height;
    tileRect = new SDL_Rect;
    tileRect->x = x;
    tileRect->y = y;
    tileRect->w = width;
    tileRect->h = height;
}

Tile::Tile(int x, int y, int width, int height){
        tileRect = new SDL_Rect;
        tileRect->x = x;
        tileRect->y = y;
        tileRect->w = width;
        tileRect->h = height;
    }

Tile::~Tile(){ delete tileRect; }

SDL_Rect* Tile::getTileRect(){ return tileRect; }
int Tile::getTileRectX(){ return tileRect->x; }
int Tile::getTileRectY(){ return tileRect->y; }
int Tile::getTileWidth(){ return tileRect->w; }
int Tile::getTileHeight(){ return tileRect->h; }
