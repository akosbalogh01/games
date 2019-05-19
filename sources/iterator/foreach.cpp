#include "mapman.hpp"
#include "pawnman.hpp"
#include "foreach.hpp"

void games::foreach::execute() {
    if (vtarget.empty()) return;
    else {
        unsigned int i = 0;
        pawnvec* target = (pawnvec*) games::mapman::vectmap["PAWNS"];
        for (i = 0; i < target->size(); i++) {
            vinstr.get()->execute();
            games::mapman::varimap[viter] = i;
        }
    }
}

void games::foreach::setIterator(const std::string& param) {
    viter = param;
}

std::string games::foreach::iter() const {
    return viter;
}

void games::foreach::setTarget(const std::string& param) {
    vtarget = param;
}

std::string games::foreach::target() const {
    return vtarget;
}

void games::foreach::bind(const std::shared_ptr <games::instrvector>& param) {
    vinstr = param;
}

const std::shared_ptr <games::instrvector>& games::foreach::get() const {
    return vinstr;
}
