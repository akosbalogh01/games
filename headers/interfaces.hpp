#ifndef GAMES_INTERFACE
#define GAMES_INTERFACE
#include <string>

namespace interfaces {
    class executable {
        public:
            virtual void execute() = 0;
    };

    class triggerable {
        public:
            virtual bool trigger(const std::string&) = 0;
            virtual void execute() = 0;
    };

    class tile {
        public:
            virtual void render() const = 0;
    };

    class conditional {
        public:
            virtual void evaluate() = 0;
    };
};

#endif
