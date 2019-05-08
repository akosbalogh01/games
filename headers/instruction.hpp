#ifndef GAMES_INSTRUCTION
#define GAMES_INSTRUCTION
#include <string>
#include <memory>
#include <iostream>
#include <functional>
#include "interfaces.hpp"

namespace games {
    class instruction: public interfaces::executable {
    private:
        void* vresult;
        void* vobject;
        std::function <bool (void*, std::string, void*)> vtarget;
        std::string vargs;

    public:
        instruction() {}
        instruction(const games::instruction&);
        instruction(void* p1, const std::function <bool (void*, std::string, void*)>& p2): vobject(p1), vtarget(p2) {}

        void setObject(void*);
        void setArgs(const std::string&);
        void setResult(void*);
        void bind(const std::function <bool (void*, std::string, void*)>&);

        void* object();
        const std::string args();
        void* result();
        const std::function <bool (void*, std::string, void*)> get();

        void execute();
    };
};

#endif
