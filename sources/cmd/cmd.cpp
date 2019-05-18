#include <regex>
#include <memory>
#include "command.hpp"
#include "interfaces.hpp"

bool games::command::evaluate(const std::string& input) const {
    if (patterns.size() == 0) return false;
    else {
        for (const auto& index: patterns) {
            if (std::regex_match(input, std::regex(index))) {
                return true;
            }
        }
    }

    return false;
}

void games::command::execute(const std::string& input) {
    std::string backup = instr.args();
    instr.setArgs(input);
    instr.execute();
    instr.setArgs(backup);
}

void games::command::addPattern(const std::string& param) {
    patterns.push_back(param);
}
