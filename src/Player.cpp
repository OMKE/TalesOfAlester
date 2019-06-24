#include "Player.hpp"


Player::Player(std::shared_ptr<SpriteSheet> sheet, int width, int height)
    : Sprite(sheet, width, height), KeyboardEventListener(), destRect(new SDL_Rect) {
        state = State::IDDLE_RIGHT;
        destRect->x = 10;
        destRect->y = 600;
        destRect->w = width;
        destRect->h = height;
    }




void Player::draw(SDL_Renderer *renderer){

    // reset helper ! delete, when it hit walls repeat
    if(this->destRect->y <= 0 || this->destRect->y >= 1000 || this->destRect->x >= 1000){
        this->destRect->y = 800;
        this->destRect->x = 10;
    }

    
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
        
        spriteSheet->drawRect(renderer, "iddle_blinking", initialFrame, destRect);
    } else if (state == State::IDDLE_LEFT){
        spriteSheet->drawFlippedRect(renderer, "iddle_blinking", initialFrame, destRect, flip);
    } else if (state == State::RIGHT){
        
        spriteSheet->drawRect(renderer, "walking", initialFrame, destRect);
    } else if (state == State::LEFT){
        
        spriteSheet->drawFlippedRect(renderer, "walking", initialFrame, destRect, flip);
    } else if (state == State::JUMP){
        // check time after it jumped, fall down after one second
    if((SDL_GetTicks() / 1000) - this->startTime >= 1){
        // provjeravamo da li je y koordiranta manja od pocetno zadane, tad znamo da je igrac skocio
            if(this->destRect->y <= 600){
                this->destRect->y += 30;
                this->destRect->x += 30;
                // reset start time variable so player is able to jump again
                startTime = 0;
            } 
    }
        spriteSheet->drawFlippedRect(renderer, "walking", initialFrame, destRect, flip);
    }
        
    
}

// Start jump
void Player::start(){
    if(!startTime){
        startTime = SDL_GetTicks() / 1000;
    }
    this->destRect->y -= 30;
    this->destRect->x += 30; // test
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
    this->destRect->x += dX;
    this->destRect->y += dY;
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
        this->destRect->x += 10;
        break;
    case SDLK_a:
        this->destRect->x -= 10;
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



