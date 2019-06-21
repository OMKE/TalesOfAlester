#include "Sprite.hpp"


Sprite::Sprite(SpriteSheet *sheet, int width, int height) : IDrawable(), IMovable(), 
    spriteSheet{sheet}, spriteRect(new SDL_Rect) {
        spriteRect->x = 0;
        spriteRect->y = 0;
        spriteRect->w = width;
        spriteRect->h = height;
        initialFrame = 0;
    }


void Sprite::draw(SDL_Renderer *renderer){
    SDL_Rect destRect {200,200, 128, 128};
    // SDL_RenderCopy(renderer, spriteSheet->getTexture(), spriteSheet->getAnimations()["iddle_blinking"][1]->getTile(), spriteRect);
    
    spriteSheet->drawRect(renderer, "iddle_blinking", initialFrame, &destRect);
    
}

void Sprite::move(int dX, int dY){
    spriteRect->x += dX;
    spriteRect->y += dY;
}

// Getters and Setters
int Sprite::getSpriteRectX(){ return this->spriteRect->x; }
int Sprite::getSpriteRectW(){ return this->spriteRect->y; }
int Sprite::getSpriteRectY(){ return this->spriteRect->w; }
int Sprite::getSpriteRectH(){ return this->spriteRect->h; }
int Sprite::getState(){ return this->state; }
void Sprite::setState(int state){ this->state = state; }


int Sprite::getNumberOfAnimationsFromSpriteSheet(std::string animationName){
    return this->spriteSheet->getNumberOfFramesPerAnimation(animationName);
}

// testing
int Sprite::getInitialFrame(){ return this->initialFrame; }
void Sprite::setInitialFrame(int frame){ this->initialFrame = frame; }