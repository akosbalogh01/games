#include "pawnman.hpp"

char games::pawnman::getChar(const unsigned int index) const {
    return pawn_charmap.get()->at(index);
}

void games::pawnman::setCharmap(const charvec& charvecp) {
    pawn_charmap = charvecp;
}

const pawnvec& games::pawnman::get() {
    return pawn_vector;
}
