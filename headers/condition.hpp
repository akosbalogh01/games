#ifndef GAMES_CONDITION
#define GAMES_CONDITION
#include <functional>
#include <string>
#include "interfaces.hpp"
#include "instruction.hpp"

namespace games {
    template <class compare_type>
    class condition: public interfaces::conditional {
        private:
            const std::function <bool (compare_type, compare_type)> cond_comp;
            const games::instruction const_instr1;
            const games::instruction const_instr2;

        public:
        condition(const std::function <bool (compare_type, compare_type)>& p1, const games::instruction& p2, const games::instruction& p3):
            cond_comp(p1), const_instr1(p2), const_instr2(p3) {}

    };
};

#endif // GAMES_CONDITION
