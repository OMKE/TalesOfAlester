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
    // Initializaiton
    std::ifstream is {"./assets/sheet.txt"};
    auto bg = std::make_shared<Background>("./assets/world/village.png", renderer);
    auto playerSpriteSheet = std::make_shared<SpriteSheet>(is, renderer, 2);
    auto enemySpriteSheet = std::make_shared<SpriteSheet>(is, renderer, 1);
    auto player = std::make_shared<Player>(playerSpriteSheet, 128, 128, bg);
    // auto enemy = std::make_shared<Enemy>(enemySpriteSheet, 128, 128, bg, 2000);


    std::vector<std::shared_ptr<Enemy>> enemies;
    int numOfEnemies = rand() % 30 + 1; 
    // int randomPosition = rand() % 1000 + 2000; // generates random position for enemy
    // std::cout << randomPosition << std::endl;
    std::cout << "Number of enemies: " << numOfEnemies << std::endl;
    for(int i = 0; i < numOfEnemies; i++){
        enemies.push_back(std::make_shared<Enemy>(enemySpriteSheet, 128, 128, bg, rangeRandomAlg(2000, 10000)));
    }

    
        

    
    drawables.push_back(bg);
    drawables.push_back(player);
    

    for(auto enemy:enemies){
        enemy->setFrameSkip(4);
        drawables.push_back(enemy);
    }

    movables.push_back(player);
    

    
    

    listeners.push_back(player);
    player->setFrameSkip(6);
    // enemy->setFrameSkip(4);


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
                            player->setIsMoving(false);
                        } else if (player->getState() == 2){
                            player->setState(1);
                            player->setIsMoving(false);
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

        for(const auto movable: movables){
            movable->move();
        }
        
        for(auto enemy: enemies){
            enemy->listenForPlayerMove(player);
            }
        
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


int Engine::rangeRandomAlg (int min, int max){
    int n = max - min + 1;
    int remainder = RAND_MAX % n;
    int x;
    do{
        x = rand();
    }while (x >= RAND_MAX - remainder);
    return min + x % n;
}


bool Player::getIsMoving(){ return this->isMoving; }
void Player::setIsMoving(bool move){ this->isMoving = move; }
