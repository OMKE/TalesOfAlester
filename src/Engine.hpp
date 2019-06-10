#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"


/*
** Engine **
desc:
    Glavna klasa koja povezuje sve ostale, postavlja scenu, upravlja entitetima i njihovim atributima...
*/
class Engine {
    private:
        std::string windowTitle;
        SDL_Window *window {nullptr};
        SDL_Renderer *renderer {nullptr};
        const int FPS = 60;
        int windowHeight;
        int windowWidth;
    public:
        Engine(std::string windowTitle = "Game Engine", int windowHeight = 800, int windowWidth = 600);
        void loop();
        ~Engine();

};


#endif // ENGINE_H