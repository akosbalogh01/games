#include "vector2d.hpp"
#include "pawn.hpp"

bool games::pawn::valid_move(const games::vec2d& param) {
    for (auto index: pawn_moveset) {
        if (index.x() == param.x() && index.y() == param.y()) {
            return true;
        }
    }

    return false;
}

void games::pawn::pushMove(const games::vec2d& param) {
    pawn_moveset.push_back(param);
}

void games::pawn::popMove(const int index) {
    pawn_moveset.erase(pawn_moveset.begin() + index);
}

void games::pawn::setOwnerID(const unsigned int id) {
    owner_id = id;
}

void games::pawn::setCharacter(const char param) {
    pawn_char = param;
}

void games::pawn::setType(const unsigned int param) {
    pawn_type = param;
}

void games::pawn::setPos(const games::vec2d& param) {
    pawn_pos.setX(param.x());
    pawn_pos.setY(param.y());
}

unsigned int games::pawn::pos1D() const {
    return pawn_pos.y() * 8 + pawn_pos.x();
}




