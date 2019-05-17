#include <iostream>
#include <string>
#include "logic.hpp"
#include "mapman.hpp"

void games::logic::processInput() {
    std::string input, keyword;
    std::cout << std::endl << std::endl << ">> ";
    std::getline(std::cin, input);
    keyword = input.substr(0, input.find(' '));

    auto search = games::mapman::cmdmap.find(keyword);
    if (search != games::mapman::cmdmap.end()) {
        if (games::mapman::cmdmap[keyword].evaluate(input)) {
            games::mapman::cmdmap[keyword].execute(input);
        }
    }
    else {
        std::cout << "Invalid command." << std::endl;
    }
}
