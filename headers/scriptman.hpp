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
        static const std::shared_ptr <games::instrvector> parse_label(const std::string&);
        static const std::shared_ptr <games::branch>      parse_branch(const std::string&);
        static const std::shared_ptr <games::instruction> parse_instr(void*, const std::string&);
        static void parse_end(const std::string&);

    public:
        static const lexvec lexer(const std::string&);
        static const games::instrvector parser(const lexvec&);
    };
};

#endif // GAMES_SCRIPTMAN
