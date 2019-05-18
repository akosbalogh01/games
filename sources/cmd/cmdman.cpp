#include "cmdman.hpp"

void games::cmdman::process(const std::string& input) {
    std::string keyword = input.substr(0, input.find(' '));

    auto search = cmdmap.find(keyword);
    if (search != cmdmap.end()) {
        if (cmdmap[keyword].evaluate(input)) {
            cmdmap[keyword].execute(input);
        }
    }
    else {
        std::cout << "Invalid command." << std::endl;
    }
}

bool games::cmdman::addcmd(const std::string& input) {


    return false;
}
