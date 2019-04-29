#ifndef GAMES_INITMAN
#define GAMES_INITMAN
#include <vector>
#include <string>
//#include "instrvect.hpp"

namespace games {
    class initman {
    private:
        std::vector <std::string> vinitscript;

    public:
        bool loadInitScript(const std::string&);

    };
};

#endif // GAMES_INITMAN
