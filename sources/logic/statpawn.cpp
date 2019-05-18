#include <regex>
#include <iostream>
#include "statfunc.hpp"
#include "vector2d.hpp"
#include "pawnman.hpp"

inline games::vec2d* buildvec(const std::string input) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(VEC2D\\[)(\\d+)(,\\s+)(\\d+)(\\])"))) {
        return new games::vec2d(std::stoi(match[2]), std::stoi(match[4]));;
    }
    else {
        std::cout << "[e] Failed to create 2D vector from " << input << std::endl;
    }

    return NULL;
}

bool games::statfunc::moves::defmove(void* object, const std::string& input, void* unused) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(DEFINEMOVE\\[)(\\d+)(,\\s+)(.?*)(\\];)"))) {
        if (games::vec2d* new_vector = buildvec(match[4])) {
            games::pawnman* target = (games::pawnman*) object;
            target->defineMove(std::stoi(match[2]), *new_vector);
            std::cout << "[i] Defined move " << match[4] << " on pawn[" << match[2] << "]" << std::endl;
        }
        else {
            std::cout << "[e] Failed to define vector from " << input << std::endl;
        }
    }
    else {
        std::cout << "[e] Failed to define move from " << input << std::endl;
    }

    return false;
}

bool games::statfunc::moves::dismove(void* object, const std::string& input, void* unused) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(DISABLEMOVE\\[)(\\d+)(,\\s+)(\\d+)(\\];)"))) {
        games::pawnman* target = (games::pawnman*) object;
        target->disableMove(std::stoi(match[2]), std::stoi(match[4]));
        std::cout << "[i] Disabled move[" << match[4] << "] on pawn[" << match[2] << "]" << std::endl;
    }
    else {
        std::cout << "[e] Failed to disable move from " << input << std::endl;
    }

    return false;
}

bool games::statfunc::moves::enamove(void* object, const std::string& input, void* unused) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(ENABLEMOVE\\[)(\\d+)(,\\s+)(\\d+)(\\];)"))) {
        games::pawnman* target = (games::pawnman*) object;
        target->enableMove(std::stoi(match[2]), std::stoi(match[4]));
        std::cout << "[i] Enabled move[" << match[4] << "] on pawn[" << match[2] << "]" << std::endl;
    }
    else {
        std::cout << "[e] Failed to enable move from " << input << std::endl;
    }

    return false;
}
