#ifndef SPRITE_H
#define SPRITE_H


#include <memory>

#include "IDrawable.hpp"
#include "IMovable.hpp"
#include "SpriteSheet.hpp"
#include "SDL2/SDL.h"

class Sprite : public IDrawable, public IMovable {
    private:
        std::shared_ptr<SpriteSheet> spritesheet;
        SDL_Rect *spriteRect;
        enum State:short int {IDLE, LEFT, RIGHT, JUMPIMG, KICKING, RUNNING_LEFT, RUNNING_RIGHT, HURT, DYING, SLASHING};
        short int state;
    public:
        Sprite(std::shared_ptr<SpriteSheet> spritesheet, int width, int height);
        
        void draw(SDL_Renderer *renderer) override; // IDrawable
        void move(int destinationX) override; // IMovable
        
        void setState(short int state);
        short int getState();
        SDL_Rect* getSpriteRect();
        
};  


#endif // SPRITE_H