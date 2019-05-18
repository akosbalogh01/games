#ifndef GAMES_ITERATOR
#define GAMES_ITERATOR
#include <string>
#include <vector>
#include "interfaces.hpp"
#include "instrvector.hpp"

namespace games {
    class iteration: public interfaces::executable {
    private:
        void* vobj;
        unsigned int viter;
        std::string vargs;
        std::shared_ptr <games::instrvector> vinstv;

    public:
        void setObject(void*);
        void setArgs(const std::string&);

        void* object() const;
        std::string args() const;

        void execute();

        const std::shared_ptr <games::instrvector>& get();
    };
};

#endif // GAMES_ITERATOR
