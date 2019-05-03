#include "statfunc.hpp"
#include "mapman.hpp"
#include "instrvector.hpp"

std::map <std::string, games::instrvector> games::mapman::parsmap;

void games::mapman::init_parsmap() {
    parsmap["DEFINE_VAR"] = games::instrvector(games::instruction(nullptr, std::function <bool (void*, std::string, void*)> (games::statfunc::parsedefvar)));
    parsmap["DEFINE_FUN"] = games::instrvector(games::instruction(nullptr, std::function <bool (void*, std::string, void*)> (games::statfunc::parsedeffun)));
}
