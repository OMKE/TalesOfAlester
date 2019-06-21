#ifndef ENGINE_H
#define ENGINE_H

#include <string>
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Engine {
    private:
        SDL_Window *window {nullptr};
        SDL_Renderer *renderer {nullptr};
        const int FPS = 60;
    public:
        Engine(std::string windowTitle, int windowWidth = 1000, int windowHeight = 1000);
        void loop();
        ~Engine();
};


#endif // ENGINE_H