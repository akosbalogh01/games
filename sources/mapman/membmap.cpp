#include <string>
#include "mapman.hpp"
#include "logic.hpp"

std::map <std::string, void*> games::mapman::membmap;

void games::mapman::init_membmap() {
    games::logic* origin = (games::logic*) core;

    membmap["LOGIC"]    = origin;
    membmap["PAWNMAN"]  = &origin->logic_pawnman;
    membmap["GRAPHICS"] = &origin->logic_gfx;
}
