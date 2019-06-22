
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
            animations[animationName].push_back(std::make_shared<Rect>(is));
        }
        // For destructor so we keep trakc of animations and its rects
        //animationNames.push_back(animationName);
        
    }
    // for(auto animation : animations["walking"]){
    //     std::cout << animation->getTileW() << ", " << animation->getTileH() << std::endl;
    // }
    

}
// SpriteSheet::~SpriteSheet(){
//     for(auto animationName : animationNames){
//         for(auto animation : animations[animationName]){
//             delete animation;
//         }
//     }

// }

void SpriteSheet::drawRect(SDL_Renderer *renderer, std::string animationName, int frame,  SDL_Rect *destRect){
    SDL_RenderCopy(renderer, texture, animations[animationName][frame]->getTile(), destRect);
}
void SpriteSheet::drawFlippedRect(SDL_Renderer *renderer, std::string animationName, int frame,  SDL_Rect *destRect, SDL_RendererFlip flip){
    SDL_RenderCopyEx(renderer, texture, animations[animationName][frame]->getTile(), destRect,0, NULL, flip);
}

SDL_Texture* SpriteSheet::getTexture(){ return this->texture; }
std::map<std::string, Rects> SpriteSheet::getAnimations(){ return this->animations; }



