#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <memory>
#include "TalesOfAlester.hpp"


int main(int argc, char *args[]){
    
    try {
        std::unique_ptr<TalesOfAlester> game = std::make_unique<TalesOfAlester>("Tales of Alester");
    } catch (int &ex){
        std::cerr << ex << std::endl;
    }

    

    return 0;
}