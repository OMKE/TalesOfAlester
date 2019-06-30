
#ifndef ENEMY_H
#define ENEMY_H

#include "Sprite.hpp"
#include "Background.hpp"

class Enemy : public Sprite {
    
    public:
        Enemy(std::shared_ptr<SpriteSheet> sheet, int width = 128, int height = 128);
        ~Enemy();
        virtual void draw(SDL_Renderer *renderer) override;
        virtual void move(int dX, int dY) override;
        virtual void move() override;
        
};


#endif // ENEMY_H