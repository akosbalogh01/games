#ifndef GAMES_ITERATOR
#define GAMES_ITERATOR
#include <string>
#include <vector>
#include "interfaces.hpp"
#include "instrvector.hpp"

namespace games {
    class iteration: public interfaces::executable {
    protected:
        std::string vtarget;

    public:
        virtual void setTarget(const std::string&);
        virtual std::string target() const;

        virtual void execute();
    };
};

#endif // GAMES_ITERATOR
