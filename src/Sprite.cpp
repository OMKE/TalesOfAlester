#include "Sprite.hpp"


Sprite::Sprite(std::shared_ptr<SpriteSheet> spritesheet, int width, int height)
    :  IDrawable(), IMovable(), spritesheet(spritesheet) {
        
        state = Sprite::IDLE; // postavljamo pocetni state na idle_blinking
        this->spritesheet = spritesheet;

        spriteRect = new SDL_Rect();
        spriteRect->x = 0;
        spriteRect->y = 0;
        spriteRect->w = width;
        spriteRect->h = height;

    }
Sprite::~Sprite(){ delete spriteRect; }
void Sprite::setState(short int state){ this->state = state; }
short int Sprite::getState(){ return this->state; }


void Sprite::move(int destinationX){
    spriteRect->x += destinationX;
}




