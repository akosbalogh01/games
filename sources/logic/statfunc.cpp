#include <regex>
#include <string>
#include "statfunc.hpp"
#include "logic.hpp"
#include "pawnman.hpp"

bool games::statfunc::createpawn(void* target, const std::string& input) {
    std::smatch match;
    if (std::regex_match(input, match, std::regex("(CREATEPAWN)(\\[)(\\d+)(,\\s+)(\\d+)(\\];)"))) {
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
