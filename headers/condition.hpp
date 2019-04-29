#ifndef GAMES_CONDITION
#define GAMES_CONDITION
#include <functional>
#include <string>
#include "interfaces.hpp"

namespace games {
    template <class compare_type>
    class condition: public interfaces::conditional {
        private:
            const std::function <bool (compare_type, compare_type)> cond_comp;
            const std::string cond_key;
            const std::string cond_args;

        public:
        condition(const std::function <bool (compare_type, compare_type)>& p1, const std::string& p2, const std::string& p3):
            cond_comp(p1), cond_key(p2), cond_args(p3) {}

    };
};

#endif // GAMES_CONDITION
