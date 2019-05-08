#ifndef GAMES_BRANCH
#define GAMES_BRANCH
#include <vector>
#include <string>
#include <memory>
#include "statfunc.hpp"
#include "interfaces.hpp"

namespace games {
    class branch: public interfaces::executable {
    private:
        std::vector <std::shared_ptr <interfaces::executable>>  branches;
        std::vector <std::shared_ptr <interfaces::conditional>> evals;

    public:
        friend bool games::statfunc::branch::bif(void*, const std::string&, void*);
        friend bool games::statfunc::branch::belif(void*, const std::string&, void*);
        friend bool games::statfunc::branch::belse(void*, const std::string&, void*);

        bool build(const std::string&);
        void execute();
    };
};

#endif // GAMES_BRANCH
