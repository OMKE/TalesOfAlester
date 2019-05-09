#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_Main.h"



using namespace std;


int main(int argc, char *argv[]){
    
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Tales of Alester", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    bool isRunning = true;
    SDL_Event e;

    while(isRunning){

        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
                isRunning = false;
            
        }

        SDL_RenderPresent(renderer);
    }
    

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    renderer = nullptr;
    window = nullptr;

    SDL_Quit();

    return 0;
}


