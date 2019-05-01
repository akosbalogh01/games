#include "pawnman.hpp"

bool games::pawnman::setPawnPos(const unsigned int pawnindex, const games::vec2d& pos) {
    for (auto index: pawn_vector) {
        if (index.get()->id() == pawnindex) {
            index.get()->setPos(pos);
            return true;
        }
    }

    return false;
}
