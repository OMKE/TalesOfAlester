#ifndef PLAYER_H
#define PLAYER_H


#include "Sprite.hpp"
#include "KeyboardEventListener.hpp"



class Player : public Sprite, public KeyboardEventListener{
    private:
        
    public:
        Player(std::shared_ptr<SpriteSheet> sheet, int width = 128, int height = 128);
        ~Player();
        virtual void draw(SDL_Renderer *renderer) override;
        virtual void move(int dX, int dY) override;
        
        virtual void listenForKeyboardEvent(SDL_KeyboardEvent &event) override;
        



};


#endif // PLAYER_H