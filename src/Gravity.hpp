#ifndef GRAVITY_H
#define GRAVITY_H

#include <iostream>
#include <ctime>

#include "SDL2/SDL.h"



class Gravity {
    protected:
        float velocity = 2.0;
        float gravity = -2;

        

        float previousTime = 0;

        // Get current time
        float currentTime;

        
        
        

    public:
        // virtual void jump() = 0;
        
        

};

class Timer {
    protected:
        Uint32 startTime = 0;
        Uint32 timePassed;
    public:
        virtual void start() = 0;



};


#endif // GRAVITY_H