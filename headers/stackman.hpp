#ifndef GAMES_STACKMAN
#define GAMES_STACKMAN
#include <vector>
#include <memory>
#include "branch.hpp"
#include "instrvector.hpp"

namespace games {
    class stackman {
    private:
        void init_insvstack();
        void init_branstack();

    public:
        void init() {
            init_insvstack();
            init_branstack();
        }

        static std::vector <std::shared_ptr <games::instrvector>>   insvstack;
        static std::vector <std::shared_ptr <games::branch>>        branstack;
    };
};

#endif // GAMES_STACKMAN
