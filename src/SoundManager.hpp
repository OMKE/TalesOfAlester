#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include <string>
#include <iostream>

#include "SDL2/SDL_mixer.h"

class SoundManager {

    private:
        Mix_Music *music = nullptr;
        

    public:
        SoundManager();
        ~SoundManager();
        void playMusic(std::string path);
    
        

};


#endif // SOUND_MANAGER_H