#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "SDL2/SDL.h"

// testing
#include "Rect.hpp"


typedef std::vector<Rect*> Rects;
class SpriteSheet {
    private:
        SDL_Texture *texture {nullptr};    
        std::map<std::string, Rects> animations;
    public:
        SpriteSheet(std::ifstream &is, SDL_Renderer *renderer);


};


#endif // SPRITESHEET_H