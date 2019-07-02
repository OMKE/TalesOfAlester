
#include "SoundManager.hpp"

SoundManager::SoundManager(){



    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    

}

SoundManager::~SoundManager(){
    Mix_FreeMusic(music);

    for(auto& [key, val] : sounds){
        Mix_FreeChunk(val);
    }


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

void SoundManager::playSound(std::string soundName){
    Mix_Volume(-1, 50);
    Mix_PlayChannel(-1, sounds[soundName], 0);
}

void SoundManager::insertSound(std::string path, std::string soundName){
    // Mix_Chunk *sound = nullptr;
    Mix_Chunk *sound = Mix_LoadWAV(path.c_str());
    sounds[soundName] = sound;

}


void SoundManager::waitForPlayerInput(std::shared_ptr<Player> player){

    if(player->getState() == 8){
        playSound("swish");
    } else if(player->getState() == 2 || player->getState() == 3){
        playSound("walk");
    }

}