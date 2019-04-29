#include <regex>
#include <memory>
#include <string>
#include "pawn.hpp"
#include "pawnman.hpp"

bool games::pawnman::createPawn(unsigned int owner_id, unsigned int type_id) {
    std::shared_ptr <games::pawn> new_pawn = std::make_shared <games::pawn> (pawn_index);
    if (new_pawn != nullptr) {
        new_pawn.get()->setOwnerID(owner_id);
        new_pawn.get()->setType(type_id);
        new_pawn.get()->setCharacter(getChar(type_id));
        pawn_index++;
        pawn_vector.push_back(new_pawn);
        return true;
    }

    return false;
}
