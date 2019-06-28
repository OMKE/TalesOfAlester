
#include "SpriteSheet.hpp"


SpriteSheet::SpriteSheet(std::istream &is, SDL_Renderer *renderer){
    std::string path;
    std::string animation;
    int totalFrames;
    is >> path;

    SDL_Surface *surface = IMG_Load(path.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    while(!is.eof()) {
        is >> animation;
        animations[animation] = Rects();

        is >> totalFrames;
        for(int i = 0; i < totalFrames; i++) {
            animations[animation].push_back(std::make_shared<Rect>(is));
        }
    }

    
    

}



void SpriteSheet::drawRect(SDL_Renderer *renderer, std::string animationName, int frame,  SDL_Rect *destRect){
    SDL_RenderCopy(renderer, texture, animations[animationName][frame]->getTile(), destRect);
}
void SpriteSheet::drawFlippedRect(SDL_Renderer *renderer, std::string animationName, int frame,  SDL_Rect *destRect, SDL_RendererFlip flip){
    SDL_RenderCopyEx(renderer, texture, animations[animationName][frame]->getTile(), destRect,0, NULL, flip);
}

SDL_Texture* SpriteSheet::getTexture(){ return this->texture; }
std::map<std::string, Rects> SpriteSheet::getAnimations(){ return this->animations; }




