#ifndef GAMES_MAPMAN
#define GAMES_MAPMAN
#include <string>
#include <map>
#include "instrvector.hpp"

namespace games {
    class mapman {
    private:
        void*   core;
        void    init_funcmap();
        void    init_membmap();
        void    init_vectmap();
        void    init_parsmap();
        void    init_varimap();

    public:
        mapman(void* param): core(param) {
            init_vectmap(); //contains accessible data vector references
            init_membmap(); //contains accessible objects
            init_funcmap(); //contains accessible functions
            init_parsmap(); //contains accessible parse defaults, run before the parsing itself (adds new functions, members, so on)
            init_varimap(); //contains accessible global variables
        }

        static std::map <std::string, games::instrvector> funcmap;
        static std::map <std::string, games::instrvector> parsmap;
        static std::map <std::string, unsigned int>       varimap;
        static std::map <std::string, void*> membmap;
        static std::map <std::string, void*> vectmap;
    };
};

#endif
