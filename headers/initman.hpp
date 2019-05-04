#ifndef GAMES_INITMAN
#define GAMES_INITMAN
#include <vector>
#include <string>
#include "instrvector.hpp"

namespace games {
    class initman {
    private:
        std::vector <std::string> vinitscript;
        games::instrvector vinstvector;

    public:
        bool loadInitScript(const std::string&);

        void init();
    };
};

#endif // GAMES_INITMAN
