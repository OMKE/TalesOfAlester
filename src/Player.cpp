#include "Player.hpp"


Player::Player(std::shared_ptr<SpriteSheet> sheet, int width, int height, std::shared_ptr<Background> bg)
    : Sprite(sheet, width, height), KeyboardEventListener(), Timer() , background {bg} {

        

        state = State::IDDLE_RIGHT;
        spriteRect->x = 10;
        spriteRect->y = 600;
        

        
        
        
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
    } else if (state == State::JUMP){
        // check time after it jumped, fall down after one second
    // TODO popraviti kad se promijeni state da se vrati skok
    if((SDL_GetTicks() / 1000) - this->startTime >= 1){
        // provjeravamo da li je y koordiranta manja od pocetno zadane, tad znamo da je igrac skocio
            if(this->spriteRect->y <= 600){
                this->spriteRect->y += 30;
                this->spriteRect->x += 30;
                // reset start time variable so player is able to jump again
                startTime = 0;
            } 
    }
        spriteSheet->drawRect(renderer, "walking", initialFrame, spriteRect);
    }

    
        
    
}

// Start jump
void Player::start(){
    if(!startTime){
        startTime = SDL_GetTicks() / 1000;
    }
    // this->spriteRect->y -= 30;
    // this->spriteRect->x += 30; // test
    move(30, -30);
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
    
    this->spriteRect->x += dX;
    this->spriteRect->y += dY;
    this->background->setSrcRectX(this->background->getSrcRectX() + dX);
    this->background->setDestRectX(this->background->getDestRectX() - dX);
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
        this->state = State::RIGHT;
        move(10, 0);
        break;
    case SDLK_a:
        move(-10,0);
        state = State::LEFT;
        break;
    case SDLK_SPACE:
        state = State::JUMP;
        start();
        break;    

    default:
        break;
    }

    
}



