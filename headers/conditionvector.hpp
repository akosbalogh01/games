#ifndef GAMES_CONDITION_VECTOR
#define GAMES_CONDITION_VECTOR
#include <string>
#include <vector>
#include "interfaces.hpp"
#include "condition.hpp"

namespace games {
    class condvector: public interfaces::conditional {
    private:
        std::vector <interfaces::conditional*> vec;

    public:
        bool build(const std::string&);

        bool evaluate() const;
    };
};

#endif // GAMES_CONDITION_VECTOR
