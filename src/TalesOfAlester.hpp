
#ifndef TALES_OF_ALESTER_H
#define TALES_OF_ALESTER_H



#include <memory>
#include <string>
#include "Engine.hpp"

class TalesOfAlester {
    private:
        std::string name;
        std::string release;
        std::unique_ptr<Engine> engine;
    public:
        TalesOfAlester(std::string name = "Tales Of Alester", std::string relase = "0.1");
        ~TalesOfAlester() = default;
};


#endif // TALES_OF_ALESTER_H