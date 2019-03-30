#include <functional>
#include <string>
#include "command.hpp"

const bool games::command::interpret(const std::string& input) {
    return var_interpreter(input);
}

void games::command::execute() {
    var_target();
}
