#include "TalesOfAlester.hpp"

TalesOfAlester::TalesOfAlester(std::string name, std::string release)
    : name {name}, release{release}{
        try {
            engine = std::make_shared<Engine>(name);    
            engine->loop();
        } catch(const int &e){
            std::cerr << e << '\n';
        }
        
        
        
    }
