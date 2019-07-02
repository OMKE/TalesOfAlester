#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <iostream>

#include "SDL2/SDL_ttf.h"

#include "IDrawable.hpp"

class Text : public IDrawable {

    private:
        SDL_Texture *texture {nullptr};
        TTF_Font *font {nullptr};
        std::string text;
        SDL_Rect *rect;
        SDL_Color color;
    public:
        Text(SDL_Renderer *renderer, int size, std::string text,  int posX, int posY, Uint8 R, Uint8 G, Uint8 B);
        ~Text();
        virtual void draw(SDL_Renderer *renderer);
        void setTextRectW(int w);
        void setTextRectH(int h);
        void setTextContent(std::string text);
        void setTextColor(Uint8 R, Uint8 G, Uint8 B);


};


#endif // TEXT_H