#ifndef KEYBOARD_EVENT_LISTENER_H
#define KEYBOARD_EVENT_LISTENER_H

#include "EventListener.hpp"

class KeyboardEventListener : public EventListener {
    public:
        virtual void listen(SDL_Event &e);
        virtual void listen(SDL_KeyboardEvent &e)=0;
};


#endif // KEYBOARD_EVENT_LISTENER_H