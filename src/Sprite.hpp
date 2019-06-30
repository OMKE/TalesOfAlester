#ifndef SPRITE_H
#define SPRITE_H

#include <fstream>

#include <memory>
#include "SpriteSheet.hpp"
#include "Rect.hpp"
#include "IDrawable.hpp"
#include "IMovable.hpp"

class Sprite : public IDrawable, public IMovable {

    protected:
        std::shared_ptr<SpriteSheet> spriteSheet;
        SDL_Rect *spriteRect {nullptr};
        SDL_RendererFlip flip {SDL_FLIP_HORIZONTAL};
        int initialFrame;
        int frameCounter;
        int frameSkip;
        int state;
        enum State: int { IDDLE_RIGHT = 0, IDDLE_LEFT = 1, LEFT = 2, RIGHT = 3, JUMP = 4, JUMP_SLASH =54, RUN_LEFT = 6, RUN_RIGHT=7, ATTACK = 8};
        
    public:
        Sprite(std::shared_ptr<SpriteSheet> sheet, int width = 128, int height = 128);
        ~Sprite();
        virtual void draw(SDL_Renderer *renderer) = 0;
        virtual void move(int dX, int dY);
        int getSpriteRectX();
        int getSpriteRectY();
        int getSpriteRectW();
        int getSpriteRectH();
        int getInitialFrame();
        void setInitialFrame(int frame);
        int getState();
        void setState(int state);
        void setFrameSkip(int frameSkip);
        SDL_Rect* getSpriteRect();
};


#endif // SPRITE_H