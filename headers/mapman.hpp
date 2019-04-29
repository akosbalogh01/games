#ifndef GAMES_MAPMAN
#define GAMES_MAPMAN
#include <string>
#include <map>

namespace games {
    class mapman {
    private:
        void*   core;
        void    init_funcmap();
        void    init_membmap();
        void    init_vectmap();

    public:
        mapman(void* param): core(param) {
            init_vectmap();
            init_membmap();
            init_funcmap();
        }

        static std::map <std::string, void*>    funcmap;
        static std::map <std::string, void*>    membmap;
        static std::map <std::string, void*>    vectmap;
    };
};

#endif
