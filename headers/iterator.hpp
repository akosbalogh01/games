#ifndef GAMES_ITERATOR
#define GAMES_ITERATOR
#include <string>
#include <vector>
#include "interfaces.hpp"
#include "instrvector.hpp"

namespace games {
    class iteration: public interfaces::executable {
    protected:
        std::string vargs;
        std::shared_ptr <interfaces::executable> vinstv;

    public:
        void setArgs(const std::string&);
        std::string args() const;

        virtual void execute();

        const std::shared_ptr <interfaces::executable>& get();
    };
};

#endif // GAMES_ITERATOR
