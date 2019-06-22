#include "Player.hpp"


Player::Player(std::shared_ptr<SpriteSheet> sheet, int width, int height)
    : Sprite(sheet, width, height), KeyboardEventListener(), destRect(new SDL_Rect) {
        state = State::IDDLE_RIGHT;
        destRect->x = 600;
        destRect->y = 600;
        destRect->w = width;
        destRect->h = height;
    }




void Player::draw(SDL_Renderer *renderer){
    

    if(state == State::IDDLE_RIGHT){
        
        spriteSheet->drawRect(renderer, "iddle_blinking", initialFrame, destRect);
        
        if(frameCounter%frameSkip == 0) {
            initialFrame++;
            if(initialFrame >= 17) {
                initialFrame = 0;
            }
            frameCounter = 0;
        }
    } else if (state == State::IDDLE_LEFT){
        spriteSheet->drawFlippedRect(renderer, "iddle_blinking", initialFrame, destRect, flip);
        
        if(frameCounter%frameSkip == 0) {
            initialFrame++;
            if(initialFrame >= 17) {
                initialFrame = 0;
            }
            frameCounter = 0;
        }
    } 
    else if (state == State::RIGHT){
        
        spriteSheet->drawRect(renderer, "walking", initialFrame, destRect);
    
        if(frameCounter%frameSkip == 0) {
            initialFrame++;
            if(initialFrame >= 14) {
                initialFrame = 0;
            }
            frameCounter = 0;
        }
    } else if (state == State::LEFT){
        
        spriteSheet->drawFlippedRect(renderer, "walking", initialFrame, destRect, flip);
    
        if(frameCounter%frameSkip == 0) {
            initialFrame++;
            if(initialFrame >= 14) {
                initialFrame = 0;
            }
            frameCounter = 0;
        }
    } else if (state == State::JUMP){
        
        spriteSheet->drawRect(renderer, "walking", initialFrame, destRect);
    
        if(frameCounter%frameSkip == 0) {
            initialFrame++;
            if(initialFrame >= 14) {
                initialFrame = 0;
            }
            frameCounter = 0;
        }
    }
    frameCounter++;

    
    
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
        this->destRect->y -= 20;
        break;    

    default:
        break;
    }

    
}



