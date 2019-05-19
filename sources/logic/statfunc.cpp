#include <regex>
#include <iostream>
#include "statfunc.hpp"
#include "logic.hpp"
#include "pawnman.hpp"
#include "vector2d.hpp"

bool games::statfunc::createpawn(void* target, const std::string& input, void* unused) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(CREATEPAWN\\[)(\\d+)(,\\s+)(\\d+)(\\];)"))) {
        games::pawnman* origin = (games::pawnman*) target;
        if (origin->createPawn(std::stoi(match[2]), std::stoi(match[4]))) {
            std::cout << "[i] Created pawn[" << games::pawnman::pawn_index - 1 << "]" << std::endl;
            return true;
        }
        else {
            std::cout << "[e] Failed to create pawn [" << games::pawnman::pawn_index << "]" << std::endl;
        }
    }
    else {
        std::cout << "[e] Unmatched regular expression to create pawn " << input << std::endl;
    }

    return false;
}

bool games::statfunc::setpawnpos(void* target, const std::string& input, void* unused) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(SETPAWNPOS\\[)(\\d+)(,\\s+\\[)(\\d+)(,\\s+)(\\d+)(\\]\\];)"))) {
        games::pawnman* origin = (games::pawnman*) target;
        if (origin->setPawnPos(std::stoi(match[2]), games::vec2d(std::stoi(match[4]), std::stoi(match[6])))) {
            std::cout << "[i] Modified pawn[" << match[2] << "] position" << std::endl;
            return true;
        }
        else {
            std::cout << "[e] Failed to modify pawn[" << match[2] << "] position" << std::endl;
        }
    }
    else {
        std::cout << "[e] Unmatched regular expression to set pawn position " << input << std::endl;
    }

    return false;
}

bool games::statfunc::returnconst(void* unused, const std::string& input, void* result) {
    *(unsigned int*) result = std::stoi(input);
    return true;
}

bool games::statfunc::assignvalue(void* unused, const std::string& input, void* result) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(ASSIGN\\[)(.*?)(,\\s+)(\\d+)(\\];)"))) {
        auto search = games::mapman::varimap.find(match[2]);
        if (search != games::mapman::varimap.end()) {
            games::mapman::varimap[match[2]] = std::stoi(match[4]);
            return true;
        }
        else {
            std::cout << "[e] Error assigning value from line: " << input << std::endl;
            std::cout << "[e] Undefined variable '" << match[2] << "'" << std::endl;
        }
    }
    else if (std::regex_match(input, match, std::regex("(ASSIGN\\[)(.*?)(,\\s+)(.*?)(\\];)"))) {
        auto search1 = games::mapman::varimap.find(match[2]);
        auto search2 = games::mapman::varimap.find(match[4]);
        if (search1 != games::mapman::varimap.end() && search2 != games::mapman::varimap.end()) {
            games::mapman::varimap[match[2]] = games::mapman::varimap[match[4]];
            return true;
        }
        else {
            std::cout << "[e] Error assigning value from line: " << input << std::endl;
            std::cout << "[e] Undefined variable '" << match[2] << "' or '" << match[4] << "'" << std::endl;
        }
    }

    return false;
}

bool games::statfunc::value(void* unused, const std::string& input, void* result) {
    auto search = games::mapman::varimap.find(input);
    if (search != games::mapman::varimap.end()) {
        *(unsigned int*) result = games::mapman::varimap[input];
        return true;
    }

    return false;
}


