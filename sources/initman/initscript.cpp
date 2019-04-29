#include <regex>
#include <fstream>
#include <iostream>
#include "initman.hpp"
#include "mapman.hpp"

/*
SETPAWNPOS[];
CREATEPAWN[];
*/

bool games::initman::loadInitScript(const std::string& filepath) {
    std::cout << "[i] Generating init script from " << filepath << ':' << std::endl;
    std::ifstream initscript(filepath);
    std::string   current_line;
    std::smatch   match;

    while (std::getline(initscript, current_line)) {
        if (current_line.front() == '#') continue;
        else {
            if (std::regex_match(current_line, match, std::regex("(.*?)(\\[)(.*?)"))) {
                std::cout << current_line << std::endl;
                auto new_thing = games::mapman::funcmap[match[1]];
            }
        }
    }

    return true;
}
