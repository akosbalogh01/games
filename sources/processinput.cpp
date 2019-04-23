#include <iostream>
#include <string>
#include "logic.hpp"

void games::logic::processInput() {
    std::string input;
    std::cout << std::endl << std::endl << ">> ";
    std::getline(std::cin, input);


    for (auto index: logic_commands) {
        if (index.get()->trigger(input)) {
            index.get()->execute();
            return;
        }
    }


    std::cout << "Invalid command." << std::endl;

    return;
}
