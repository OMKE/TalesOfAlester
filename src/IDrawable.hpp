#ifndef I_DRAWABLE_H
#define I_DRAWABLE_H


#include "SDL2/SDL.h"

/*
** IDrawable **
desc:
    Interface
    Ovaj interfejs ce naslijediti svaka klasa koja moze biti iscrtana na ekranu
*/
class IDrawable {
    public:
        /*
        ** draw **
        desc:
            Iscrtava objekat na ekran
        return: void 
        */
        virtual void draw(SDL_Renderer *renderer) = 0;
        
};


#endif // I_DRAWABLE_H