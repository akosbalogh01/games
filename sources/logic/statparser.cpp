#include "mapman.hpp"
#include "statfunc.hpp"

bool games::statfunc::parsedefvar(void* unused, const std::string& key, void* unused2) {
    games::mapman::varimap[key] = 0;
    return true;
}

bool games::statfunc::parsedeffun(void* unused, const std::string& key, void* unused2) {
    games::mapman::funcmap[key] = games::instrvector();
    return true;
}
