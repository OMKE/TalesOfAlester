#include "Engine.hpp"


Engine::Engine(std::string windowTitle, int windowWidth, int windowHeight)
    : windowWidth{windowWidth}, windowHeight{windowHeight} {

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
    // Initializaiton
    std::ifstream is {"./assets/sheet.txt"};
    auto bg = std::make_shared<Background>("./assets/world/village.png", renderer);
    auto playerSpriteSheet = std::make_shared<SpriteSheet>(is, renderer, 2);
    auto enemySpriteSheet = std::make_shared<SpriteSheet>(is, renderer, 1);
    auto player = std::make_shared<Player>(playerSpriteSheet, 128, 128);
    auto enemy = std::make_shared<Enemy>(enemySpriteSheet, 128, 128);
    

    camera = std::make_shared<Camera>(windowWidth, windowHeight, bg, player);

    
        

    
    drawables.push_back(bg);
    drawables.push_back(player);
    drawables.push_back(camera);
    drawables.push_back(enemy);
    

    listeners.push_back(player);
    player->setFrameSkip(6);
    enemy->setFrameSkip(4);


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

        camera->follow();
        for(const auto drawable: drawables){
            drawable->draw(renderer);
        }
        
        
        
        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();
        if(frameEnd - frameStart < maxDelay){
            SDL_Delay(maxDelay - (frameEnd - frameStart));
        }
    }

    


     
    
}   
