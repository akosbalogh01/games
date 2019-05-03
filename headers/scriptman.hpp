#ifndef GAMES_SCRIPTMAN
#define GAMES_SCRIPTMAN
#include <vector>
#include <string>
#include "instrvector.hpp"

typedef std::vector <std::string> lexvec;

namespace games {
    class scriptman {
    public:
        static const lexvec lexer(const std::string&);
        static const games::instrvector parser(const lexvec&);
    };
};

#endif // GAMES_SCRIPTMAN
