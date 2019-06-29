#ifndef PLAYER_H
#define PLAYER_H


#include "Sprite.hpp"
#include "KeyboardEventListener.hpp"
#include "Timer.hpp"
#include "Camera.hpp"
#include "Background.hpp"

class Player : public Sprite, public KeyboardEventListener, public Timer{
    private:
        std::shared_ptr<Background> background;
    public:
        Player(std::shared_ptr<SpriteSheet> sheet, int width = 128, int height = 128, std::shared_ptr<Background> bg = nullptr);
        ~Player();
        virtual void draw(SDL_Renderer *renderer) override;
        virtual void move(int dX, int dY) override;
        virtual void start() override;
        virtual void listenForKeyboardEvent(SDL_KeyboardEvent &event) override;
        



};


#endif // PLAYER_H