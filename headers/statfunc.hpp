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
        bool assignvalue(void*, const std::string&, void*);

        namespace math {
            bool add(void*, const std::string&, void*);
            bool sub(void*, const std::string&, void*);
            bool increment(void*, const std::string&, void*);
            bool decrement(void*, const std::string&, void*);
            bool multiply(void*, const std::string&, void*);
            bool divide(void*, const std::string&, void*);
            bool modulo(void*, const std::string&, void*);
        };
    };
};

#endif
