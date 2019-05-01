#ifndef GAMES_INSTRVECTOR
#define GAMES_INSTRVECTOR
#include <memory>
#include <vector>
#include "interfaces.hpp"
#include "instruction.hpp"

typedef std::vector <std::shared_ptr <games::instruction>> insvect;

namespace games {
    class instrvector: public interfaces::executable {
    private:
        insvect data;

    public:
        void add(const std::shared_ptr <games::instruction>&);

        void pop(unsigned int);
        void execute();
    };
};

#endif // GAMES_INSTRVECTOR
