#ifndef GAMES_ITERATOR
#define GAMES_ITERATOR
#include <string>
#include <vector>
#include "interfaces.hpp"
#include "instrvector.hpp"

namespace games {
    class iteration: public interfaces::executable {
    protected:
        std::shared_ptr <games::instrvector> vinstr;

    public:
        virtual void execute();

        virtual void bind(const std::shared_ptr <games::instrvector>&);
        virtual const std::shared_ptr <games::instrvector>& get() const;
    };
};

#endif // GAMES_ITERATOR
