#ifndef GAMES_INITMAN
#define GAMES_INITMAN
#include <vector>
#include <string>
#include "instrvector.hpp"

namespace games {
    class initman {
    private:
        std::vector <std::string> vinitscript;
        std::vector <std::string> vmainscript;

    public:
        bool loadInitScript(const std::string&);
        bool loadMainScript(const std::string&);

        void init();
        void main();
    };
};

#endif // GAMES_INITMAN
