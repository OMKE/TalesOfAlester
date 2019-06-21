
#include "SpriteSheet.hpp"


SpriteSheet::SpriteSheet(std::ifstream &is, SDL_Renderer *renderer){
    std::string path;
    std::string animationName;
    int numberOfFrames;

    // is >> path >> animationName >> numberOfFrames;
    is >> path;
    
    
    Rects rects;
    
    
    while(!is.eof()){
        is >> animationName;
        animations[animationName] = Rects();

        is >> numberOfFrames;
        


        for(size_t i = 0; i < numberOfFrames; i++){
            // Rect se konstruise tako sto prima inputStream i popunjava koordinate
            animations[animationName].push_back(new Rect(is));
        }
    }
    
    
    


}