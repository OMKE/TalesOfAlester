#include "TalesOfAlester.hpp"

TalesOfAlester::TalesOfAlester(std::string name, std::string release)
    : name {name}, release{release}{
        engine = std::make_unique<Engine>(name);
        engine->loop();
    }
