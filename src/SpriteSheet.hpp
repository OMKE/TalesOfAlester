#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

// testing
#include "Rect.hpp"


typedef std::vector<Rect*> Rects;
class SpriteSheet {
    private:
        SDL_Texture *texture {nullptr};    
        std::map<std::string, Rects> animations;
    public:
        SpriteSheet(std::ifstream &is, SDL_Renderer *renderer);
        ~SpriteSheet();
        int getNumberOfFramesPerAnimation(std::string animationName);
        void drawRect(SDL_Renderer *renderer, std::string animationName, int frame, SDL_Rect *destRect);
        SDL_Texture* getTexture();
        std::map<std::string, Rects> getAnimations();


};


#endif // SPRITESHEET_H