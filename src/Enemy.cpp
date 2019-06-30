#include "Enemy.hpp"


Enemy::Enemy(std::shared_ptr<SpriteSheet> sheet, int width, int height)
    : Sprite(sheet, width, height) {

        state = State::LEFT;
        spriteRect->x = 200;
        
        
    }

Enemy::~Enemy(){

}

void Enemy::draw(SDL_Renderer *renderer){
    
    

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

void Enemy::move(){
    
}