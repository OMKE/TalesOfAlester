#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include <vector>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"



/*
** Engine **
desc:
    Glavna klasa koja instancira igru i postavlja scenu, sadrzi glavnu petlju, ucitava fajlove i prosljedjuje instanci igre
*/
class Engine {
    private:
        SDL_Window *window {nullptr};
        SDL_Renderer *renderer {nullptr};
        const int FPS = 60;
        int windowHeight;
        int windowWidth;
    public:
        Engine(std::string windowTitle, int windowHeight = 1000, int windowWidth = 1000);
        void loop();
        ~Engine();

};


#endif // ENGINE_H