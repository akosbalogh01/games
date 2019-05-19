#include "pawn.hpp"

bool games::pawn::move(const games::vec2d& param) {
    for (auto index: pawn_moveset) {
        if (index.getVect() == param && index.enabled()) {
            pawn_pos.setX(pawn_pos.x() + param.x());
            pawn_pos.setY(pawn_pos.y() + param.y());
            return true;
        }
    }

    return false;
}

void games::pawn::setMoveEnabled(unsigned int index, const bool param) {
    pawn_moveset[index].setEnabled(param);
}

void games::pawn::pushMove(const games::vec2d& param) {
    pawn_moveset.push_back(games::move(param));
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

void games::pawn::enableMoves() {
    for (auto& index: pawn_moveset) {
        index.setEnabled(true);
    }
}

void games::pawn::enableMove(unsigned int index) {
    if (index < pawn_moveset.size()) {
        pawn_moveset[index].setEnabled(true);
    }
}

void games::pawn::enableMove(const games::vec2d& vec) {
    for (auto& index: pawn_moveset) {
        if (index.getVect() == vec) {
            index.setEnabled(true);
        }
    }
}

void games::pawn::disableMoves() {
    for (auto& index: pawn_moveset) {
        index.setEnabled(false);
    }
}

void games::pawn::disableMove(unsigned int index) {
    if (index < pawn_moveset.size()) {
        pawn_moveset[index].setEnabled(false);
    }
}

void games::pawn::disableMove(const games::vec2d& vec) {
    for (auto& index: pawn_moveset) {
        if (index.getVect() == vec) {
            index.setEnabled(false);
        }
    }
}
