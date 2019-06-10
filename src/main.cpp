#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>

#include "Engine.hpp"


int main(int argc, char *args[]){
    
    try {
        Engine *engine = new Engine("Tales of Alester");
        engine->loop();
        delete engine;
        engine = nullptr;
    } catch (int &ex){
        std::cerr << ex << std::endl;
    }

    

    return 0;
}