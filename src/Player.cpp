#include "Player.hpp"


Player::Player(std::shared_ptr<SpriteSheet> sheet, int width, int height, std::shared_ptr<Background> bg)
    : Sprite(sheet, width, height), KeyboardEventListener(), bg {bg} {

        

        state = State::IDDLE_RIGHT;
        spriteRect->x = 50;
        spriteRect->y = 603;
        

        
        
        
    }

Player::~Player(){

}


void Player::draw(SDL_Renderer *renderer){

    // reset helper ! delete, when it hit walls repeat
    // if(this->spriteRect->y <= 0 || this->spriteRect->y > 800 || this->spriteRect->x >= 1000){
    //     this->spriteRect->y = 600;
    //     this->spriteRect->x = 10;
    // }

    
    // Limits initial frame so it doesnt make overflow of vector of animations
    if(state == State::IDDLE_RIGHT || state == State::IDDLE_LEFT){
        if(initialFrame >= 16) {
            initialFrame = 0;
        }
    } else if(state == State::RIGHT || state == State::LEFT || state == State::JUMP){
        if(initialFrame >= 13) {
                initialFrame = 0;
        }
    }

    frameCounter++;
    
    if(frameCounter%frameSkip == 0) {
        initialFrame++;
        frameCounter = 0;
    }

    

    
    
    
    

    if(state == State::IDDLE_RIGHT){
        
        spriteSheet->drawRect(renderer, "iddle_blinking", initialFrame, spriteRect);
    } else if (state == State::IDDLE_LEFT){
        spriteSheet->drawFlippedRect(renderer, "iddle_blinking", initialFrame, spriteRect, flip);
    } else if (state == State::RIGHT){
        
        spriteSheet->drawRect(renderer, "walking", initialFrame, spriteRect);
    } else if (state == State::LEFT){
        
        spriteSheet->drawFlippedRect(renderer, "walking", initialFrame, spriteRect, flip);
    // } else if (state == State::JUMP){
        // check time after it jumped, fall down after one second
    // TODO popraviti kad se promijeni state da se vrati skok
    // if((SDL_GetTicks() / 1000) - this->startTime >= 1){
        // provjeravamo da li je y koordiranta manja od pocetno zadane, tad znamo da je igrac skocio
    //         if(this->spriteRect->y <= 600){
    //             this->spriteRect->y += 30;
    //             this->spriteRect->x += 30;
                // reset start time variable so player is able to jump again
    //             startTime = 0;
    //         } 
    // }
    //     spriteSheet->drawRect(renderer, "walking", initialFrame, spriteRect);
    }
    
}


    

/*
** move **
desc:
    defines method of moving the character(running has different speed than walking, jumping...)
params:
    dX - X coordinate of destination rectangle, 
    dY - Y coordinate of destination rectangle, 
return: void - 
*/
void Player::move(int dX, int dY){
    if(spriteRect->x <= 10 && dX == -10){
        return;
    }
    

    if(spriteRect->x <= 300 || spriteRect->x + dX <= 300 || dX < 0){
        if(dX < 0){
            spriteRect->x += dX;
            spriteRect->y += dY;    
        } else if (dX > 0) {
            spriteRect->x += dX / 3;
            spriteRect->y += dY / 3;
            
        }
        
        
    }
    
    if(dX > 0){
        this->bg->setSrcRectX(this->bg->getSrcRectX() + dX);
        this->bg->setDestRectX(this->bg->getDestRectX() - dX);
    } 
    

    
}

/*
** listenForKeyboardEvent **
desc:
    Waits for key presses and accordingly moves the character and changes states
params:
    event - structure that contains keyboard button information, 
return:  void - 
*/
void Player::listenForKeyboardEvent(SDL_KeyboardEvent &event){

    switch (event.keysym.sym)
    {
    case SDLK_d:
        state = State::RIGHT;
        move(10, 0);
        break;
    case SDLK_a:
        state = State::LEFT;
        move(-10,0);
        
        
        break;
    case SDLK_SPACE:        
        
        state = State::JUMP;
        
        break;    

    default:
        break;
    }

    
}



