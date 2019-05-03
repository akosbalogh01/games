#include "mapman.hpp"

std::map <std::string, unsigned int> games::mapman::varimap;

void games::mapman::init_varimap() {
    varimap["MOVES"] = 0;
}
