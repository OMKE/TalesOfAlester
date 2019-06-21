
#include "KeyboardEventListener.hpp"

void KeyboardEventListener::listen(SDL_Event &e){
    if(e.type == SDL_KEYDOWN || e.type == SDL_KEYUP){
        listen(e);
    }
}