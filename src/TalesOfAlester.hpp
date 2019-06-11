#ifndef TALES_OF_ALESTER_H
#define TALES_OF_ALESTER_H

#include <memory>
#include <string>

#include "Engine.hpp"
#include "SpriteSheet.hpp"

/*
** TalesOfAlester **
desc:
    Ova nam klasa predstavlja igru Tales of Alester koja ce se zasnivati na engine-u
*/
class TalesOfAlester {
    private:
        std::string name;
        std::string release;
        std::unique_ptr<Engine> engine;
        std::unique_ptr<SpriteSheet> sheet;
        
        // Tileset - mapa svijeta
        // Players - playeri
        // Enemies 
        // Levels - leveli
    public:
        TalesOfAlester(std::string name = "Tales of Alester", std::string release = "0.1");
        ~TalesOfAlester();
};      


#endif // TALES_OF_ALESTER_H