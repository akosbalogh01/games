#include <string>
#include "mapman.hpp"
#include "logic.hpp"

std::map <std::string, const void*> games::mapman::vectmap;

void games::mapman::init_vectmap() {
    games::logic* origin = (games::logic*) core;
    vectmap["PAWNS"] = &(origin->logic_pawnman.get());
}
