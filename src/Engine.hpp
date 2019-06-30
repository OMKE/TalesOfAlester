#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <vector>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "SpriteSheet.hpp"
#include "Sprite.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "KeyboardEventListener.hpp"
#include "EventListener.hpp"
#include "Background.hpp"
#include "IDrawable.hpp"

#include "IMovable.hpp"



class Engine {
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        const int FPS = 60;
        std::vector<std::shared_ptr<EventListener>> listeners;
        std::vector<std::shared_ptr<IDrawable>> drawables;
        std::vector<std::shared_ptr<IMovable>> movables;
    
    public:
        Engine(std::string windowTitle, int windowWidth = 1000, int windowHeight = 1000);
        void loop();
        int rangeRandomAlg(int min, int max);
        ~Engine();
};


#endif // ENGINE_H