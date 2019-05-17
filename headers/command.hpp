#ifndef GAMES_COMMAND
#define GAMES_COMMAND
#include <string>
#include <vector>
#include "instrvector.hpp"

typedef std::vector <std::string> patvec;

namespace games {
    class command {
    private:
        patvec patterns;
        games::instruction instr;

    public:
        command() {}
        command(const games::instruction& p1): instr(p1) {}
        command(const std::string& p1, const games::instruction& p2): instr(p2) {
            patterns.push_back(p1);
        }

        bool evaluate(const std::string&) const;
        void execute(const std::string&);

        void addPattern(const std::string&);
    };
};

#endif // GAMES_COMMAND
