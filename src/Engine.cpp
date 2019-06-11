#include "Engine.hpp"



Engine::Engine(std::string windowTitle, int windowHeight, int windowWidth) 
    : windowTitle {windowTitle}, windowHeight {windowHeight}, windowWidth {windowWidth} {

        SDL_Init(SDL_INIT_VIDEO);
        IMG_Init(IMG_INIT_PNG);

        window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowHeight, windowWidth, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        
        if(!window) throw SDL_GetError();
        if(!renderer) throw SDL_GetError();
        
}

Engine::~Engine(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    delete ss;
    ss = nullptr;
    renderer = nullptr;
    window = nullptr;
    SDL_Quit();
}

void Engine::loop(){
    int maxDelay = 1000 / FPS;
    int frameStart = 0;
    int frameEnd = 0;

    bool running = true;
    SDL_Event event;
    std::string path {"./assets/alester/default/idle_blinking.png"};
    ss = new SpriteSheet(path, renderer);
    // drawables.push_back()

    while(running){
        frameStart = SDL_GetTicks();
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = false;
            } 
        }
        SDL_SetRenderDrawColor(renderer, 168, 230, 255, 255);
        SDL_RenderClear(renderer);

        ss->draw(renderer);

        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();
        if(frameEnd - frameStart < maxDelay){
            SDL_Delay(maxDelay - (frameEnd - frameStart));
        }
    }
}