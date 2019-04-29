#ifndef GAMES_INSTRUCTION
#define GAMES_INSTRUCTION
#include <functional>
#include <string>
#include "interfaces.hpp"

namespace games {
    class instruction: public interfaces::executable {
    private:
        void* object_;
        std::function <bool (void*, std::string)> target_;
        std::string args_;

    public:
        instruction() {}
        instruction(void* p1, const std::function <bool (void*, std::string)>& p2): object_(p1), target_(p2) {}

        void setObject(void*);
        void setArgs(const std::string&);
        void bind(const std::function <bool (void*, std::string)>&);

        void* object();
        const std::string args();
        const std::function <bool (void*, std::string)> get();

        void execute();
    };
};

#endif
