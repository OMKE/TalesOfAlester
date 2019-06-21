#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "SDL2/SDL.h"

// testing
#include "Rect.hpp"

class SpriteSheet {
    private:
        SDL_Texture *texture {nullptr};    
    public:
        SpriteSheet(std::ifstream &is, SDL_Renderer *renderer);


};


#endif // SPRITESHEET_H