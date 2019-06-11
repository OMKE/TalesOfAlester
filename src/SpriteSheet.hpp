#ifndef SPRITESHEET_H
#define SPRITESHEET_H


#include <iostream>
#include <fstream>
#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "Tile.hpp"

class SpriteSheet {
    
    private:   
        SDL_Texture *texture {nullptr};
    public:
        SpriteSheet(std::ifstream &ifs, SDL_Renderer *renderer);
        void drawTile(std::string animation, int frame, SDL_Rect *dest, SDL_Renderer *renderer);
        
        

};


#endif // SPRITESHEET_H