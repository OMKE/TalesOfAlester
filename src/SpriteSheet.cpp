
#include "SpriteSheet.hpp"


SpriteSheet::SpriteSheet(std::ifstream &is, SDL_Renderer *renderer){
    std::string path;
    std::string animationName;
    int numberOfFrames;

    is >> path >> animationName >> numberOfFrames;

    // std::cout << path << ", " << animationName << ", " << numberOfFrames << std::endl;
    std::vector<Rect*> rects;
    for(size_t i = 0; i < numberOfFrames; i++){
        rects.push_back(new Rect(is));
    }

    


}