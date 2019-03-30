#ifndef GAMES_INTERFACE
#define GAMES_INTERFACE

#include <string>

namespace interfaces {
    class triggerable {
        public:
            virtual const bool interpret(const std::string&) const = 0;
            virtual void execute() const = 0;
    };
};

#endif
