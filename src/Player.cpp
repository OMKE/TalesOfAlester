#include "Player.hpp"


Player::Player(SpriteSheet *sheet, int width, int height)
    : Sprite(sheet, width, height), KeyboardEventListener(), destRect(new SDL_Rect) {
        state = State::IDDLE;
        destRect->x = 600;
        destRect->y = 600;
        destRect->w = width;
        destRect->h = height;
    }

void Player::draw(SDL_Renderer *renderer){
    if(state == State::IDDLE){
        spriteSheet->drawRect(renderer, "iddle_blinking", initialFrame, destRect);
    }
}
void Player::move(int dX, int dY){
    this->destRect->x += dX;
    this->destRect->y += dY;
}

// FIXME preraditi u poll event, ovako ne valja i stvara segmentation fault
void Player::listen(SDL_KeyboardEvent &e){
    if(e.type == SDL_KEYDOWN){
        if(e.keysym.sym == SDLK_d){
            state = State::RIGHT;
        } else if (e.keysym.sym == SDLK_a){
            state = State::LEFT;
        } else if (e.keysym.sym == SDLK_SPACE){
            state = State::JUMP;
        } else if (e.keysym.sym == SDLK_LSHIFT && e.keysym.sym == SDLK_a){
            state = State::RUN_LEFT;
        } else if (e.keysym.sym == SDLK_LSHIFT && e.keysym.sym == SDLK_d){
            state = State::RUN_RIGHT;
        } else if (e.keysym.sym == SDLK_r){
            state = State::IDDLE;
        }  

    }
    
}