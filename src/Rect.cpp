#include "Rect.hpp"



Rect::Rect(std::ifstream &is)
    : tile(new SDL_Rect){
        is >> tile->x >> tile->y >> tile->w >> tile->h;
    }
Rect::~Rect(){ delete tile; }

SDL_Rect* Rect::getTile(){ return this->tile; }
int Rect::getTileX(){ return this->tile->x; }
int Rect::getTileY(){ return this->tile->y; }
int Rect::getTileW(){ return this->tile->w; }
int Rect::getTileH(){ return this->tile->h; }