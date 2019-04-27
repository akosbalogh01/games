#include <regex>
#include <memory>
#include <string>
#include "pawnman.hpp"

pPawn games::pawnman::createPawn(const std::string& current_line, unsigned int current_index) {
    std::smatch match;
    if (std::regex_match(current_line, match, std::regex("(CREATEPAWN\\[)(\\d+)(,\\s+)(\\d+)(\\];)"))) {
        std::shared_ptr <games::pawn> new_pawn = std::make_shared <games::pawn> (current_index);
        new_pawn.get()->setOwnerID(std::stoi(match[2]));
        new_pawn.get()->setCharacter(getChar(std::stoi(match[4])));
        new_pawn.get()->setType(std::stoi(match[4]));

        return new_pawn;
    }

    return nullptr;
}
