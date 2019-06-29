
#ifndef ENEMY_H
#define ENEMY_H

#include "Sprite.hpp"
#include "Background.hpp"

class Enemy : public Sprite {
    private:
        std::shared_ptr<Background> bg;
        int changedBgPos;
    public:
        Enemy(std::shared_ptr<SpriteSheet> sheet, int width = 128, int height = 128, std::shared_ptr<Background> bg = nullptr);
        ~Enemy();
        virtual void draw(SDL_Renderer *renderer) override;
        virtual void move(int dX, int dY) override;
        
};


#endif // ENEMY_H