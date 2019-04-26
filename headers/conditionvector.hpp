#ifndef GAMES_CONDITION_VECTOR
#define GAMES_CONDITION_VECTOR
#include <vector>
#include "interfaces.hpp"
#include "condition.hpp"

namespace games {
    class conditionvector: public interfaces::conditional {
    private:
        std::vector <interfaces::conditional*> vec;

    public:
        void

        bool evaluate() const;
    };
};

#endif // GAMES_CONDITION_VECTOR
