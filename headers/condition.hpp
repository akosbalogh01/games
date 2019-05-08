#ifndef GAMES_CONDITION
#define GAMES_CONDITION
#include <functional>
#include <string>
#include "interfaces.hpp"
#include "instruction.hpp"

namespace games {
    class condition: public interfaces::conditional {
        private:
            std::function <bool (int, int)> cond_comp;
            games::instruction cond_instr1;
            games::instruction cond_instr2;

        public:
            condition(const std::string&);

            bool evaluate();
    };
};

#endif // GAMES_CONDITION
