#ifndef GAMES_INSTRVECTOR
#define GAMES_INSTRVECTOR
#include <memory>
#include <vector>
#include "interfaces.hpp"
#include "instruction.hpp"

typedef std::vector <std::shared_ptr <interfaces::executable>> insvect;

namespace games {
    class instrvector: public interfaces::executable {
    private:
        insvect data;

    public:
        instrvector();
        instrvector(const games::instruction);
        void add(const std::shared_ptr <interfaces::executable>&);

        void pop(unsigned int);
        void execute();
        unsigned int size();

        /*
        const instrvector operator= (const instrvector& p) {
            instrvector temp;
            temp.data = p.data;
            return temp;
        }
        */
    };
};

#endif // GAMES_INSTRVECTOR
