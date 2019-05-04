#ifndef GAMES_MAPMAN
#define GAMES_MAPMAN
#include <map>
#include <string>
#include "instrvector.hpp"

namespace games {
    class mapman {
    private:
        void*   core;
        void    init_funcmap();
        void    init_membmap();
        void    init_vectmap();
        void    init_funvmap();
        void    init_varimap();

    public:
        mapman(void* param): core(param) {
            init_vectmap(); //contains accessible data vector references
            init_membmap(); //contains accessible objects
            init_funcmap(); //contains accessible instructions
            init_funvmap(); //contains accessible instruction vectors
            init_varimap(); //contains accessible global variables
        }

        static std::map <std::string, games::instruction> funcmap;
        static std::map <std::string, games::instrvector> funvmap;
        static std::map <std::string, unsigned int>       varimap;
        static std::map <std::string, void*> membmap;
        static std::map <std::string, void*> vectmap;
    };
};

#endif
