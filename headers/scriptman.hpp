#ifndef GAMES_SCRIPTMAN
#define GAMES_SCRIPTMAN
#include <vector>
#include <string>
#include "mapman.hpp"
#include "stackman.hpp"
#include "branch.hpp"
#include "instrvector.hpp"

typedef std::vector <std::string> lexvec;

namespace games {
    class scriptman {
    private:
        static bool parse_label(const std::string&);
        static bool parse_branch(const std::string&);
        static bool parse_instr(void*, const std::string&);
        static bool parse_end(const std::string&);

    public:
        static const lexvec lexer(const std::string&);
        static void parser(const lexvec&);
    };
};

#endif // GAMES_SCRIPTMAN
