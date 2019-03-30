#ifndef GAMES_COMMAND
#define GAMES_COMMAND

#include <functional>
#include "interfaces.hpp"

namespace games {
    class command: public interfaces::triggerable {
        private:
            const std::function <bool (const std::string&)> var_interpreter;
            const std::function <void ()>                   var_target;

        public:
            command(const std::function <bool (const std::string&)>& interpreter,
                    const std::function <void ()>& target): var_interpreter(interpreter), var_target(target) {}

            const bool interpret(const std::string&);
            void execute();
    };
};

#endif // GAMES_COMMAND
