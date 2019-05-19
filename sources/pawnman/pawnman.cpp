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

bool games::pawnman::movePawn(uint index, const games::vec2d& param) {
    return pawn_vector[index].get()->move(param);
}

void games::pawnman::enableMoves(uint pawnindex) {
    if (pawnindex < pawn_vector.size()) {
        pawn_vector[pawnindex].get()->enableMoves();
    }
}

void games::pawnman::enableMove(uint pawnindex, uint moveindex) {
    if (pawnindex < pawn_vector.size()) {
        pawn_vector[pawnindex].get()->enableMove(moveindex);
    }
}

void games::pawnman::enableMove(uint pawnindex, const games::vec2d& vec) {
    if (pawnindex < pawn_vector.size()) {
        pawn_vector[pawnindex].get()->enableMove(vec);
    }
}

void games::pawnman::disableMoves(uint pawnindex) {
    if (pawnindex < pawn_vector.size()) {
        pawn_vector[pawnindex].get()->disableMoves();
    }
}

void games::pawnman::disableMove(uint pawnindex, uint moveindex) {
    if (pawnindex < pawn_vector.size()) {
        pawn_vector[pawnindex].get()->disableMove(moveindex);
    }
}

void games::pawnman::disableMove(uint pawnindex, const games::vec2d& vec) {
    if (pawnindex < pawn_vector.size()) {
        pawn_vector[pawnindex].get()->disableMove(vec);
    }
}
