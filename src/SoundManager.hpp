#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <string>
#include <iostream>
#include <map>


#include "SDL2/SDL_mixer.h"
#include "Player.hpp"

class SoundManager {

    private:
        Mix_Music *music = nullptr;
        std::map<std::string, Mix_Chunk*> sounds;
        
    public:
        SoundManager();
        ~SoundManager();
        void playMusic(std::string path);
        void playSound(std::string soundName);
        void insertSound(std::string path, std::string soundName);
        void waitForPlayerInput(std::shared_ptr<Player> player);
};


#endif // SOUND_MANAGER_H