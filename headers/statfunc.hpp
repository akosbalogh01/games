#ifndef GAMES_STATFUNC
#define GAMES_STATFUNC
#include <string>

namespace games {
    namespace statfunc {
        bool parsedefvar(void*, const std::string&, void*);
        bool parsedeffun(void*, const std::string&, void*);
        bool writeconsole(void*, const std::string&, void*);
        bool exit(void*, const std::string&, void*);
        bool call(void*, const std::string&, void*);
        bool start(void*, const std::string&, void*);

        bool createpawn(void*, const std::string&, void*);
        bool setpawnpos(void*, const std::string&, void*);
        bool movepawn(void*, const std::string&, void*);
        bool returnconst(void*, const std::string&, void*);
        bool assignvalue(void*, const std::string&, void*);
        bool value(void*, const std::string&, void*);

        namespace math {
            bool add(void*, const std::string&, void*);
            bool sub(void*, const std::string&, void*);
            bool increment(void*, const std::string&, void*);
            bool decrement(void*, const std::string&, void*);
            bool multiply(void*, const std::string&, void*);
            bool divide(void*, const std::string&, void*);
            bool modulo(void*, const std::string&, void*);
        };

        namespace branch {
            bool bif(void*, const std::string&, void*);
            bool belif(void*, const std::string&, void*);
            bool belse(void*, const std::string&, void*);

            bool btrue(void*, const std::string&, void*);
            bool bfalse(void*, const std::string&, void*);

            bool bcond(void*, const std::string&, void*);
            bool bconv(void*, const std::string&, void*);
            bool foreach(void*, const std::string&, void*);
        };

        namespace moves {
            bool defmove(void*, const std::string&, void*);
            bool dismove(void*, const std::string&, void*);
            bool enamove(void*, const std::string&, void*);
        };

        namespace iter {
            bool foreach(void*, const std::string&, void*);
        };
    };
};

#endif
