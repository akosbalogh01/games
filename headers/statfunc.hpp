#ifndef GAMES_STATFUNC
#define GAMES_STATFUNC
#include <string>

namespace games {
    namespace statfunc {
        bool parsedefvar(void*, const std::string&, void*);
        bool parsedeffun(void*, const std::string&, void*);

        bool createpawn(void*, const std::string&, void*);
        bool setpawnpos(void*, const std::string&, void*);
        bool returnconst(void*, const std::string&, void*);
    };
};

#endif
