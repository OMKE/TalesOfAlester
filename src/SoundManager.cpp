
#include "SoundManager.hpp"

SoundManager::SoundManager(){



    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    

}

SoundManager::~SoundManager(){
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}


void SoundManager::playMusic(std::string path){
    if(Mix_PlayingMusic() == 0){
        music = Mix_LoadMUS(path.c_str());
        if(!music){
            std::cout << "Error: Failed to load background music!" << std::endl;
        }
        Mix_PlayMusic(music, -1);
    }
}