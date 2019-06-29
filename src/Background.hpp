

#ifndef SCROLLING_BG
#define SCROLLING_BG


#include <iostream>
#include <string>

#include "SDL2/SDL_image.h"
#include "IDrawable.hpp"


class Background : public IDrawable {
    private:
        SDL_Texture *bg;
        SDL_Rect *srcRect;
        SDL_Rect *destRect;
        
        
    public:
        Background(std::string path, SDL_Renderer *renderer);
        ~Background();
        void draw(SDL_Renderer *renderer) override;
        
        void setSrcRectX(int x);
        int getSrcRectX();
        void setDestRectX(int x);
        int getDestRectX();
        




};  


#endif // SCROLLING_BG