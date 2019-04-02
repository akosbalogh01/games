#ifndef GAMES_INTERPRETERS
#define GAMES_INTERPRETERS
#include <string>

namespace interpreters {
    bool quit(const std::string& param) {return (param == "quit" || param == "exit");}
};

#endif
