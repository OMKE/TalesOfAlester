#include "Engine.hpp"


Engine::Engine(std::string windowTitle, int windowWidth, int windowHeight){

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    window = SDL_CreateWindow(windowTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // if(!window) throw SDL_GetError();
    // if(!renderer) throw SDL_GetError();

}
Engine::~Engine(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    renderer = nullptr;
    window = nullptr;
    SDL_Quit();
}


void Engine::loop(){
    int maxDelay = 1000 / this->FPS;
    int frameStart = 0;
    int frameEnd = 0;
    bool running = true;


    SDL_Event event;
    std::ifstream is {"./assets/alester/sheet.txt"};
    auto spriteSheet = std::make_shared<SpriteSheet>(is, renderer);
    auto player = std::make_shared<Player>(spriteSheet);    
    listeners.push_back(player);
    player->setFrameSkip(6);

    while(running){
        frameStart = SDL_GetTicks();
        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                running = false;
            } else {
                for(size_t i = 0; i < listeners.size(); i++) {
                    listeners[i]->listen(event);
                    if(event.type == SDL_KEYUP){
                        if(player->getState() == 3){
                            player->setState(0);
                        } else if (player->getState() == 2){
                            player->setState(1);
                        } else if (player->getState() == 4) {
                            player->setState(4);
                        }
                        else {
                            player->setState(0);
                        }
                    }   
                }
            }
            
            
        }
        SDL_SetRenderDrawColor(renderer, 168, 230, 255, 255);
        SDL_RenderClear(renderer);

        
        player->draw(renderer);
        
        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();
        if(frameEnd - frameStart < maxDelay){
            SDL_Delay(maxDelay - (frameEnd - frameStart));
        }
    }
     
    
}   
