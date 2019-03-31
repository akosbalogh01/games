#ifndef GAMES_COMMAND
#define GAMES_COMMAND

#include <functional>
#include <regex>
#include "interfaces.hpp"
#include "logic.hpp"

namespace games {
    template <class exec_target, class exec_argument>
    class command: public interfaces::triggerable {
    private:
        exec_argument                                               cmd_target_argument;
        std::shared_ptr <exec_target>                               cmd_target;
        std::function   <void (exec_target*, const exec_argument&)> cmd_target_function;
        std::vector     <std::string>                               cmd_regexp_patterns;

    public:
        command(const std::function <void (exec_target*, const exec_argument&)> target_func):
        cmd_target_function(target_func) {}

        virtual bool trigger(const std::string& input) {
            for (auto const index: cmd_regexp_patterns) {
                if (std::regex_match(input, std::regex(index))) return true;
            }

            return false;
        }

        virtual void execute() {cmd_target_function(cmd_target.get(), cmd_target_argument);}

        void setTarget(const std::shared_ptr <exec_target>& param) {cmd_target = param;}
        void setArgument(const exec_argument& param) {cmd_target_argument = param;}
        void pushRegexpPattern(const std::string& param) {cmd_regexp_patterns.push_back(param);}
    };
};

#endif // GAMES_COMMAND
