
#include "SpriteSheet.hpp"


SpriteSheet::SpriteSheet(std::ifstream &is, SDL_Renderer *renderer){
    std::string path;
    std::string animationName;
    int numberOfFrames;

    
    is >> path;

    SDL_Surface *surface = IMG_Load(path.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    
    
    
    
    
    while(!is.eof()){
        is >> animationName;
        animations[animationName] = Rects();

        is >> numberOfFrames;
        


        for(size_t i = 0; i < numberOfFrames; i++){
            // Rect se konstruise tako sto prima inputStream i popunjava koordinate
            // animations nam se sastoji od imena animacije i na njemu mapiranog vektora rectova(frejmova)
            // od kojih svaki ima koordinate
            animations[animationName].push_back(new Rect(is));
        }
    }
    

}

void SpriteSheet::drawRect(SDL_Renderer *renderer, std::string animationName, int frame,  SDL_Rect *destRect){
    SDL_RenderCopy(renderer, texture, animations[animationName][frame]->getTile(), destRect);
}

SDL_Texture* SpriteSheet::getTexture(){ return this->texture; }
std::map<std::string, Rects> SpriteSheet::getAnimations(){ return this->animations; }
int SpriteSheet::getNumberOfFramesPerAnimation(std::string animationName){
    return animations[animationName].size();
}


