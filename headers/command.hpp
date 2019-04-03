#ifndef GAMES_COMMAND
#define GAMES_COMMAND

#include <iostream>
#include <memory>
#include <functional>
#include <regex>
#include "interfaces.hpp"

namespace games {
    template <class exec_target, class exec_argument>
    class command: public interfaces::triggerable {
    protected:
        exec_argument                                               cmd_target_argument;
        std::shared_ptr <exec_target>                               cmd_target;
        std::function   <void (exec_target*, const exec_argument&)> cmd_target_function;
        std::vector     <std::string>                               cmd_regexp_patterns;
        std::vector     <std::string>                               cmd_argument_vector;

    public:
        command(const std::function <void (exec_target*, const exec_argument&)> target_func):
        cmd_target_function(target_func) {}

        virtual bool trigger(const std::string& input) {
            for (auto const index: cmd_regexp_patterns) {
                if (std::regex_match(input, std::regex(index))) {
                    tokenise(input);
                    return true;
                }
            }

            return false;
        }

        virtual void execute() {cmd_target_function(cmd_target.get(), cmd_target_argument);}
        virtual void tokenise(std::string source) {
            std::istringstream sstream(source);
            std::string new_token;

            while (std::getline(sstream, new_token, ' ')) {
                std::cout << new_token << std::endl;
                cmd_argument_vector.push_back(new_token);
            }
        }

        void setTarget(const std::shared_ptr <exec_target>& param) {cmd_target = param;}
        void setArgument(const exec_argument& param) {cmd_target_argument = param;}
        void pushRegexpPattern(const std::string& param) {cmd_regexp_patterns.push_back(param);}
    };
};

#endif // GAMES_COMMAND
