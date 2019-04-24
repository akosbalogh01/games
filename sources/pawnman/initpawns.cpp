#include <fstream>
#include <iostream>
#include <regex>
#include "pawnman.hpp"

void games::pawnman::initPawns(const std::string& filepath) {
    std::cout << "[i] Initialising pawns from " << filepath << std::endl;
    std::ifstream initpawns(filepath);
    std::string   current_line;
    std::smatch   match;

    while (std::getline(initpawns, current_line)) {
        if (std::regex_match(current_line, match, std::regex("(SETPAWNPOS\\[)(\\d+)(,\\s+\\[)(\\d+)(,\\s+)(\\d+)(\\]\\];)"))) {
            setPawnPos(std::stoi(match[2]), games::vec2d(std::stoi(match[4]), std::stoi(match[6])));
        }
    }
}
