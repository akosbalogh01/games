#include "mapman.hpp"

std::map <std::string, unsigned int> games::mapman::varimap;

void games::mapman::init_varimap() {
    varimap["PLACEHOLDER"] = 0;
}
