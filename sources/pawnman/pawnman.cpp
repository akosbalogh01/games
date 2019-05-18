#include "pawnman.hpp"

unsigned int games::pawnman::pawn_index = 0;

char games::pawnman::getChar(const unsigned int index) const {
    return pawn_charmap.get()->at(index);
}

void games::pawnman::setCharmap(const charvec& charvecp) {
    pawn_charmap = charvecp;
}

const pawnvec& games::pawnman::get() {
    return pawn_vector;
}

unsigned int games::pawnman::getPawnType(unsigned int index) {
    return pawn_vector[index].get()->getType();
}

int games::pawnman::getPawnIndex(const games::vec2d& param) {
    for (uint i = 0; i < pawn_vector.size(); i++) {
        if (pawn_vector[i].get()->getPos() == param) {
            return pawn_vector[i].get()->id();
        }
    }

    return -1;
}

void games::pawnman::defineMove(uint index, const games::vec2d& param) {
    pawn_vector[index].get()->pushMove(param);
}

void games::pawnman::enableMove(uint pawnindex, uint moveindex) {
    pawn_vector[pawnindex].get()->setMoveEnabled(moveindex, true);
}

void games::pawnman::disableMove(uint pawnindex, uint moveindex) {
    pawn_vector[pawnindex].get()->setMoveEnabled(moveindex, false);
}

bool games::pawnman::movePawn(uint index, const games::vec2d& param) {
    return pawn_vector[index].get()->move(param);
}
