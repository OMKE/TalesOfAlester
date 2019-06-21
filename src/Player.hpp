#ifndef PLAYER_H
#define PLAYER_H


#include "Sprite.hpp"
#include "KeyboardEventListener.hpp"

class Player : public Sprite, public KeyboardEventListener {
    private:
        SDL_Rect *destRect {nullptr};
    public:
        Player(SpriteSheet *sheet, int width = 128, int height = 128);
        virtual void draw(SDL_Renderer *renderer) override;
        virtual void move(int dX, int dY) override;
        virtual void listen(SDL_KeyboardEvent &e) override;




};


#endif // PLAYER_H