#ifndef GAMES_ARGVECTOR_COMMAND
#define GAMES_ARGVECTOR_COMMAND

#include <iostream>
#include <memory>
#include <functional>
#include <regex>
#include "argvectoridx.hpp"
#include "command.hpp"

namespace games {
    template <class exec_target, class exec_argument>
    class argvcommand: public command <exec_target, exec_argument> {
    private:
        games::argvindex                cmd_target_argument_index;

    public:
        argvcommand(const std::function <void (exec_target*, const exec_argument&)> target_func, const games::argvindex& argv):
        games::command <exec_target, exec_argument> (target_func), cmd_target_argument_index(argv) {}

        void execute() {
            std::cout << "calling argvcmd with base " << command <exec_target, exec_argument>::cmd_argument_vector.at(0) << " with argument " << (command <exec_target, exec_argument>::cmd_argument_vector.at(cmd_target_argument_index.data())) << std::endl;
            command <exec_target, exec_argument>::cmd_target_function(command <exec_target, exec_argument>::cmd_target.get(), command <exec_target, exec_argument>::cmd_argument_vector.at(cmd_target_argument_index.data()));
        }
    };
};

#endif
