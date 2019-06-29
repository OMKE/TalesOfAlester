#include "Enemy.hpp"


Enemy::Enemy(std::shared_ptr<SpriteSheet> sheet, int width, int height)
    : Sprite(sheet, width, height), bg{bg} {

        state = State::LEFT;
        spriteRect->x = 100;
        changedBgPos = bg->getSrcRectX();
        
    }

Enemy::~Enemy(){

}

void Enemy::draw(SDL_Renderer *renderer){
    
    if(changedBgPos == bg->getSrcRectX()){
        move(10, 0);
    }

    if(state == State::LEFT){
        if(initialFrame >= 20){
            initialFrame = 0;
        }
    }
    frameCounter++;
    if(frameCounter%frameSkip == 0){
        initialFrame++;
        frameCounter = 0;
    }


    if(state == State::LEFT){
        spriteSheet->drawRect(renderer, "walking", initialFrame, spriteRect);
    }
}

void Enemy::move(int dX, int dY){
    spriteRect->x += dX;
    spriteRect->y += dY;    
}