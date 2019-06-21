#ifndef SPRITE_H
#define SPRITE_H

#include <fstream>


#include "SpriteSheet.hpp"
#include "Rect.hpp"
#include "IDrawable.hpp"
#include "IMovable.hpp"

class Sprite : public IDrawable, public IMovable {

    protected:
        SpriteSheet *spriteSheet {nullptr};
        SDL_Rect *spriteRect {nullptr};
        int initialFrame;
        int state;
        enum State: int { IDDLE = 0, LEFT = 1, RIGHT = 2, JUMP = 3, JUMP_SLASH = 4, RUN_LEFT = 5, RUN_RIGHT=6, ATTACK = 7};
    public:
        Sprite(SpriteSheet *sheet, int width = 128, int height = 128);
        virtual void draw(SDL_Renderer *renderer) override;
        virtual void move(int dX, int dY) override;
        int getSpriteRectX();
        int getSpriteRectY();
        int getSpriteRectW();
        int getSpriteRectH();
        int getInitialFrame();
        void setInitialFrame(int frame);
        int getNumberOfAnimationsFromSpriteSheet(std::string animationName);
        int getState();
        void setState(int state);
};


#endif // SPRITE_H