#include "TalesOfAlester.hpp"


TalesOfAlester::TalesOfAlester(std::string name, std::string release)
    : name{name}, release{release}{
        engine = new Engine(name);
        engine->loop();
    }


TalesOfAlester::~TalesOfAlester(){
    delete engine;
    delete sheet;
}


