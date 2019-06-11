#include "SpriteSheet.hpp"


SpriteSheet::SpriteSheet(std::ifstream &ifs, SDL_Renderer *renderer){
    std::string imagePath;
    ifs >> imagePath;
    SDL_Surface *surface = IMG_Load(imagePath.c_str());
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    
}
// SpriteSheet::drawTile(std::string animation, int frame, SDL_Rect *dest, SDL_Renderer *renderer){
//     SDL_RenderCopy(renderer, texture, )
// }

// void SpriteSheet::draw(SDL_Renderer *renderer) {
//     int seconds = SDL_GetTicks() / 1000;
//     int sprite = seconds % 4;
    
//     SDL_Rect srcRect { sprite * 400 , sprite * 560, 400, 560};
//     SDL_Rect destRect {0, 0, srcRect.w - 200, srcRect.h - 300};
   
//     SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
// }
