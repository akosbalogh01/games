#ifndef GAMES_CONDITION_VECTOR
#define GAMES_CONDITION_VECTOR
#include <string>
#include <vector>
#include <memory>
#include "interfaces.hpp"

typedef std::vector <std::shared_ptr <interfaces::conditional>> condvect;

namespace games {
    class condvec: public interfaces::conditional {
    private:
        condvect vec;

    public:
        bool build(const std::string&);

        bool evaluate();
    };
};

#endif // GAMES_CONDITION_VECTOR
