#include <iostream>
#include <string>
#include "logic.hpp"

void games::logic::processInput() {

    for (const auto& cmd: logic_commands) {
        if (cmd.interpret(logic_inputstring)) {
            cmd.execute();
            return;
        }
    }

    std::cout << "Invalid command." << std::endl;

    return;
}
